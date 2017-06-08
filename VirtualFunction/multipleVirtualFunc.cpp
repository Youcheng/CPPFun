#include <iostream>

struct base {
    virtual void foo() {
        std::cout << "base::foo()" << std::endl;
        helper();  // dynamic dispatch
    }

    virtual void helper() {
        std::cout << "base::helper()" << std::endl;
    }
};

struct derived1 : public base {
    void foo() {
        std::cout << "derived1::foo()" << std::endl;
        helper();
    }
    void helper() override { std::cout << "derived1::helper()" << std::endl; }
};


struct derived2 : public base {
    void foo() {
        std::cout << "derived2::foo()" << std::endl;
        helper();
    }
    void helper() override { std::cout << "derived2::helper()" << std::endl; }
};


int main() {
    base * pd1 = new derived1;
    base * pd2 = new derived2;

    pd1->foo();
    pd2->foo();

    base* pb = new base;
    pb->foo();
}