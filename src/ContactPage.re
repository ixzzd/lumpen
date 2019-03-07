open Utils;

let component = RR.statelessComponent(__MODULE__);

let make = (_children) => {
  ...component,
  render: (_self) => {
      <div>
        <h2> {s("Contacts")} </h2>
      </div>;
  },
};
