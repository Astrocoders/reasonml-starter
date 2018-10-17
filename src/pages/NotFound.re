let component = ReasonReact.statelessComponent("NotFound");

module Styles = {
  open Css;
  let notFoundBody =
    style([
      alignItems(center),
      backgroundColor(hex("ffffff")),
      display(`flex),
      flexDirection(`column),
      height(vh(100.)),
      justifyContent(center),
      margin(px(0)),
      width(vw(100.)),
    ]);

  let apologizes =
    style([
      paddingTop(px(50)),
      paddingBottom(px(50)),
      textAlign(`center),
      width(`percent(100.)),
    ]);
  let button = style([marginRight(px(30))]);
};

let make = _children => {
  ...component,
  render: _self =>
    <div className=Styles.notFoundBody>
      <div className=Styles.apologizes>
        <h2> ("We're sorry!" |> ReasonReact.string) </h2>
        <h3> ("Unfortunately, we can't seem to find the page you're looking for. Please take a look in our Coach Catalog." |> ReasonReact.string) </h3>
      </div>
    </div>,
};