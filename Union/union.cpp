#include <iostream>

union foo {
    char i;
    double j;
};

int main() {
    foo f;
    std::cout << "sizeof(f)" << sizeof(f) << std::endl
              << "address of f " << &f << std::endl;

    f.i = 'c';
    std::cout << f.i << std::endl;
}