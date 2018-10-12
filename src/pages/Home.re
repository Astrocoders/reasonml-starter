let component = ReasonReact.statelessComponent("Home");

module MD = MaterialUI;

module Styles = {
  open Css;
  let welcome =
    style([
      color(hex("DB4D3F")),
    ]);
};

let make = (~message, _children) => {
  ...component,
  render: _self =>
    <MD.Grid>
      <h1 className=Styles.welcome>(message |> ReasonReact.string)</h1>
    </MD.Grid>
};