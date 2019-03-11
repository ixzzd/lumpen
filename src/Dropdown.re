[@bs.module "react-dropdown/dist/index.js"]
external dropdown: ReasonReact.reactClass = "default";

[@bs.deriving abstract]
type item = {
  label: string,
  value: string,
};

[@bs.obj]
external makeProps:
(
  ~className: string=?,
  ~options: array(string),
  ~onChange: (item) => unit=?
) => _ = "";

let make = (~className: option(string)=?, ~options: array(string), ~onChange=?, _children) =>
ReasonReact.wrapJsForReason(
  ~reactClass=dropdown,
  ~props=
  makeProps(
    ~className?,
    ~options,
    ~onChange?
  ),
  _children,
);
