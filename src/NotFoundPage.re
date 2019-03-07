open Utils;

let component = RR.statelessComponent(__MODULE__);

let make = (_children) => {
  ...component,
  render: (_self) => <h2> {s("Page not found")} </h2>
};
