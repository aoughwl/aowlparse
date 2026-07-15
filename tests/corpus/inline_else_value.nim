let dbgvSuffix = if not toExtern and not isImport:
                   emitGlobalDbgVar(c, name, varInfo, lit, diType) else: ""

let w = if cond:
          computeThing(a, b) else: fallback
