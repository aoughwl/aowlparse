proc f(c, d, x, y: int) =
  case c
  of 1: discard x
  elif c < d: discard y
  else: discard
