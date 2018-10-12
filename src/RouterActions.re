type route =
  | HomeRoute;

let go = (route, _) =>
  switch (route) {
  | HomeRoute => ReasonReact.Router.push("/")
  };

let handleLink = (route, event) => {
  ReactEventRe.Synthetic.preventDefault(event);
  go(route, ());
};