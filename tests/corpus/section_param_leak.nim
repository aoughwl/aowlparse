var
  g = proc () = discard
  ilocs: int
let
  f1 = proc(x: int): bool = true
  f2 = 3
const
  A = cast[proc(x: cint)](0)
  B = 2
