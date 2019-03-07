open Utils;

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
  | ChangeRoute(route) => RR.Update({route: route})
  };

let mapUrlToRoute = (url: RR.Router.url) =>
  switch (url.path) {
  | ["contacts"] => ContactRoute
  | [cityName] => ModelsGridRoute(cityName)
  | [_, modelName] => ModelRoute(modelName)
  | _ => NotFound
  };

let component = RR.reducerComponent(__MODULE__);

let make = (~models: DataTypes.models, ~cities: DataTypes.cities, _children) => {
  ...component,
  reducer,
  initialState: () => {route: ModelsGridRoute("moscow")},
  didMount: self => {
    let watchId =
      RR.Router.watchUrl(url =>
        self.send(ChangeRoute(url |> mapUrlToRoute))
      );
    self.onUnmount(() => RR.Router.unwatchUrl(watchId));
  },
  render: self => {
    <div>
      <Link href=("/contacts")>
        (s("Contacts"))
      </Link>
      <CitySelector cities />
      (
        switch (self.state.route) {
          | ModelRoute(modelName) => {
            let model = models |> List.find((model: DataTypes.model) => model.name === modelName);
            <ModelPage model/>
          }
          | ModelsGridRoute(cityName) => <ModelsGridPage models city=cityName />
          | ContactRoute => <ContactPage />
          | NotFound => <NotFoundPage />
          }
      )
      </div>;
  }
};
