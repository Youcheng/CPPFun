memory model
------------
    - a set of guarantees for concurrent access to memory that basically <br>
      ensures that simple and ordinary access works as one would naively expect.
    - the result of discussions between machine architects and compiler writers about how best to repre-
       sent computer hardware
    - represents a contract between the implementers and the programmers to ensure that most programmers do not
      have to think about the details of modern computer hardware.
    -  The C++ memory model guarantees that two threads of execution can update and access sepa-
       rate memory locations without interfering with each other
  
operation on an object in memory
--------------------------------
    - are never directly performed on the object in memory.
    - the object is first loaded from main memory into a cache memory and then to a register.


x = x + 1
---------
    - load x into cache Cx
    - load Cx into regiger Rx
    - Rx = Rx + 1 in the core
    - store Rx back to Cx
    - store Cx back to x

word in the memory
------------------
    - the machine cannot load or store anything smaller than a word

memory ordering
----
    The time needed to get the value of a word from memory into a cache,
    then into a register, can be (on a processor’s time scale) very long.
    At best, maybe 500 instructions are executed before the value reaches the register,
    and another 500 instructions are executed before a new value reaches its
    intended location.

    Memory ordering is the term used to describe
    what a programmer can assume about what a thread
    sees when it looks at a value from memory.

![Memory hierarchy](https://github.com/Youcheng/CPPFun/blob/master/MemoryModel/memoryHierarchy.png)