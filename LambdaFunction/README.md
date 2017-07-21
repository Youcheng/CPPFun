closure class
-------------
    A class from which an object(closure) is instantiated.
    Each lambda causes compilers to generate a unique closure class.
    The statements inside a lambda become executable instructions
    in the member functions of its closure class.

closure
--------
    The runtime object created by a lambda. Depending on the capture mode,
    closures hold copies of or reference to the captured data.
    
    Example,
    auto c1 = [x](int y) { return x*y > 55; } c1 is a copy of the closure produced by the lambda
    auto c2 = c1; c2 is a copy of c1