[@bs.module "react-dropdown/dist/index.js"]
external dropdown: ReasonReact.reactClass = "default";

[@bs.deriving {jsConverter: newType}]
type inputOption = {
  label: string,
  value: string,
  className: option(string),
};
[@bs.deriving abstract]
type outputOption = {
  label: string,
  value: string,
};

type input =
  | InputMap(abs_inputOption)
  | InputString(string);

[@bs.obj]
external makeProps:
  (
    ~className: string=?,
    ~options: array(input),
    ~onChange: outputOption => unit=?,
    unit
  ) =>
  _ =
  "";

let make = (~className=?, ~options, ~onChange=?, _children) => {
  ReasonReact.wrapJsForReason(
    ~reactClass=dropdown,
    ~props=makeProps(~className?, ~options, ~onChange?, ()),
    _children,
  );
};
