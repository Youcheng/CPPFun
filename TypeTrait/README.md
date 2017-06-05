The type traits library enables you, to check, to compare and to modify types at compile time.
So there is no overhead on the runtime of your program.

There are two reasons for using the type traits library: Optimization and Correctness.

Optimization, because the introspection capabilities of the type traits library make
it possible to choose automatically the faster code.

Correctness, because you can specify requirements for your code,
which will be checked at compile time.


The type traits library and the function static_assert are a powerful pair.
On one side, the functions of the type traits library provide the type information at compile time,
on the other side, the static_assert function checks the given information at compile time.