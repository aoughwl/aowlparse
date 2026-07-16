proc convert(a, b: int; s: string): string =
  let wideString = if a == 1200: s
                   else: toWide(s)
  return if b == 1200: wideString
         else: fromWide(wideString)

proc stmtForm(c: bool) =
  if c:
    echo "a"
  else:
    echo "b"
