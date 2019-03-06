type data = {
  models: list(DataTypes.model),
  cities: list(DataTypes.city)
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
  let decodeModel = json => {
    Json.Decode.{
      DataTypes.id: json |> field("id", int),
      name: json |> field("name", string),
      city: json |> field("city", string),
      position: json |> field("position", int),
    };
  };
  let decodeCity = json => {
    Json.Decode.{
      DataTypes.id: json |> field("id", int),
      name: json |> field("name", string),
      position: json |> field("position", int),
    };
  };
  let decodeData = json => {
    Json.Decode.{
      models: json |> field("models", list(decodeModel)),
      cities: json |> field("cities", list(decodeCity)),
    };
  };
};

let fetchData = () => {
  let url = "http://api.lumpen.agency/data.json";
  Js.Promise.(
    Fetch.fetch(url)
    |> then_(Fetch.Response.json)
    |> then_(json =>
         json
         |> Decode.decodeData
         |> (decodedData => Some(decodedData) |> resolve)
       )
    |> catch(_err => resolve(None))
  );
};

let component = ReasonReact.reducerComponent("DataFetcher");

let make = _children => {
  ...component,
  initialState: () => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | LoadData =>
      ReasonReact.UpdateWithSideEffects(
        Loading,
        self =>
          Js.Promise.(
            fetchData()
            |> then_(result =>
                 switch (result) {
                 | Some(data) => resolve(self.send(DataLoaded(data)))
                 | None => resolve(self.send(LoadDataFailed))
                 }
               )
            |> ignore
          ),
      )
    | DataLoaded(data) => ReasonReact.Update(Success(data))
    | LoadDataFailed => ReasonReact.Update(Failure)
    },
  didMount: self => {
    self.send(LoadData);
  },
  render: self =>
    switch (self.state) {
    | Loading => <div> {ReasonReact.string("Loading...")} </div>
    | Failure => <div> {ReasonReact.string("Something went wrong!")} </div>
    | Success(data) => <App models=data.models />
    },
};
