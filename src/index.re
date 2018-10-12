[%bs.raw {|require('./index.css')|}];

[@bs.module "./App.js"] external app : ReasonReact.reactClass = "default";

module App = {
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=app,
      ~props=Js.Obj.empty(),
      children,
    );
};

ReactDOMRe.renderToElementWithId(<App> <Router /> </App>, "root");