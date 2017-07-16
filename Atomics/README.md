lock-free programming
---------------------
    Lock-free programming is a set of techniques for writing concurrent programs without using
    explicit locks. Instead, the programmer relies on primitive operations (directly supported by hard-
    ware) to avoid data races for small objects (typically a single word or a double word).


atomic Type
-----------
    An atomic type is a specialization of the atomic template.
    An operation on an object of an atomic type is atomic.
    That is, it is performed by a single thread without interference from other threads.

atomic operation
----------------
    Primitive operations that do not suffer data races, often called atomic operations.
    - load
    - store
    - swap
    - increment
    - decrement

memory model
------------

