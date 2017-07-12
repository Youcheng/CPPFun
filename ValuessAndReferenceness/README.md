# type of an expression
- T
- rvalue reference to T
- lvalue reference to T

# valueness of an expression
- An expression is either lvalue or rvalue.
- Criteria:<br>
  1. If you can take the address of an expression, the expression is an lvalue.
  2. If the type of an expression is an lvalue reference (e.g., T& or const T&, etc.), that expression is an lvalue. 
  3. Otherwise, the expression is an rvalue.

# referenceness of an expression
- lvalue reference
- rvalue reference
- universal reference <- If a variable or parameter is declared to have type T&& for some deduced type T, that variable or parameter is a universal reference.

# connection between valueness and type of an expression
- valuesness of an expression is independent of its type<br>
  int x; x is lvalue of type, int<br>
  10; 10 is rvalue of type, int<br>
  Widget&& var1 = makeWidget(); var1 is lvalue of type, rvalue reference to Widget<br>
  static_cast<Widget&&>(var1); this whole expression is rvalue of type, rvalue reference to Widget<br>

# reference bind
- bind rvalue reference only to rvalue
- bind lvalue reference to either lvalue or rvalue
- bind universal reference to either lvalue or rvalue


# reference collapsing
- Reference collapsing is the mechanism that leads to universal references sometimes resolving to lvalue references and sometimes to rvalue references. 

# rule of reference collapsing
- rvalue reference to rvalue reference collapses to rvalue reference
- other reference to reference collapses to lvalue reference

# contexts in which reference collapsing occurs
- template instantiation
- definition of auto variable
- typedef formation of use
- use of decltype

# mechanism how universal reference works
- type deduction for universal reference   
- reference collapsing
- example<br>
  template\<typename T> void f(T&& param);<br>
  1. f(10); -> 10 is rvalue, T is deduced to be int --> f(int&&) 
  2. int x; f(x) -> x is lvalue, T is decued to int& --> f(int& &&) --> f(int&)
  3. int&& r1 = 10; f(r1) -> r1 is lvalue of type, int&&--> reference-stripping --> lvalue, T is deduced to int& --> f(int& &&) --> f(int&)
  4. int x; int& r2 = x; f(r1) -> r2 is lvalue of type, int&--> reference-stripping --> lvalue, T is deduced to int& --> f(int& &&) --> f(int&)
- example<br>
  Widget&& var1 = someWidget;<br>
  auto&& var2 = var1; --> var is lvalue of type, Widget&&--> reference-stripping --> lvalue, auto is deduced to Widget& --> auto&&--> Widget& && ->> Widget&<br>