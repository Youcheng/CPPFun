# memory model
- a set of guarantees for concurrent access to memory that basically <br>
  ensures that simple and ordinary access works as one would naively expect
  
# operation on an object in memory
- are never directly performed on the object in memory.
- the object is first loaded from main memory into a cache memory and then to a register.   


# x = x + 1
- load x into cache Cx
- load Cx into regiger Rx
- Rx = Rx + 1 in the core
- store Rx back to Cx
- store Cx back to x

# word in the memory
- the machine cannot load or store anything smaller than a word 