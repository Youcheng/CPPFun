#include <iostream>
#include <string>

class Foo {
public:
    Foo() { std::cout << __FUNCTION__ << " creating an object at " << this <<std::endl;}
    ~Foo() { std::cout << __FUNCTION__ << " destroying an object at " << this << std::endl;}

    int m = 5;
};

int main() {

    Foo* f = new Foo; // allocate memory on the heap
    Foo* g = f;

    std::cout << f->m << std::endl;

    // delete f; // leaked objects
    // delete g;  // double deletion after deleting f already

/*  premature deletion
    delete f;
    std::cout << f->m << std::endl;
    std::cout << g->m << std::endl;*/

}
