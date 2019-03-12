open Utils;

let component = RR.statelessComponent(__MODULE__);

let make = (_children, ~model: DataTypes.model) => {
  ...component,
  render: _self => {
    <div>
      <h2> {s("Model page:" ++ model.name)} </h2>
      <img src={model.avatar.normal} />
    </div>;
  },
};
