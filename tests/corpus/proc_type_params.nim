proc initBlob(cleanup: proc (b: var VfsBlob): int = nil): VfsBlob =
  discard

survPairs.sort(proc (a: (int, SymId), b: (int, SymId)): int = cmp(a[0], b[0]))

let f = map(xs, proc (x: int): int = x + 1)
