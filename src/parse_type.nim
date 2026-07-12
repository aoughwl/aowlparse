## parse_type.nim — TYPE DEFS, ROUTINE DEFS, PARAMS, PRAGMAS
## (owned by the type/proc/pragma agent).
##
## Spliced after parse_expr.nim, before parse_stmt.nim. `parseType` is the
## cross-file entry (forward-declared in parsecore.nim); routine bodies call
## `parseStmt` (forward-declared in parsecore.nim, implemented in parse_stmt.nim).
##
## Currently: single-token type, flat params (multi-name groups, return-type-
## after-params), and routine defs (proc/func/method/iterator/…). EXTEND HERE:
## real type section `(type name export generics pragma rhs…)`; object
## (`(object … inherit (fld …))`), enum (`(enum . (efld …))`), tuple, ref/ptr,
## distinct, proctype/itertype; generic params `(typevars (typevar …))`; pragma
## slots `(pragmas …)` and the splitIdentDefName export/pragma convention. See
## nifler-nif-spec.md §5–7. Watch the traps: return type is a SIBLING emitted
## AFTER `(params)`, enum efld export & type slots are ALWAYS `.`, object fields
## carry FldL flattening.

proc parseType(ps: var Parser; b: var Builder; idx: int; pl, pc: int32): int =
  ## Minimal type: a single primary (ident). Returns index after it.
  let t = ps.tok(idx)
  b.addIdent t.s
  ps.emitInfo(b, t.line, t.col, pl, pc, false)
  result = idx + 1

proc parseParams(ps: var Parser; b: var Builder; lpIdx: int; pl, pc: int32): int =
  ## Emit `(params ...)` then the return type as a sibling. `lpIdx` is `(`.
  ## `pl,pc` = the enclosing routine node position. Returns index after the
  ## return type (or after `)` if none).
  let lp = ps.tok(lpIdx)
  let rpIdx = ps.matchClose(lpIdx)
  b.addTree "params"
  ps.emitInfo(b, lp.line, lp.col, pl, pc, false)   # params node info = '(' pos
  var i = lpIdx + 1
  while i < rpIdx:
    # collect a group of names up to ':'
    var names: seq[Token] = @[]
    if ps.tok(i).kind == tkIdent or ps.tok(i).kind == tkKeyword:
      names.add ps.tok(i)
      inc i
    while i < rpIdx and ps.tok(i).kind == tkComma:
      inc i
      if i < rpIdx and (ps.tok(i).kind == tkIdent or ps.tok(i).kind == tkKeyword):
        names.add ps.tok(i)
        inc i
    var typeIdx = -1
    if i < rpIdx and ps.tok(i).kind == tkColon:
      inc i
      typeIdx = i
      inc i  # single-token type (skeleton)
    for nm in names:
      b.addTree "param"
      ps.emitInfo(b, nm.line, nm.col, lp.line, lp.col, false)  # param node = name pos
      b.addIdent nm.s
      ps.emitInfo(b, nm.line, nm.col, nm.line, nm.col, false)
      b.addEmpty  # export marker
      b.addEmpty  # pragma
      if typeIdx >= 0:
        discard ps.parseType(b, typeIdx, nm.line, nm.col)  # type (parent = name)
      else:
        b.addEmpty
      b.addEmpty  # value
      b.endTree()
    # separator between groups
    if i < rpIdx and (ps.tok(i).kind == tkComma or ps.tok(i).kind == tkSemicolon):
      inc i
  b.endTree()  # close params
  # return type sibling
  var j = rpIdx + 1
  if ps.tok(j).kind == tkColon:
    inc j
    j = ps.parseType(b, j, lp.line, lp.col)   # ret type parent = params node ('(' pos)
  else:
    b.addEmpty
  result = j

proc parseRoutine(ps: var Parser; b: var Builder; kwIdx: int; pl, pc: int32;
                  tag: string): int =
  let kw = ps.tok(kwIdx)
  b.addTree tag
  ps.emitInfo(b, kw.line, kw.col, pl, pc, false)   # routine node info = keyword pos
  var i = kwIdx + 1
  # name
  let name = ps.tok(i)
  b.addIdent name.s
  ps.emitInfo(b, name.line, name.col, kw.line, kw.col, false)
  inc i
  # export marker `*`
  if ps.tok(i).kind == tkOperator and ps.tok(i).s == "*":
    inc i
    b.addRaw " x"
  else:
    b.addEmpty
  b.addEmpty  # pattern
  b.addEmpty  # generics
  # params + return type
  if ps.tok(i).kind == tkParLe:
    i = ps.parseParams(b, i, kw.line, kw.col)
  else:
    b.addEmpty  # params slot
    b.addEmpty  # return type slot
  b.addEmpty  # pragmas
  b.addEmpty  # reserved / misc
  # body after `=`
  if ps.tok(i).kind == tkOperator and ps.tok(i).s == "=":
    inc i
    # body = indented block; body stmts node info = first body stmt position
    let refIndent = kw.col
    if ps.tok(i).kind == tkEof or ps.tok(i).indent <= refIndent:
      b.addEmpty
    else:
      let first = ps.tok(i)
      b.addTree "stmts"
      ps.emitInfo(b, first.line, first.col, kw.line, kw.col, false)  # body parent = routine node
      while ps.tok(i).kind != tkEof and ps.tok(i).indent > refIndent:
        i = ps.parseStmt(b, i, first.line, first.col)
      b.endTree()
  else:
    b.addEmpty
  b.endTree()
  result = i
