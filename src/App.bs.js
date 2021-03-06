// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Link$ReasonSsr = require("./Link.bs.js");
var Utils$ReasonSsr = require("./Utils.bs.js");
var ModelPage$ReasonSsr = require("./ModelPage.bs.js");
var ContactPage$ReasonSsr = require("./ContactPage.bs.js");
var CitySelector$ReasonSsr = require("./CitySelector.bs.js");
var NotFoundPage$ReasonSsr = require("./NotFoundPage.bs.js");
var ModelsGridPage$ReasonSsr = require("./ModelsGridPage.bs.js");

function reducer(action, _state) {
  return /* Update */Block.__(0, [/* record */[/* route */action[0]]]);
}

function mapUrlToRoute(url) {
  var match = url[/* path */0];
  if (match) {
    var cityName = match[0];
    var exit = 0;
    if (cityName === "contacts" && !match[1]) {
      return /* ContactRoute */0;
    } else {
      exit = 1;
    }
    if (exit === 1) {
      var match$1 = match[1];
      if (match$1) {
        if (match$1[1]) {
          return /* NotFound */1;
        } else {
          return /* ModelRoute */Block.__(0, [match$1[0]]);
        }
      } else {
        return /* ModelsGridRoute */Block.__(1, [cityName]);
      }
    }
    
  } else {
    return /* NotFound */1;
  }
}

var component = Curry._1(Utils$ReasonSsr.RR[/* reducerComponent */2], "App-ReasonSsr");

function make(models, cities, _children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */(function (self) {
              var watchId = ReasonReact.Router[/* watchUrl */1]((function (url) {
                      return Curry._1(self[/* send */3], /* ChangeRoute */[mapUrlToRoute(url)]);
                    }));
              return Curry._1(self[/* onUnmount */4], (function (param) {
                            return ReasonReact.Router[/* unwatchUrl */2](watchId);
                          }));
            }),
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* route */0];
              var tmp;
              if (typeof match === "number") {
                tmp = match === 0 ? ReasonReact.element(undefined, undefined, ContactPage$ReasonSsr.make(/* array */[])) : ReasonReact.element(undefined, undefined, NotFoundPage$ReasonSsr.make(/* array */[]));
              } else if (match.tag) {
                tmp = ReasonReact.element(undefined, undefined, ModelsGridPage$ReasonSsr.make(models, match[0], /* array */[]));
              } else {
                var modelName = match[0];
                var model = List.find((function (model) {
                        return model[/* name */1] === modelName;
                      }), models);
                tmp = ReasonReact.element(undefined, undefined, ModelPage$ReasonSsr.make(/* array */[], model));
              }
              return React.createElement("div", undefined, ReasonReact.element(undefined, undefined, Link$ReasonSsr.make("/contacts", undefined, /* array */[Utils$ReasonSsr.s("Contacts")])), ReasonReact.element(undefined, undefined, CitySelector$ReasonSsr.make(cities, /* array */[])), tmp);
            }),
          /* initialState */(function (param) {
              return /* record */[/* route : ModelsGridRoute */Block.__(1, ["moscow"])];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */reducer,
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

exports.reducer = reducer;
exports.mapUrlToRoute = mapUrlToRoute;
exports.component = component;
exports.make = make;
/* component Not a pure module */
