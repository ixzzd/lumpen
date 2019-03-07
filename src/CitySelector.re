open Utils;

let component = RR.statelessComponent(__MODULE__);

let make = (~cities: DataTypes.cities, _children) => {
  ...component,
  render: (_self) => {
    <div>
      {cities
       |> List.map((city: DataTypes.city) =>
         <Link key={string_of_int(city.id)} href=("/" ++ city.name)>
           (s(city.name))
         </Link>
        )
       |> RR.list}
    </div>
  }
};
