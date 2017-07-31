special member functions
------------------------
    The ones that C++ is willing to generate on its own if they're needed, i.e.,
    if some code uses them without their being expressly declared in the class.

    The special member functions are those compilers may generate on their own:
    default constructor, destructor, copy operations, and move operations.


default constructor
-------------------
* default constructor
  Generated only if the class contains no user-declared constructors.

destructor
----------
* destructor
  destructors are noexcept by default; virtual only if a base class destructor is virtual.

copy operations
---------------
* copy assignment
    Generated only if the class lacks an explicitly declared copy assignment operator, and it’s deleted if a move operation is declared.
    Generation of this function in a class with a user-declared copy constructor or destructor is deprecated.

* copy constructor
    Generated only if the class lacks an explicitly declared copy constructor, and it’s deleted if a move operation is declared.
    Generation of this function in a class with a user-declared copy assignment operator or destructor is deprecated.

move operations
---------------
* move constructor and assignment operator
    Generated only if the class lacks explicitly declared move operations, copy operations, and a destructor.


