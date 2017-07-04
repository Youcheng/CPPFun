Placement new does not allocate memory, it only calls a constructor on existing memory.
That existing memory could be on the stack or the heap - it doesn't matter.