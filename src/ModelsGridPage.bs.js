// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Link$ReasonSsr = require("./Link.bs.js");

var component = ReasonReact.statelessComponent("ModelsGridPage");

function make(models, city, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", undefined, React.createElement("h2", undefined, "Models in city: " + city), React.createElement("ul", undefined, $$Array.of_list(List.map((function (model) {
                                        return React.createElement("li", {
                                                    key: String(model[/* id */0])
                                                  }, ReasonReact.element(undefined, undefined, Link$ReasonSsr.make("/" + (city + ("/" + model[/* name */1])), undefined, /* array */[model[/* name */1]])));
                                      }), List.filter((function (model) {
                                              return model[/* city */2] === city;
                                            }))(models)))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
