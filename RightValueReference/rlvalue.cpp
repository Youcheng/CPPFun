#include <iostream>

int foobar() {
    return 3;
}

int &foo(int* p_) {
    return *p_;

}

int main() {

// lvalues:
//
    int i = 42;
    i = 43;
    int *p = &i; // ok, i is an lvalue, cause you can take the address of it
    std::cout << "p: " << p << std::endl;

    foo(p) = 42;
    int *p1 = &(foo(p)); // ok, foo() is an lvalue, cause you can take the address of it
    std::cout << "p1: " << p1 << std::endl;

// rvalues:
//
    int foobar();
    int j = 0;
    j = foobar(); // ok, foobar() is an rvalue
    //int *p2 = &foobar(); // error, cannot take the address of an rvalue
    j = 42; // ok, 42 is an rvalue

}