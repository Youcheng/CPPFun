#include <iostream>
#include <type_traits>
#include <typeinfo>


int main() {
    int i = 5;
    int &j = i;
    j =6;
    static_assert(std::is_reference<int &>::value);

}