proc f() =
  await fetch("x".cstring)
    .then((r: Response) => r.json())
    .then((j: JsObject) => log(j))
    .catch((e: Error) => log("Failed", e))
