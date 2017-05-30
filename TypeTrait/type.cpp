#include <iostream>
#include <ios>
#include "../../../../../opt/cresearch/vendor/gcc/6.3.0/include/c++/6.3.0/type_traits"

// checks if a type has a default constructor
// std::is_constructible


class Foo
{

};

class Foo1 {
public:
    Foo1() noexcept {}
};

class Foo2 {
public:
    Foo2() = default;
};

int main() {
    std::cout << std::boolalpha
              << std::is_default_constructible<Foo>::value << std::endl
              << std::is_trivially_default_constructible<Foo>::value << std::endl
              << std::is_nothrow_default_constructible<Foo>::value << std::endl
              << std::endl;

    std::cout << std::boolalpha
              << std::is_default_constructible<Foo1>::value << std::endl
              << std::is_trivially_default_constructible<Foo1>::value << std::endl
              << std::is_nothrow_default_constructible<Foo1>::value << std::endl
              << std::endl;

    std::cout << std::boolalpha
              << std::is_default_constructible<Foo2>::value << std::endl
              << std::is_trivially_default_constructible<Foo2>::value << std::endl
              << std::is_nothrow_default_constructible<Foo2>::value << std::endl
              << std::endl;
}