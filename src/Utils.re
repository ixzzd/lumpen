module RR = {
  include ReasonReact;
  let list = l => l |> Array.of_list |> ReasonReact.array;
};

let s = RR.string;
