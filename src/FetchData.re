type model = {
  id: int,
  name: string,
};

type data = {
  models: list(model)
}

type state =
  | Loading
  | Failure
  | Success(data);

type action =
  | LoadData
  | DataLoaded(data)
  | LoadDataFailed;

module Decode = {
  let decodeModel = json =>{
    Json.Decode.{
      id: json |> field("id", int),
      name: json |> field("name", string),
    };
  }
  let decodeData = json =>{
    Json.Decode.{
      models: json |> field("models", list(decodeModel)),
    };
  }
};


let fetchData = () => {
  let url = "http://api.lumpen.agency/data.json";
  Js.Promise.(
      Fetch.fetch(url)
      |> then_(Fetch.Response.json)
      |> then_(json => json |> Decode.decodeData |> (data => Some(data) |> resolve))
      |> catch(_err => resolve(None))
  );
}

let component = ReasonReact.reducerComponent("FetchComponent");

let make = _children => {
  ...component,
  initialState: () => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | LoadData =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        (
          self => Js.Promise.(
            fetchData()
            |> then_(result =>
              switch (result) {
                | Some(data) => resolve(self.send(DataLoaded(data)))
                | None => resolve(self.send(LoadDataFailed))
              }
            )
            |> ignore
          )
        ),
      )
    | DataLoaded(data) => ReasonReact.Update(Success(data))
    | LoadDataFailed => ReasonReact.Update(Failure)
  },
  didMount: (self) => {
    self.send(LoadData)
  },
  render: self =>
    switch (self.state) {
    | Loading => <div> (ReasonReact.string("Loading...")) </div>
    | Failure => <div> (ReasonReact.string("Something went wrong!")) </div>
    | Success(data) =>
      <div>
        <h2> (ReasonReact.string("Models")) </h2>
        <ul>
          (
            data.models
            |> List.map(model =>
                 <li key=(string_of_int(model.id))>
                   (ReasonReact.string(model.name))
                 </li>
               )
            |> Array.of_list
            |> ReasonReact.array
          )
        </ul>
      </div>
    },
};
