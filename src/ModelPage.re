let component = ReasonReact.statelessComponent("ModelPage");

let make = (_children, ~model:DataTypes.model) => {
  ...component,
  render: (_self) => {
    <div>
      <h2> {ReasonReact.string("Model page:" ++ model.name)} </h2>
      <img src={model.avatar.normal} />
    </div>
  }
};
