# Copy control

- copy constructor
- move constructor
To define what happens when an object is initialized
from another object of the same type.

- copy-assignment operator
- move-assignment operator
To define what happens when we assign an object of a class type
to another object of the same class type.

- destructor
To define what happens when an object of the type ceases to exist.

# Direct/Copy initialization

string dots(10, '.')  // direct
string book = "999";
string nines = string(100, '9')  // copy

- direct initialization(constructor)
We ask the compiler to use ordinary function matching to select the
constructor that best matches the arguments we provide.

- copy initialization(copy/move constructor)
We ask the compiler to copy right-hand operand into the object being created,
converting that operand if necessary.



