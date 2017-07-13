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


# copy v.s move
- the difference between copy and move is that<br>
  after a copy the two objects have the same value<br>
  whereas after a move the source object is not required to have its original value
- move can be used when the source object will not be used again
- Copy is the conventional meaning of x=y ; <br>
  that is, the effect is that the values of x and y are<br>
  both equal to y ’s value before the assignment
- Move leaves x with y ’s former value and y with some moved-from state. <br>
  For the most interesting cases, containers, that moved-from state is ‘‘empty.’’    
