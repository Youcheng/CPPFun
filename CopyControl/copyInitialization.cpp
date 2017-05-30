#include <iostream>
#include <string>

/* copy initialization
 #1 define f4 using an =
 #2 f1 is passed as an argument to a parameter of nonreference type
 #3 return an object from an function that has a nonreference type, however it is optimized by compiler here
 #4 brace initialize the elements in an arrary, however it is optimized by compiler here
 #5 brace initialize the members of an aggregate class, however it is optimized by compiler here


 */

class Foo {
public:
    Foo() { std::cout << "Foo:Foo()" << std::endl; }
    Foo(std::string s):m_s(s) { std::cout << "Foo:Foo(std::string)" << std::endl; }
    Foo(const Foo &f) { std::cout << "Foo:Foo(const Foo&) " << std::endl; }
   ~Foo() { std::cout << "Foo:~Foo()" << std::endl; }

    std::string m_s;
};

// aggregate class
// all of its data members are public
// does not define any constructor
// has no in-class initializer
// has no base class or virtual function
struct Data {
    int val;
    Foo f;
};

Foo func() {
    Foo f("func");
    std::cout << f.m_s << std::endl;
    std::cout << &f << std::endl;
    return f; // return an object from an function that has a nonreference type, however it is optimized by compiler here
}

Foo* func1(Foo* & pr) {
    pr = new Foo("func1");
    std::cout << pr << std::endl;
    return pr;
}

void func2(Foo f) {

}


int main() {

    Foo f1;
    Foo f2("test");
    Foo f3(f1); // f1 is passed as an argument to a parameter of nonreference type
    Foo f4 = f2;  // define f4 using an =

    std::cout << "--------" << std::endl;

    Foo f5 = func();
    std::cout << f5.m_s << std::endl;
    std::cout << &f5 << std::endl;

    std::cout << "///////" << std::endl;

    Foo f6[2] = {Foo("a"), Foo("b")}; // brace initialize the elements in an array, however it is optimized by compiler here
    std::cout << f6[0].m_s << std::endl;
    std::cout << f6[1].m_s << std::endl;

    std::cout << "++++++++" << std::endl;
    Data d = {1, Foo("c")}; // brace initialize the members of an aggregate class, however it is optimized by compiler here

    std::cout << "@@@@@@@@@@" << std::endl;
    Foo f7 = std::string("abc"); // compiler bypass the copy constructor

}