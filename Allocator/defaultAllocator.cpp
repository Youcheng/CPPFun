#include <iostream>
#include <memory>

class foo {
public:
    foo() { std::cout << __FUNCTION__ << " " << this << std::endl; }
    foo(int m) : m_(m) { std::cout << __FUNCTION__ << " " << this << std::endl; }
    ~foo() { std::cout << __FUNCTION__ << " " << this << std::endl; }

    int m_;
};


int main() {
    foo example;
    std::cout << &example << std::endl;

    std::allocator<foo> a1;
    foo* p = a1.allocate(3);

    a1.construct(p, 5);
    a1.construct(p+1, 6);
    a1.construct(p+2, 7);

    std::cout << p[0].m_ << std::endl;
    std::cout << p[1].m_ << std::endl;
    std::cout << p[2].m_ << std::endl;

    a1.destroy(p);
    a1.destroy(p+1);
    a1.destroy(p+2);

    a1.deallocate(p, 3);
}