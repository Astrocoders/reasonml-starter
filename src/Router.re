type route = RouterActions.route;

type action =
  | ChangeRoute(route);

type state = {currentRoute: route};

let component = ReasonReact.reducerComponent("Router");

let pathToRoute: ReasonReact.Router.url => route =
  ({path, hash}) =>
    switch (path) {
    | [] => HomeRoute
    };

let make = _children => {
  ...component,
  initialState: () => {
    currentRoute: pathToRoute(ReasonReact.Router.dangerouslyGetInitialUrl()),
  },
  reducer: (action, _state) =>
    switch (action) {
    | ChangeRoute(route) => ReasonReact.Update({currentRoute: route})
    },
  didMount: self =>
    ReasonReact.Router.watchUrl(url =>
      self.send(ChangeRoute(pathToRoute(url)))
    )
    |> (value => self.onUnmount(() => ReasonReact.Router.unwatchUrl(value))),
  render: self =>
    switch (self.state.currentRoute) {
    | HomeRoute => <Home message="Astrocoders ReasonML Starter" />
    },
};