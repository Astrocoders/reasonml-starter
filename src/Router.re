type routes =
  | HomeRoute
  | NotFoundRoute;

let router = DirectorRe.makeRouter({
  "/": "home",
  "/404": "404"
});

let renderForRoute = (route) => {
  let element =
    switch route {
    | HomeRoute => <Home message="Welcome to Astrocoders ReasonML starter"/>
    | NotFoundRoute => <NotFound />
    };
  ReactDOMRe.renderToElementWithId(element, "root")
};

let handlers = {
  "home": () => renderForRoute(HomeRoute),
  "404": () => renderForRoute(NotFoundRoute)
};

DirectorRe.configure(router, {
  "html5history": true,
  "resource": handlers
});

let init = () => DirectorRe.init(router, "/");