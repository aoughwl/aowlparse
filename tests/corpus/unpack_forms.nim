import foo except a, b
import x/y except sym
export mymod except helper

for i, (sym, name) in efldSyms:
  discard

let (thenKind, elseKind) =
  if cond.negated: (IfFalse, IfTrue)
  else:            (IfTrue,  IfFalse)

let (a, b) = foo()
var (x, y, z) = bar
