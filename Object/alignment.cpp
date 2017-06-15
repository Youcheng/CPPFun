#include <iostream>

struct Y {
    char a;
    char b;
    char c;
    char d;
    char e;
    char f;
}; // size: 6, alignment: 1

// objects of type X must be allocated at 4-byte boundaries
struct X {
    int n;  // size: 4, alignment: 4
    char c; // size: 1, alignment: 1
    int m;   // size: 4, alignment: 4
    char e; // size: 1, alignment: 1
}; // size: 16, alignment: 4

struct W {
    int n;  // size: 4, alignment: 4
    char a; // size: 1, alignment: 1
    X x; // size: 16, alignment: 4
    char i; // size: 1, alignment: 1
}; // size: 28, alignment: 4


struct alignas(8) B
{
    char sse_data[4];
}; // size: 8, alignment: 8

struct H {
    B b;  // size: 8, alignment: 8
    char a;
}; // size: 16, alignment: 8

int main()
{
    std::cout << "sizeof(Y) = " << sizeof(Y)
              << " alignof(Y) = " << alignof(Y) << '\n';
    std::cout << "sizeof(X) = " << sizeof(X)
              << " alignof(X) = " << alignof(X) << '\n';
    std::cout << "sizeof(W) = " << sizeof(W)
              << " alignof(W) = " << alignof(W) << '\n';
    std::cout << "sizeof(B) = " << sizeof(B)
              << " alignof(B) = " << alignof(B) << '\n';
    std::cout << "sizeof(H) = " << sizeof(H)
              << " alignof(H) = " << alignof(H) << '\n';
}