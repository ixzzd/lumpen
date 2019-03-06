type route =
  | ModelRoute(string)
  | ModelsGridRoute(string)
  | ContactRoute
  | NotFound

type state = {route};

type action =
  | ChangeRoute(route);

let reducer = (action, _state) =>
  switch (action) {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let mapUrlToRoute = (url: ReasonReact.Router.url) =>
  switch (url.path) {
  | ["contacts"] => ContactRoute
  | [cityName] => ModelsGridRoute(cityName)
  | [_, modelName] => ModelRoute(modelName)
  | _ => NotFound
  };

let component = ReasonReact.reducerComponent("App");

let make = (~models: DataTypes.models, ~cities: DataTypes.cities, _children) => {
  ...component,
  reducer,
  initialState: () => {route: ModelsGridRoute("moscow")},
  didMount: self => {
    let watchId =
      ReasonReact.Router.watchUrl(url =>
        self.send(ChangeRoute(url |> mapUrlToRoute))
      );
    self.onUnmount(() => ReasonReact.Router.unwatchUrl(watchId));
  },
  render: self => {
    <div>
      <Link href=("contacts")>
        (ReasonReact.string("Contacts"))
      </Link>
      <CitySelector cities />
      (
        switch (self.state.route) {
          | ModelRoute(modelName) => <ModelPage name=modelName />
          | ModelsGridRoute(cityName) => <ModelsGridPage models city=cityName />
          | ContactRoute => <ContactPage />
          | NotFound => <NotFoundPage />
          }
      )
      </div>;
  }
};
