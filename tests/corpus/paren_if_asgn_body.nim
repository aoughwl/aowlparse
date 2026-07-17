proc f(a: cstring) =
  discard (if a == nil: result = newJNull() else: result = % $a)
