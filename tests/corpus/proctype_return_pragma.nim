proc t*(v: int): proc (x: cint) {.noconv.} =
  discard
template sa*(v: int): proc (x: cint) {.noconv.} =
  cast[proc (x: cint) {.noconv.}](v)
type
  Stream = ref object
    closeImpl*: proc (s: Stream)
      {.nimcall, gcsafe.}
    atEndImpl*: proc (s: Stream): bool
      {.nimcall, gcsafe.}
