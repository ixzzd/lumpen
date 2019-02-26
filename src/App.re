let component = ReasonReact.statelessComponent("App");

let make = (_children) => {
  ...component,
  render: (_self) => <div> {ReasonReact.string("Hello from Reason React")} </div>
};
