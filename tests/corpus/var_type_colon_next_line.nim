var posix_environ* {.importc: "environ", header: "<unistd.h>".}:
  ptr UncheckedArray[cstring]

const
  Big:
    int = 42

var x = if cond:
    1
  else:
    2
