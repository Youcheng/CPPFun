Reference Collapsing occurs in four contexts:

1) template instantiation
2) auto type generation, creation
3) use of typedefs and alias declarations
4) decltype

reference#1 to reference#2 -> reference#3
If either of reference#1 or reference#2 is an lvalue reference,
then reference#3 is an lvalue reference.
Otherwise reference#3 is an rvalue reference.

Examples:

template<typename T>
void func(T&& param);  // param is a universal reference

Widget w;
func(w); --> deduced type for T is Widget& --> void func(Widget& && param);
         --> reference collapsing --> void func(Widget& param); --> param is a lvalue reference.


========= implementation of std::forward =====
template<typename T>
T&& forward(typename remove_reference<T>::type& param)
{
  return static_cast<T&&>(param);
}

========== usage of std::forward =========
template<typename T>
void f(T&& fParam) // fParam is universal reference
{
  ...
  someFunc(std::forward<T>(fParam));
}

------------------------
Widget w;
f(w);
w, a lvalue, passed to std::forward will return an lvalue reference

-->deduced type for T is Widget&
-->
   Widget& && forward(typename remove_reference<Widget&>::type& param)
   {
     return static_cast<Widget& &&>(param);
   }
--> reference collapsing
    Widget& forward(Widget& param)
    {
      return static_cast<Widget&>(param);
    }

------------------------
f(Widget());
Widget(), a rvalue, passed to std::forward will return an rvalue reference
-->deduced type for T is Widget
-->
   Widget && forward(typename remove_reference<Widget>::type& param)
   {
     return static_cast<Widget&&>(param);
   }
--> reference collapsing
    Widget&& forward(Widget& param)
    {
      return static_cast<Widget&&>(param);
    }