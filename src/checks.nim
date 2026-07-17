## checks.nim — the pure diagnostic layer shared by the CLI driver and the
## browser/JS entry (`webmain.nim`).
##
## This is the SAME recoverable-diagnostics surface `aowlparser check` exposes,
## with NO file/stdout I/O, so it compiles cleanly through the nimony-web JS
## backend and runs in the playground. The three producers are:
##
##   * the lexer's own `gLexDiags` (unknown bytes, unterminated literals, style
##     warnings) — collected by `tokenize`;
##   * `checkBrackets` — unbalanced / mismatched `()[]{}`, with a related
##     "opened here" location and a suggested fix;
##   * `checkGrammar` — grammar errors the range-splitter copes with but a real
##     front end rejects (identifier-expected, assignment-in-condition, empty
##     condition, trailing operator), each with a fix hint.
##
## The parser ALSO records grammar diagnostics as it copes (`ps.diags`); the
## caller merges those in and calls `sortBySourceOrder` before rendering.
## `diagsToJson` is the machine-readable shape the editor consumes, carrying the
## optional `fix` and `related` fields.
##
## Kept byte-faithful to the canonical driver (aowlparser.nim) so the two never
## drift: the playground gets exactly the CLI's error coverage.

import tokens

# --- structural bracket validation ------------------------------------------

proc closerFor(k: TokKind): char =
  ## The `)`/`]`/`}` character for a bracket kind (either open or close kind).
  case k
  of tkParLe, tkParRi: ')'
  of tkBracketLe, tkBracketRi: ']'
  else: '}'

proc openerFor(k: TokKind): char =
  ## The `(`/`[`/`{` character for a bracket kind (either open or close kind).
  case k
  of tkParLe, tkParRi: '('
  of tkBracketLe, tkBracketRi: '['
  else: '{'

proc matchesClose(open, close: TokKind): bool =
  (open == tkParLe and close == tkParRi) or
  (open == tkBracketLe and close == tkBracketRi) or
  (open == tkCurlyLe and close == tkCurlyRi)

proc checkBrackets*(toks: seq[Token]): seq[Diagnostic] =
  ## Unbalanced or mismatched `()`/`[]`/`{}`. A stack of opens is matched against
  ## each close; a wrong or surplus close, and every open left unclosed at EOF,
  ## becomes a `sevError` with the offending span. Purely a validator — it never
  ## affects the emitted AIF (the parser stays best-effort).
  result = @[]
  var stack: seq[Token] = @[]
  for t in toks:
    case t.kind
    of tkParLe, tkBracketLe, tkCurlyLe:
      stack.add t
    of tkParRi, tkBracketRi, tkCurlyRi:
      if stack.len == 0:
        result.add Diagnostic(severity: sevError, code: "unmatched-close",
          message: "unmatched '" & closerFor(t.kind) & "'",
          line: t.line, col: t.col, endCol: t.col + 1)
      elif not matchesClose(stack[stack.len - 1].kind, t.kind):
        let top = stack[stack.len - 1]
        result.add Diagnostic(severity: sevError, code: "mismatched-bracket",
          message: "'" & closerFor(t.kind) & "' does not match '" &
                   openerFor(top.kind) & "'",
          line: t.line, col: t.col, endCol: t.col + 1,
          fix: "change it to '" & closerFor(top.kind) & "' or fix the opener",
          relMsg: "'" & openerFor(top.kind) & "' opened here",
          relLine: top.line, relCol: top.col)
        stack.setLen(stack.len - 1)
      else:
        stack.setLen(stack.len - 1)
    else: discard
  for t in stack:
    result.add Diagnostic(severity: sevError, code: "unclosed-bracket",
      message: "unclosed '" & openerFor(t.kind) & "'",
      line: t.line, col: t.col, endCol: t.col + 1,
      fix: "add a matching '" & closerFor(t.kind) & "'")

