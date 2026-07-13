## webmain.nim — browser/Node entry for nifparser, compiled through the
## nimony-web JS backend (`nim_js`). It replaces nifparser.nim's file/stdout
## bridges with in-memory equivalents so the parser runs with NO file I/O:
##
##   * INPUT   — the Nim source text arrives as a JS string in
##               `globalThis.__np_src` (set by the JS glue before `main` runs).
##               The file-field path written into NIF line-info suffixes arrives
##               as `globalThis.__np_file` (defaults to "in.nim" if empty), so
##               the produced bytes can be made byte-identical to native nifler /
##               `bin/nifparser` invoked on that same relative path.
##   * PARSE   — identical to nifparser.parseToFile: tokenize -> initParser ->
##               parseModule, but the builder is an in-MEMORY nifbuilder
##               (`open(sizeHint)`) whose bytes we `extract` instead of flushing
##               to a file.
##   * OUTPUT  — the produced `.p.nif` bytes are handed back to JS on
##               `globalThis.__np_out` (string). No filesystem, no stdout.
##
## This is the proof that nifparser (the parser half of client-side Tier 2) runs
## in the browser. Modeled on nifi/src/nifi/webmain.nim.

when defined(nimony):
  {.feature: "lenientnils".}

import nifbuilder
import tokens, lexer, parser
import webdiag              # web-only syntactic diagnostics (Diag/tokenizeD/bracketDiags)
import jsffi

proc jsonEscape(s: string): string =
  result = ""
  for c in s:
    case c
    of '"': result.add "\\\""
    of '\\': result.add "\\\\"
    of '\x08': result.add "\\b"
    of '\x0C': result.add "\\f"
    of '\x0A': result.add "\\n"
    of '\x0D': result.add "\\r"
    of '\x09': result.add "\\t"
    else:
      if c < ' ':
        const hex = "0123456789abcdef"
        result.add "\\u00"
        result.add hex[(ord(c) shr 4) and 0xF]
        result.add hex[ord(c) and 0xF]
      else:
        result.add c

proc diagsToJson(ds: seq[Diag]): string =
  ## `[{"line":L,"col":C,"message":"..."}]` — line 1-based, col 0-based, both as
  ## produced by the lexer/parser (the JS glue converts to Monaco's 1-based cols).
  result = "["
  for i in 0 ..< ds.len:
    if i > 0: result.add ","
    result.add "{\"line\":"
    result.add $ds[i].line
    result.add ",\"col\":"
    result.add $ds[i].col
    result.add ",\"message\":\""
    result.add jsonEscape(ds[i].msg)
    result.add "\"}"
  result.add "]"

proc parseToStr(src, fileField: string; curly: bool; diagJson: var string): string =
  ## Parse Nim source text from memory to the `.p.nif` byte string, and set
  ## `diagJson` to the JSON array of syntactic diagnostics (side-channel).
  ## `curly` enables the experimental `{ … }` block-body mode (see initParser).
  let lexed = tokenizeD(src)
  let toks = lexed.toks
  var ds = lexed.diags
  for d in bracketDiags(toks): ds.add d
  diagJson = diagsToJson(ds)
  var ps = initParser(toks, fileField, curly)
  var b = nifbuilder.open(src.len * 4 + 256)   # in-memory builder
  parseModule(ps, b)
  result = extract(b)

proc npRun() =
  ## The whole browser entry, run as MODULE INIT (top-level). Like nifi's
  ## webmain it must NOT be `{.exportc: "main".}`: the JS backend emits its own
  ## `main(argc, argv, envp)` that runs the module inits, so a second `main`
  ## would shadow it. Running as top-level code means the generated entry's
  ## module-init call invokes this directly.
  # 1. read the Nim source JS parked on globalThis.__np_src
  let src = global("__np_src").toStr
  # 2. read the file-field path (relative path baked into line-info); default it
  var fileField = global("__np_file").toStr
  if fileField.len == 0:
    fileField = "in.nim"
  # 2b. read the experimental curly-block toggle: a non-empty string ("1") means
  #     accept `{ … }` block bodies; empty/absent means classic indent-only.
  let curly = global("__np_curly").toStr.len != 0
  # 3. parse fully in memory (also collects syntactic diagnostics)
  var diagJson = ""
  let outp = parseToStr(src, fileField, curly, diagJson)
  # 4. return the produced .p.nif bytes + diagnostics JSON to JS
  let g = global("globalThis")
  g.set("__np_out", toJs(outp))
  g.set("__np_diag", toJs(diagJson))

npRun()
