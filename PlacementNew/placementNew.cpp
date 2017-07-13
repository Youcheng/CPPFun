#include <iostream>


int main() {
    int a = 5; // stack
    int* b = new int(10); // heap

    std::cout << "&a: " << &a << " a: " << a << std::endl;
    std::cout << "b: " << b << " *b: " << *b << std::endl << std::endl;

    int* mem =  new (&a) int(1004); // stack
    int* mem1 = new (b) int(2005); // heap

    std::cout << "&a: " << &a << " a: " << a << " mem: " << mem << " " << *mem << std::endl;
    std::cout << "b: " << b << " *b: " << *b << " mem1: " << mem1 << " " << *mem1 << std::endl;


}
