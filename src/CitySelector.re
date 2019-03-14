open Utils;
open Dropdown;

let component = RR.statelessComponent(__MODULE__);

let changeCity = cityName => RR.Router.push("/" ++ cityName);

let make = (~cities: DataTypes.cities, _children) => {
  ...component,
  render: _self => {
    let cityNames =
      cities
      |> List.map((city: DataTypes.city) =>
   //        InputMap(
             inputOptionToJs({
               label: city.name,
               className: Some(city.name),
               value: city.name,
             }),
    //      )
         )
      //InputString(city.name)
      |> Array.of_list;
    <Dropdown
      options=cityNames
      onChange={item => changeCity(Dropdown.valueGet(item))}
    />;
  },
};
