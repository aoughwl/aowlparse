type CompletionData = object
  cb*: owned(proc (fd: AsyncFD, bytesTransferred: DWORD,
            errcode: OSErrorCode) {.closure, gcsafe.})
  it*: sink(iterator (): int)
