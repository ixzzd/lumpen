open Utils;

let component = RR.statelessComponent(__MODULE__);

let handleClick = (href, event) =>
  if (!ReactEvent.Mouse.defaultPrevented(event)) {
    ReactEvent.Mouse.preventDefault(event);
    RR.Router.push(href);
  };

let make = (~href, ~className="", children) => {
  ...component,
  render: self =>
    <a
      href
      className
      onClick={self.handle((event, _) => handleClick(href, event))}>
      ...children
    </a>,
};
