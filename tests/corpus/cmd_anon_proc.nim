result.sort proc(a, b: int): int = cmp(nodes[a].depth, nodes[b].depth)

entries.sort(proc(a, b: (string, int)): int = cmp(a[0], b[0]))
