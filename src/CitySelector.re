let component = ReasonReact.statelessComponent("CitySelector");

let make = (~cities: DataTypes.cities, _children) => {
  ...component,
  render: (_self) => {
    <div>
      {cities
       |> List.map((city: DataTypes.city) =>
         <Link key={string_of_int(city.id)} href=("/" ++ city.name)>
           (ReasonReact.string(city.name))
         </Link>
        )
       |> Array.of_list
       |> ReasonReact.array}
    </div>
  }
};
