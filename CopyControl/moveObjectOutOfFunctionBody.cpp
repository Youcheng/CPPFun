#include <iostream>

class xoo {
public:
    xoo() { std::cout << "defaultConstructor " << this << std::endl; }
    ~xoo() { std::cout << "destructor " << this << std::endl; }

    xoo(const xoo& rhs) { std::cout << "copyConstructor " << "from " << &rhs << " to " << this << std::endl; }
    xoo(xoo&& rhs) { std::cout << "moveConstructor " << "from " << &rhs << " to " << this << std::endl; }

    xoo& operator=(const xoo& rhs) { std::cout << "copyAssignment " << "from " << &rhs << " to " << this << std::endl; }
    xoo& operator=(xoo&& rhs) { std::cout << "moveAssignment " << "from " << &rhs << " to " << this << std::endl; }
};

xoo ident(xoo arg) {
    std::cout << __FUNCTION__ << " " << &arg << std::endl;
    return arg;
}

int main() {
    xoo x1;
    // defaultConstructor 0x7ffdf13577cd(x1)


    // two bad objects were created during this process,
    // arg
    // temporary object
    x1 = ident(x1);
    //  copyConstructor from 0x7ffdf13577cd(x1) to 0x7ffdf13577cf(arg)
    //  ident 0x7ffdf13577cf(arg)

    // MOVE OBJECT OUT OF FUNCTION BODY
    //  moveConstructor from 0x7ffdf13577cf(arg) to 0x7ffdf13577ce(temporary object)
    //  moveAssignment from 0x7ffdf13577ce(temporary object) to 0x7ffdf13577cd (x1)
    //  destructor 0x7ffdf13577ce(temporary object)
    //  destructor 0x7ffdf13577cf(arg)

    xoo x2;
    //  defaultConstructor 0x7ffdf13577cc(x2)

    x1 = x2;
    //  copyAssignment from 0x7ffdf13577cc(x2) to 0x7ffdf13577cd(x1)

    // destructor 0x7ffdf13577cc(x1)
    // destructor 0x7ffdf13577cd(x2)

}