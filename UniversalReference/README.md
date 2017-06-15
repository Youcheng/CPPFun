T&& has two different meanings.
One is rvalue reference, which is bound to rvalues.
The other is either rvalue reference or lvalue reference, which is virtually bound to anything.

Universal reference arises in two contexts, both of which has the presence of type deduction.
#1 function template parameters
template<typename T>
void f(T&& param);  // param is a universal reference. Type of param is being deduced.

Widget w; f(w);  // w(lvalue) is passed to f; param's type is Widget& (lvalue reference)
f(std::move(w)); // std::move(w)(rvalue) is passed to f; param's type is Widget&& (rvalue reference)

#2 auto declarations
auto&& var2 = var1; // var2 is a universal reference. Type of var2 is being deduced.


Examples,

1)
template<typename T>
void f(std::vector<T>&& param); // param is a rvalue reference since it is not T&&

2)
template<typename T>
void f(const T&& param);  // param is a rvalue reference because the const qualifer

3)
template<typename T>
class vector {
public:
  void push_back(T&& x); // x is rvalue reference since push_back cannot exist without
                         // a particular vector instantiation for it
                         // and the type of that instantiation fully determines the declartion for push_back
                         // vector<Widget> v; --> void push_back(widget&& x); x is rvalue reference
  ...
};