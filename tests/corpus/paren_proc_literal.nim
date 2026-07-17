proc f() =
  result = (proc (y: int): int =
    n += y
    return n)
  let g = (witness = 2)
