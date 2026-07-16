proc setup() =
  w.f = proc (w, a: pointer) {.nimcall.} =
    let w = cast[ptr Worker](w)
    cleanFlowVars(w)
    signal(w.q.empty)
  signal(w.taskArrived)
