## parse_stmt.nim — STATEMENTS, CONTROL FLOW, var/let/const SECTIONS
## (owned by the statements agent).
##
## Spliced LAST (after parse_expr.nim and parse_type.nim), so it can call
## `parseExprRange`, `parseType`, `parseRoutine` directly. `parseStmt` is the
## dispatch entry (forward-declared in parsecore.nim) — routine bodies and the
## module loop re-enter through it.
##
## Currently: expr/command/assignment statements, return-like (ret/discard/raise/
## yld), import-like. EXTEND HERE: `if`/`elif`/`else`, `case`+`(of (ranges …) …)`,
## `while`, `for`+`(unpackflat (let …))` / `(unpacktup …)`, `try`/`except`/`fin`,
## `when`, `block`/`break`/`continue`, `defer`; and var/let/const SECTIONS which
## emit NO wrapper — each ident-def is its own sibling with type & value
## DUPLICATED across a multi-name group (`(var name . pragma type value)`), plus
## var-tuple `(unpackdecl value (unpacktup (let …)…))`. See nifler-nif-spec.md §4.
## Indentation-delimited blocks: use `ps.tok(i).indent > refIndent` like
## parseRoutine's body loop.

proc parseCommand(ps: var Parser; b: var Builder; lo, hi, pl, pc: int32) =
  let callee = ps.tok(int(lo))
  b.addTree "cmd"
  ps.emitInfo(b, callee.line, callee.col, pl, pc, false)   # cmd node info = callee pos
  b.addIdent callee.s
  ps.emitInfo(b, callee.line, callee.col, callee.line, callee.col, false)
  let starts = ps.splitArgs(int(lo) + 1, int(hi))
  for ai in 0 ..< starts.len:
    let aLo = starts[ai]
    let aHi = if ai + 1 < starts.len: starts[ai+1] - 1 else: int(hi)
    if aLo < aHi:
      ps.parseExprRange(b, int32(aLo), int32(aHi), callee.line, callee.col)
  b.endTree()

proc parseExprStmt(ps: var Parser; b: var Builder; lo, hi, pl, pc: int32) =
  let eqi = ps.findAssign(int(lo), int(hi))
  if eqi >= 0:
    let op = ps.tok(eqi)
    b.addTree "asgn"
    ps.emitInfo(b, op.line, op.col, pl, pc, false)
    ps.parseExprRange(b, lo, int32(eqi), op.line, op.col)
    ps.parseExprRange(b, int32(eqi) + 1, hi, op.line, op.col)
    b.endTree()
    return
  # command: leading ident, no depth-0 binary operator, not an adjacent call,
  # and a following argument token.
  let head = ps.tok(int(lo))
  let isCmd =
    (head.kind == tkIdent) and (int(lo) + 1 < int(hi)) and
    (ps.findSplit(int(lo), int(hi)) < 0) and
    not (ps.tok(int(lo)+1).kind == tkParLe and
         ps.tok(int(lo)+1).col == head.col + int32(head.s.len)) and
    startsExpr(ps.tok(int(lo)+1))
  if isCmd:
    ps.parseCommand(b, lo, hi, pl, pc)
  else:
    ps.parseExprRange(b, lo, hi, pl, pc)

proc parseReturnLike(ps: var Parser; b: var Builder; kwIdx: int; pl, pc: int32;
                     tag: string): int =
  let kw = ps.tok(kwIdx)
  let hi = ps.lineEnd(kwIdx)
  b.addTree tag
  ps.emitInfo(b, kw.line, kw.col, pl, pc, false)
  if kwIdx + 1 < hi and startsExpr(ps.tok(kwIdx+1)):
    ps.parseExprRange(b, int32(kwIdx) + 1, int32(hi), kw.line, kw.col)
  else:
    b.addEmpty
  b.endTree()
  result = hi

proc parseImportLike(ps: var Parser; b: var Builder; kwIdx: int; pl, pc: int32;
                     tag: string): int =
  let kw = ps.tok(kwIdx)
  let hi = ps.lineEnd(kwIdx)
  b.addTree tag
  ps.emitInfo(b, kw.line, kw.col, pl, pc, false)
  let starts = ps.splitArgs(kwIdx + 1, hi)
  for ai in 0 ..< starts.len:
    let aLo = starts[ai]
    let aHi = if ai + 1 < starts.len: starts[ai+1] - 1 else: hi
    if aLo < aHi:
      ps.parseExprRange(b, int32(aLo), int32(aHi), kw.line, kw.col)
  b.endTree()
  result = hi

proc parseStmt(ps: var Parser; b: var Builder; startIdx: int; pl, pc: int32): int =
  ## Emit one statement starting at token `startIdx`. Returns the index of the
  ## first token AFTER the statement.
  let t = ps.tok(startIdx)
  if t.kind == tkKeyword:
    case t.s
    of "proc": return ps.parseRoutine(b, startIdx, pl, pc, "proc")
    of "func": return ps.parseRoutine(b, startIdx, pl, pc, "func")
    of "method": return ps.parseRoutine(b, startIdx, pl, pc, "method")
    of "converter": return ps.parseRoutine(b, startIdx, pl, pc, "converter")
    of "iterator": return ps.parseRoutine(b, startIdx, pl, pc, "iterator")
    of "macro": return ps.parseRoutine(b, startIdx, pl, pc, "macro")
    of "template": return ps.parseRoutine(b, startIdx, pl, pc, "template")
    of "return": return ps.parseReturnLike(b, startIdx, pl, pc, "ret")
    of "discard": return ps.parseReturnLike(b, startIdx, pl, pc, "discard")
    of "raise": return ps.parseReturnLike(b, startIdx, pl, pc, "raise")
    of "yield": return ps.parseReturnLike(b, startIdx, pl, pc, "yld")
    of "import": return ps.parseImportLike(b, startIdx, pl, pc, "import")
    of "include": return ps.parseImportLike(b, startIdx, pl, pc, "include")
    of "export": return ps.parseImportLike(b, startIdx, pl, pc, "export")
    else: discard
  # expression / command / assignment statement (single logical line)
  let hi = ps.lineEnd(startIdx)
  ps.parseExprStmt(b, int32(startIdx), int32(hi), pl, pc)
  result = hi
