entries.sort do (a, b: IndexEntry) -> int:
  cmp(a.key, b.key)

modules.sort do (a, b: (string, string, string)) -> int:
  cmp(a[0], b[0])
