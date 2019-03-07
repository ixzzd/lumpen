open DataTypes;
open Utils;

let component = RR.statelessComponent(__MODULE__);

let make = (~models: models, ~city, _children) => {
  ...component,
  render: (_self) => {
      <div>
        <h2> {s("Models in city: " ++ city)} </h2>
        <ul>
          {models
           |> List.filter((model: model) => model.city === city)
           |> List.map((model: model) =>
              <li key={string_of_int(model.id)}>
                <Link href=("/" ++ city ++ "/" ++ model.name)> model.name->s </Link>
              </li>
            )
           |> RR.list}
        </ul>
      </div>;
  },
};
