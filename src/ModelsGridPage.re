let component = ReasonReact.statelessComponent("ModelsGridPage");

let make = (~models: DataTypes.models, ~city, _children) => {
  ...component,
  render: (_self) => {
      <div>
        <h2> {ReasonReact.string("Models in city: " ++ city)} </h2>
        <ul>
          {models
           |> List.filter((model: DataTypes.model) => model.city === city)
           |> List.map((model: DataTypes.model) =>
              <li key={string_of_int(model.id)}>
                <Link href=("/" ++ city ++ "/" ++ model.name)> (ReasonReact.string(model.name)) </Link>
              </li>
            )
           |> Array.of_list
           |> ReasonReact.array}
        </ul>
      </div>;
  },
};
