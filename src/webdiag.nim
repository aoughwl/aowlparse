## webdiag.nim — the syntactic-diagnostics side-channel used by the JS/web build.
##
## The classic native `nifler` (and nifparser's own file driver) only *parse* —
## they do not surface friendly syntax errors. The browser playground, however,
## wants Monaco squiggles, so the web entry (`webmain.nim`) collects a list of
## `Diag`s alongside the produced NIF.
##
## This module keeps that diagnostics layer OUT of the 8 core parser files
## (`tokens/lexer/parse_*/parsecore/parser`), which are synced byte-for-byte from
## the canonical `nifparser/src` and intentionally carry no diagnostics API. All
## the web-only reporting lives here instead.
##
## Two producers:
##   * `tokenizeD` — tokenize + return any lexer-level diagnostics (side-channel).
##   * `bracketDiags` — a depth-tracking scan over the flat token list that flags
##     unmatched / mismatched / unclosed `()[]{}` brackets.

import tokens, lexer

type
  Diag* = object
    line*: int32     ## 1-based source line (as produced by the lexer)
    col*: int32      ## 0-based source column
    msg*: string     ## human-readable message

proc diag*(line, col: int32; msg: string): Diag =
  Diag(line: line, col: col, msg: msg)

proc tokenizeD*(src: string): tuple[toks: seq[Token]; diags: seq[Diag]] =
  ## Tokenize `src`, returning the tokens plus any lexer-level diagnostics.
  ## The core lexer parses leniently (it never aborts), so bracket-balance is the
  ## principal syntactic check — see `bracketDiags`, which `webmain` also folds in.
  result = (tokenize(src), @[])

# ---------------------------------------------------------------------------
# bracket balancing
# ---------------------------------------------------------------------------

proc isOpenBracket(k: TokKind): bool =
  k == tkParLe or k == tkBracketLe or k == tkCurlyLe

proc isCloseBracket(k: TokKind): bool =
  k == tkParRi or k == tkBracketRi or k == tkCurlyRi

proc closerFor(k: TokKind): TokKind =
  ## The closing kind that matches an opening bracket kind.
  case k
  of tkParLe: tkParRi
  of tkBracketLe: tkBracketRi
  of tkCurlyLe: tkCurlyRi
  else: tkEof

proc bracketName(k: TokKind): string =
  ## `'()'` / `'[]'` / `'{}'` naming the bracket family of `k`.
  case k
  of tkParLe, tkParRi: "'()'"
  of tkBracketLe, tkBracketRi: "'[]'"
  of tkCurlyLe, tkCurlyRi: "'{}'"
  else: "''"

proc bracketDiags*(toks: seq[Token]): seq[Diag] =
  ## Scan the token list for unbalanced brackets, reporting one `Diag` each for:
  ##   * a closer with nothing open   → `unmatched closing '…'`
  ##   * a closer of the wrong family → `mismatched bracket: '…' opened at L:C closed by '…'`
  ##   * an opener never closed       → `unclosed '…'`
  result = @[]
  var stack: seq[Token] = @[]
  for i in 0 ..< toks.len:
    let ii = toks[i]
    if isOpenBracket(ii.kind):
      stack.add ii
    elif isCloseBracket(ii.kind):
      if stack.len == 0:
        result.add diag(ii.line, ii.col, "unmatched closing " & bracketName(ii.kind))
      else:
        let top = stack[stack.len - 1]
        if closerFor(top.kind) != ii.kind:
          result.add diag(ii.line, ii.col,
            "mismatched bracket: " & bracketName(top.kind) &
            " opened at " & $top.line & ":" & $(top.col + 1) &
            " closed by " & bracketName(ii.kind))
          discard stack.pop()
        else:
          discard stack.pop()
  for i in 0 ..< stack.len:
    let ii = stack[i]
    result.add diag(ii.line, ii.col, "unclosed " & bracketName(ii.kind))
