#include <iostream>

int main() {
    int a = 5;
    int* b = new int(10);

    std::cout << "&a: " << &a << " a: " << a << std::endl;
    std::cout << "b: " << b << " *b: " << *b << std::endl;

    int* mem =  new (&a) int(500);
    int* mem1 = new (b) int(1000);

    std::cout << "&a: " << &a << " a: " << a << " mem: " << mem << std::endl;
    std::cout << "b: " << b << " *b: " << *b << " mem1: " << mem1 << std::endl;
}
