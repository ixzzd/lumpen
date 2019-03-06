let component = ReasonReact.statelessComponent("ModelPage");

let make = (_children, ~name:string) => {
  ...component,
  render: (_self) => <h2> {ReasonReact.string("Model page:" ++ name)} </h2>
};
