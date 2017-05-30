Exceptions
- let us separate problem detection(throw) from problem resolution(catch)


Stack Unwinding
- when an exception is thrown, execution of current function is suspended
  and the search for a matching catch clause begins.
- if the throw appears inside a try block
  {
     the catch clauses associated with that try are examined.
     if a matching catch is found
        the exception is handled by that catch;
     else
     {
        if the try was nested inside another try,
           the search continues thru the catch clauses of the enclosing trys;
        else
           the current function is exited, and the search continues in the calling function;
     }
  }
  else
  {
     the current function is exited, and the search continues in the calling function
     if the call to that function that threw is in a try block
     {
        the catch clauses associated with that try are examined.
        if a matching catch is found,
           the exception is handled by that catch;
        else
           if the try was nested inside another try,
              the search continues thru the catch clauses of the enclosing trys;
           else
               the current function is exited, and the search continues in the calling function;
     }
     else
     {
        ...
        ...
        if the main function is exited without having found a matching catch,
           the program calls the library terminate function to stop the execution of the program.
     }
  }
- when a block is exited during the stack unwinding, the compiler guarantees that objects created in that
  block are properly destroyed.