How type deduction works
========================

sample code
------------
    template<typename T>
    void f(ParamType param);
    
    f(expr); // call f with some expression
        

3 cases to deduce T and ParamType
---------------------------------- 
    During compilation, compilers use expr to deduce two types:
    one for T and one for ParamType.
        
    The type deduced for T is dependent not just
    on the type of expr, but also on the form of ParamType.

1) ParamType is a pointer or reference type   
   * If expr's type is a reference, ignore the reference part
   * pattern-match expr's type against ParamType to determine T

````
   template<typename T>
   void f(T& param);
   
   int x =27;<br>
   f(x)<br>
````
   expr's type is **int**, which doesn't have reference part;<br>
   pattern-match **int** against **T&** to determine T=**int**, param's type=**int&**<br>




````
   const int& rx =x;<br>
   f(rx)<br>
````   
   expr's type is **const int&**, ignore the reference to get **const int**;<br>
   pattern-match **const int** against **T&** to determine T= **const int**, param's type=**const int&**



2) ParamType is a universal reference
   * if expr is lvalue, both T and ParamType are deduced to lvalue reference
   * if expr is rvalue, 1) rule apply
````   
   template<typename T>
   void f(T&& param);

   int x = 27
   f(x)
````
   expr is lvalue, T = **int&** and param's type = **int&**


````   
   const int& rx = x
   f(rx)
````
   expr is lvalue, T = **int&** and param's type = **int&**

````   
   f(27)
````
   expr is rvalue, expr's type is not reference, pattern-match **int** against **T&&**, T=**int**, param's type=**int&&**



3) ParamType is neither a pointer nor a reference
   * If expr's type is a reference, ignore the reference part
   * If after ignoring expr's reference-ness, expr was const reference to sth, ignore that const too.
````
   template<typename T>
   void f(T param);
   
   int x = 27
   f(x)
````   
   T=**int**, param's type=**int**

````   
   const int& rx = x
   f(rx)
````   
   ignore reference-ness and const-ness to get int, T=**int**, param's type=**int**<br>
   param is an object independent of rx --  a copy of rx.

````   
   const char * const ptr = "Fun with pointers";// ptr is const pointer to const object
   f(ptr)
````   
   ignore const-ness to get **const char\*,** T=**const char\*,** and param's type = **const char\*,**