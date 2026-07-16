const b = T is object
const c = T is tuple
proc f(A: typedesc) =
  assert A is enum
