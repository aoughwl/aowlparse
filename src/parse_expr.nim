## parse_expr.nim — EXPRESSIONS & OPERATORS (owned by the expressions agent).
##
## Spliced after parsecore.nim (and parse_type.nim / parse_stmt.nim resolve
## against `parseExprRange` via the forward decl in parsecore.nim).
##
## Expression strategy: a token-range splitter. `parseExprRange [lo,hi)` finds the
## lowest-precedence depth-0 binary operator (rightmost = left-assoc) and emits
## `(infix op L R)`, recursing on the sub-ranges — reproducing nifler's operator
## nesting and pretty-print indentation. `parsePrimaryRange` handles atoms/calls/
## grouping/prefix. EXTEND HERE: dot (`(dot a b)`), index (`(at a b)`),
## `(curlyat …)`, cast/addr/typeof, ranges `(infix .. a b)`, constructors
## (`(bracket …)`,`(curly …)`,`(tup …)`,`(oconstr …)`,`(tabconstr …)`), named
## args (`(vv k v)` / `(kv k v)`), if/case expressions. See nifler-nif-spec.md §3.

proc parseCallRange(ps: var Parser; b: var Builder; lo, hi, pl, pc: int32) =
  ## `callee(args)` spanning `[lo, hi)`; `lo+1` is the `(`.
  let callee = ps.tok(int(lo))
  let lpIdx = int(lo) + 1
  let lp = ps.tok(lpIdx)
  let rpIdx = ps.matchClose(lpIdx)
  b.addTree "call"
  ps.emitInfo(b, lp.line, lp.col, pl, pc, false)   # call node info = '(' position
  b.addIdent callee.s
  ps.emitInfo(b, callee.line, callee.col, lp.line, lp.col, false)
  let starts = ps.splitArgs(lpIdx + 1, rpIdx)
  for ai in 0 ..< starts.len:
    let aLo = starts[ai]
    let aHi = if ai + 1 < starts.len: starts[ai+1] - 1 else: rpIdx
    if aLo < aHi:
      ps.parseExprRange(b, int32(aLo), int32(aHi), lp.line, lp.col)
  b.endTree()

proc parsePrimaryRange(ps: var Parser; b: var Builder; lo, hi, pl, pc: int32) =
  let t = ps.tok(int(lo))
  case t.kind
  of tkIntLit:
    b.addIntLit t.iVal
    ps.emitInfo(b, t.line, t.col, pl, pc, false)
  of tkFloatLit:
    b.addFloatLit(t.fVal, t.col - pc, t.line - pl, "")
  of tkStrLit:
    b.addStrLit t.s
    ps.emitInfo(b, t.line, t.col, pl, pc, false)
  of tkRStrLit:
    b.addStrLit(t.s, "R", t.col - pc, t.line - pl, "")
  of tkTripleStrLit:
    b.addStrLit(t.s, "T", t.col - pc, t.line - pl, "")
  of tkCharLit:
    b.addCharLit char(t.iVal)
    ps.emitInfo(b, t.line, t.col, pl, pc, false)
  of tkParLe:
    # `(...)` grouping — `(par x)` or `(tup a b)` (best-effort)
    let rpIdx = ps.matchClose(int(lo))
    let starts = ps.splitArgs(int(lo) + 1, rpIdx)
    let tag = if starts.len > 1: "tup" else: "par"
    b.addTree tag
    ps.emitInfo(b, t.line, t.col, pl, pc, false)
    for ai in 0 ..< starts.len:
      let aLo = starts[ai]
      let aHi = if ai + 1 < starts.len: starts[ai+1] - 1 else: rpIdx
      if aLo < aHi:
        ps.parseExprRange(b, int32(aLo), int32(aHi), t.line, t.col)
    b.endTree()
  of tkOperator:
    # prefix operator: `(prefix op operand)`
    b.addTree "prefix"
    ps.emitInfo(b, t.line, t.col, pl, pc, false)
    b.addIdent t.s
    ps.emitInfo(b, t.line, t.col, t.line, t.col, false)
    if int(lo) + 1 < int(hi):
      ps.parseExprRange(b, lo + 1, hi, t.line, t.col)
    b.endTree()
  of tkIdent, tkKeyword:
    if t.kind == tkKeyword and t.s == "nil":
      b.addTree "nil"
      ps.emitInfo(b, t.line, t.col, pl, pc, false)
      b.endTree()
    elif int(lo) + 1 < int(hi) and ps.tok(int(lo)+1).kind == tkParLe and
         ps.tok(int(lo)+1).line == t.line and
         ps.tok(int(lo)+1).col == t.col + int32(t.s.len):
      # adjacent `(` → call
      ps.parseCallRange(b, lo, hi, pl, pc)
    else:
      b.addIdent t.s
      ps.emitInfo(b, t.line, t.col, pl, pc, false)
  else:
    b.addEmpty

proc parseExprRange(ps: var Parser; b: var Builder; lo, hi, pl, pc: int32) =
  let split = ps.findSplit(int(lo), int(hi))
  if split < 0:
    ps.parsePrimaryRange(b, lo, hi, pl, pc)
  else:
    let op = ps.tok(split)
    b.addTree "infix"
    ps.emitInfo(b, op.line, op.col, pl, pc, false)   # infix node info = operator pos
    b.addIdent op.s
    ps.emitInfo(b, op.line, op.col, op.line, op.col, false)
    ps.parseExprRange(b, lo, int32(split), op.line, op.col)          # left
    ps.parseExprRange(b, int32(split) + 1, hi, op.line, op.col)      # right
    b.endTree()
