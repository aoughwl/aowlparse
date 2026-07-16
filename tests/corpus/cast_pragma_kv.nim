proc p() {.cast(raises: []).} = discard
proc q() {.cast(raises: [IOError, OSError]).} = discard
