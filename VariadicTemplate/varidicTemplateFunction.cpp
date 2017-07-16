#include <iostream>
#include <string>
#include <utility>

template<typename T>
void findLValueRValue(const T&& tmp) {
    std::cout << "rvalue" << std::endl;
}

template<typename T>
void findLValueRValue(T& tmp) {
    std::cout << "lvalue" << std::endl;
}


void foo() {
    std::cout << __FUNCTION__ << std::endl;
}

template <typename T, typename ... Args>  // Args, template parameter pack
void foo(T&& first, Args&&... rest) { // rest, function parameter pack

    // we need the parameter, T first, to extract one parameter a time from the function parameter pack
//    std::cout << "number of parameters in template parameter pack: " << sizeof...(Args) << std::endl
//              << "number of parameters in function parameter pack: " << sizeof...(rest) << std::endl;
//    std::cout << "first value in the function parameter pack " << first << " the rest are ...." << std::endl;

    findLValueRValue(std::forward<T>(first));

    foo(std::forward<Args>(rest)...);
}


int main() {
    std::string s("sdfds");
    foo(1, std::string(), s);
}