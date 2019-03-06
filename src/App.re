let component = ReasonReact.statelessComponent("App");

let make = (~models: DataTypes.models, _children) => {
  ...component,
  render: (_self) => <ModelsPage models=models />
};
