let component = ReasonReact.statelessComponent("App");

let make = (~models: DataTypes.models, ~cities: DataTypes.cities, _children) => {
  ...component,
  render: (_self) => <ModelsPage models=models />
};
