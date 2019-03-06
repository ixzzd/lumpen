let component = ReasonReact.statelessComponent("NotFoundPage");

let make = (_children) => {
  ...component,
  render: (_self) => <h2> {ReasonReact.string("Page not found")} </h2>
};
