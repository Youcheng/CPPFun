constexpr objects
-----------------
    * are const and are initialized with values known during compilation
  
constexpr functions
-------------------
    * can produce compile-time results when called with arguments
      whose values are known during compilation. 
      If the values of the arguments you pass to a constexpr
      function in such a context are known during compilation, 
      the result will be computed during compilation. 
      If any of the arguments’ values is not known during compilation, 
      your code will be rejected.
      
    * When a constexpr function is called with one or more values that are
      not known during compilation, it acts like a normal function, computing
      its result at runtime.    
    
const objects
-------------
    * need not be initialized with values during compilation