proc f(x: uint64): uint64 =
  result = (((uint64)x) shl 8) + ((uint64) x)
  let y = (x + result)f
