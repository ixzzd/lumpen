let component = ReasonReact.statelessComponent("ModelsPage");

let make = (~models: DataTypes.models, _children) => {
  ...component,
  render: (_self) => {
      <div>
        <h2> {ReasonReact.string("Models")} </h2>
        <ul>
          {models
           |> List.map((model: DataTypes.model) =>
                <li key={string_of_int(model.id)}>
                  {ReasonReact.string(model.name)}
                </li>
              )
           |> Array.of_list
           |> ReasonReact.array}
        </ul>
      </div>;
  },
};
