

# std::forward implementation
 * template<class S>
 * S&& forward(typename remove_reference\<S>::type& arg) noexcept
 * {
 *  return static_cast<S&&>(arg);
 * }
 *


#std::move implementation
 * template\<class T>
 * typename remove_reference\<T>::type&&
 * std::move(T&& a) noexcept
 * {
 *  typedef typename remove_reference\<T>::type&& RvalRef;
 *  return static_cast\<RvalRef>(a);
 * }
 * This determines which constructor(copy[lvalue reference], move[rvalue reference to rvalue]) will be called
  
# binding between valueness and referenceness
- bind rvalue reference only to rvalue
- bind lvalue reference to either lvalue or rvalue<br>
        bind lvalue reference to rvalue only when the lvalue reference is declared as a reference-to-const
- bind universal reference to either lvalue or rvalue


# std::move
 * unconditional cast to an rvalue
  
# std::forward
 * conditional cast to an rvalue only if its argument was initialized with an rvalue
 * retain its original valueness of the 