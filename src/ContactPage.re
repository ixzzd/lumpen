let component = ReasonReact.statelessComponent("ContactPage");

let make = (_children) => {
  ...component,
  render: (_self) => {
      <div>
        <h2> {ReasonReact.string("Contacts")} </h2>
      </div>;
  },
};
