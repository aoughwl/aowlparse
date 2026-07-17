template swapRefsInArray*{swap(arr[a], arr[b])}(arr: openArray[ref], a, b: int) =
  swap(cast[ptr pointer](addr arr[a])[], cast[ptr pointer](addr arr[b])[])
