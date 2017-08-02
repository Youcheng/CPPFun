From [TemplateTypeDeduction](../TemplateTypeDeduction/templateTypeDeduction.md) case 2
- If expr at call site, move(expr), is lvalue, T  and T&& will be deduced to lvalue reference
- If expr at call site, move(expr), is rvalue, ignoring the reference part to deduce T and T&&


std::move
---------
std::move doesn’t move anything.
At runtime, it does anything at all.
std::move unconditionally casts its argument to an rvalue.

It guarantees that std::move truly returns an rvalue reference,
and that’s important, because rvalue references returned from functions are rvalues.
Thus, std::move casts its argument to an rvalue, and that’s all it does.

```
// std:move implementation
        template<typename T>
        typename remove_reference<T>::type&& move(T&& param)
        {
            using ReturnType = typename remove_reference<T>::type&&; // it has to be rvalue reference
            return static_cast<ReturnType>(param);
        }

const std::string text;
std::string s(std::move(text));

Which functions to be called?

1)
text is lvalue const std::string,
T will be deduduced to lvalue reference, T = const std::string &,
T&& is collapsed to const std::string &

template instantiation --->
        template<typename const std::string &>
        const std::string&& move(const std::string & param)
        {
            using ReturnType = typename remove_reference<const std::string &>::type&&; // it has to be rvalue reference
            return static_cast<const std::string&&>(param);
        }

2)
std::string s(const std::string&&) --> which std::string constructor to call?
move ctor will take string&& without const.
Then copy ctor is called becuase we can bind lvalue-reference-to-const to rvalue.
Therefore even though we cast to an rvalue but the copy ctor is called instead.

class string {
public:
...
string(const string& rhs); // copy ctor
string(string&& rhs); // move ctor
...
};
```


std::forward
------------
std::forward doesn’t forward anything.
At runtime, it does anything at all.
std::forward performs this cast only if its argument was initialized with an rvalue.
