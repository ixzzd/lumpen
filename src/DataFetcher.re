open Utils;
open DataTypes;

type data = {
  models,
  cities,
};

type state =
  | Loading
  | Failure
  | Success(data);

type action =
  | LoadData
  | DataLoaded(data)
  | LoadDataFailed;

module Decode = {
  let decodeModelImage = json => {
    Json.Decode.{
      normal: json |> field("normal", string),
      og: json |> field("og", string),
    };
  };
  let decodeModel = json => {
    Json.Decode.{
      id: json |> field("id", int),
      name: json |> field("name", string),
      city: json |> field("city", string),
      avatar: json |> field("avatar", decodeModelImage),
    };
  };
  let decodeCity = json => {
    Json.Decode.{
      id: json |> field("id", int),
      name: json |> field("name", string),
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
    |> catch(_err => {
         Js.log(_err);
         resolve(None);
       })
  );
};

let component = RR.reducerComponent(__MODULE__);

let make = _children => {
  ...component,
  initialState: () => Loading,
  reducer: (action, _state) =>
    switch (action) {
    | LoadData =>
      RR.UpdateWithSideEffects(
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
    | DataLoaded(data) => RR.Update(Success(data))
    | LoadDataFailed => RR.Update(Failure)
    },
  didMount: self => {
    self.send(LoadData);
  },
  render: self =>
    switch (self.state) {
    | Loading => <div> {s("Loading...")} </div>
    | Failure => <div> {s("Something went wrong!")} </div>
    | Success(data) => <App models={data.models} cities={data.cities} />
    },
};