proc checkGrammar*(toks: seq[Token]): seq[Diagnostic] =
  ## Grammar-level errors the range-splitter silently copes with but nifler
  ## rejects. Purely a validator — never changes the emitted AIF. Conservative:
  ## every case here is UNAMBIGUOUSLY malformed (zero false positives on valid
  ## Nim), so `check` can flag it the way a real front end would.
  result = @[]
  # `let`/`const` ALWAYS introduce a declaration, so the next significant token
  # must begin a name: an identifier, or `(` for a tuple unpack. Anything else —
  # a keyword (`let proc`), an operator, a literal, a closing bracket, EOF — is
  # what nifler reports as "identifier expected, but got 'X'".
  # (`var`/`type` are deliberately NOT checked: they double as TYPE modifiers, so
  # `x: var ptr int` legitimately puts a keyword right after them.)
  for i in 0 ..< toks.len:
    let k = toks[i]
    if k.kind != tkKeyword or (k.s != "let" and k.s != "const"): continue
    # next significant token
    var j = i + 1
    while j < toks.len and toks[j].kind == tkComment: inc j
    if j >= toks.len: continue
    let nx = toks[j]
    let namey = nx.kind == tkIdent or nx.kind == tkParLe
    if not namey and nx.kind != tkEof:
      result.add Diagnostic(severity: sevError, code: "identifier-expected",
        message: "identifier expected after '" & k.s & "', but got '" &
                 (if nx.kind == tkKeyword: "keyword " & nx.s
                  elif nx.s.len > 0: nx.s else: "token") & "'",
        line: nx.line, col: nx.col, endCol: nx.endCol)
    elif nx.kind == tkEof:
      result.add Diagnostic(severity: sevError, code: "identifier-expected",
        message: "identifier expected after '" & k.s & "'",
        line: k.line, col: k.col, endCol: k.endCol)
  # Assignment '=' inside an if/elif/while/when CONDITION — the classic `==` typo
  # (`if x = 5:`). A bare depth-0 `=` there is always malformed (assignment is not
  # an expression in Nim); named args use `=` only inside `()` (depth > 0), so
  # this cannot false-positive. nifler reports a generic "expected ':', but got
  # '='"; we say what actually went wrong and offer the fix.
  for i in 0 ..< toks.len:
    let k = toks[i]
    if k.kind != tkKeyword or (k.s != "if" and k.s != "elif" and
                               k.s != "while" and k.s != "when"): continue
    # EMPTY condition: the keyword is immediately followed by its `:` (`elif:`,
    # `if:`, `while:`). A condition is always required, so this is unambiguous.
    if i + 1 < toks.len and toks[i+1].kind == tkColon:
      result.add Diagnostic(severity: sevError, code: "expected-condition",
        message: "'" & k.s & "' requires a condition before ':'",
        line: k.line, col: k.col, endCol: k.endCol,
        fix: "add a condition, e.g. '" & k.s & " cond:'")
      continue
    # scan the condition: from after the keyword to the depth-0 `:` (or line end).
    var depth = 0
    var j = i + 1
    while j < toks.len:
      let t2 = toks[j]
      if t2.kind == tkEof: break
      if t2.kind == tkParLe or t2.kind == tkBracketLe or t2.kind == tkCurlyLe:
        inc depth
      elif t2.kind == tkParRi or t2.kind == tkBracketRi or t2.kind == tkCurlyRi:
        if depth > 0: dec depth else: break
      elif depth == 0 and t2.kind == tkColon: break
      elif depth == 0 and t2.line != k.line: break   # condition ended at newline
      elif depth == 0 and t2.kind == tkOperator and t2.s == "=":
        result.add Diagnostic(severity: sevError, code: "assignment-in-condition",
          message: "'=' assigns; this '" & k.s & "' condition needs a comparison",
          line: t2.line, col: t2.col, endCol: t2.endCol,
          fix: "did you mean '=='?")
        break
      inc j
  # last significant (non-comment) token
  var last = -1
  for i in countdown(toks.len - 1, 0):
    if toks[i].kind != tkEof and toks[i].kind != tkComment:
      last = i; break
  if last < 0: return
  let t = toks[last]
  # An operator, comma, or dot as the FINAL token has no operand after it —
  # `let x = 1 +`, `foo(a,` (the bracket check also flags the paren), `a.` — so
  # nifler reports "expression expected". Even a *prefix* operator needs a
  # following operand, so ANY trailing operator is incomplete. `=` is excluded:
  # a proc header can legitimately end `= <body>` and a lone trailing `=` is
  # rare enough to leave to the bracket/indent checks.
  let kwOp = t.kind == tkKeyword and t.s in
    ["and", "or", "xor", "div", "mod", "shl", "shr", "in", "notin",
     "is", "isnot", "not", "of"]
  if t.kind == tkComma or t.kind == tkDot or
     (t.kind == tkOperator and t.s != "=") or kwOp:
    result.add Diagnostic(severity: sevError, code: "expression-expected",
      message: "expression expected after '" &
               (if t.kind == tkComma: "," elif t.kind == tkDot: "." else: t.s) &
               "'", line: t.line, col: t.col, endCol: t.endCol)

proc sortBySourceOrder*(diags: var seq[Diagnostic]) =
  ## Stable insertion sort by (line, col) so `check`/JSON output reads
  ## top-to-bottom instead of validator-internal order. Diagnostic counts are
  ## tiny, so an O(n²) sort is fine and avoids a stdlib dependency.
  for i in 1 ..< diags.len:
    let cur = diags[i]
    var j = i - 1
    while j >= 0 and (diags[j].line > cur.line or
                      (diags[j].line == cur.line and diags[j].col > cur.col)):
      diags[j + 1] = diags[j]
      dec j
    diags[j + 1] = cur

proc sevName*(s: Severity): string =
  case s
  of sevError: "error"
  of sevWarn: "warning"
  of sevHint: "hint"

proc jsonEscape*(s: string): string =
  result = ""
  for c in s:
    case c
    of '"': result.add "\\\""
    of '\\': result.add "\\\\"
    of '\n': result.add "\\n"
    of '\t': result.add "\\t"
    of '\r': result.add "\\r"
    else:
      if c < ' ': result.add "\\u" & ["0000","0001","0002","0003","0004","0005",
        "0006","0007","0008","0009","000A","000B","000C","000D","000E","000F",
        "0010","0011","0012","0013","0014","0015","0016","0017","0018","0019",
        "001A","001B","001C","001D","001E","001F"][int(c)]
      else: result.add c

proc diagsToJson*(diags: seq[Diagnostic]): string =
  ## `[{severity,code,message,line,col,endCol[,fix][,related]}]` — line 1-based,
  ## col/endCol 0-based (the JS glue shifts col to Monaco's 1-based). Matches
  ## `aowlparser check --diagnostics:json` exactly.
  result = "["
  for i in 0 ..< diags.len:
    let d = diags[i]
    if i > 0: result.add ","
    result.add "{\"severity\":\"" & sevName(d.severity) & "\",\"code\":\"" &
      d.code & "\",\"message\":\"" & jsonEscape(d.message) &
      "\",\"line\":" & $d.line & ",\"col\":" & $d.col &
      ",\"endCol\":" & $d.endCol
    if d.fix.len > 0:
      result.add ",\"fix\":\"" & jsonEscape(d.fix) & "\""
    if d.relMsg.len > 0:
      result.add ",\"related\":{\"message\":\"" & jsonEscape(d.relMsg) &
        "\",\"line\":" & $d.relLine & ",\"col\":" & $d.relCol & "}"
    result.add "}"
  result.add "]"
