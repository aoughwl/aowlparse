proc f() =
  server.maxFDs = try: maxDescriptors() except: nimMaxDescriptorsFallback
  x = block: computeIt()
