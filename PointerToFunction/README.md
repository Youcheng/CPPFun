# function pointer variable
- bool lengthCompare(const string &, const string &); // // compares lengths of two strings<br>

  // pf points to a function returning bool that takes two const string references<br>
  bool (*pf)(const string &, const string &); // uninitialized<br>

  pf = lengthCompare; // pf now points to the function named lengthCompare<br>
  pf = &lengthCompare; // equivalent assignment: address-of operator is optional<br>

  bool b1 = pf("hello", "goodbye"); // calls lengthCompare<br>
  bool b2 = (*pf)("hello", "goodbye"); // equivalent call<br>
  bool b3 = lengthCompare("hello", "goodbye"); // equivalent call<br>

# function pointer parameter
- // third parameter is a function type and is automatically treated as a pointer to function<br>
  void useBigger(const string &s1, const string &s2, bool pf(const string &, const string &));<br>

  // equivalent declaration: explicitly define the parameter as a pointer to function<br>
  void useBigger(const string &s1, const string &s2, bool (*pf)(const string &, const string &));<br>

  // automatically converts the function lengthCompare to a pointer to function<br>
  useBigger(s1, s2, lengthCompare);<br>

# alias for function type and pointer to function type
- bool lengthCompare(const string &, const string &);

- // Func and Func2 have function type<br>
  typedef bool Func(const string&, const string&);<br>
  typedef decltype(lengthCompare) Func2; // equivalent type<br>

- // FuncP and FuncP2 have pointer to function type<br>
  typedef bool(*FuncP)(const string&, const string&);<br>
  typedef decltype(lengthCompare) *FuncP2; // equivalent type<br>

- // equivalent declarations of useBigger using type aliases<br>
  void useBigger(const string&, const string&, Func);<br>
  void useBigger(const string&, const string&, FuncP2);<br>

# return a pointer to function, but cannot return function type
- bool func(const string&, const string&);
- using F = bool (const string&, const string&); <br>
  using FP = bool (*) (const string&, const string&); <br>
- F f1(int); // error: F is a function type; f1 can't return a function<br>
  FP f1(int); // ok: PF is a pointer to function; f1 returns a pointer to function<br>
  F* f1(int); // ok: explicitly specify that the return type is a pointer to function<br>
  auto f1(int) -> bool (*) (const string&, const string&) <br>
  decltype(func)* f1(int); <br>