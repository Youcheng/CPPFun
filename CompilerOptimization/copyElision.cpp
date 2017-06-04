#include <iostream>

struct C {
    C() { std::cout << "Create " << this << std::endl; }
    C(const C& rhs) { std::cout << "A copy was made." << std::endl  << "from " << &rhs << " to " << this << std::endl; }

    ~C() { std::cout << "Destruct " << this << std::endl; }
};

C f() {
    return C();
}

int main() {
    std::cout << "Hello World!\n";
    C obj = f();
    return 0;
}

/*
 * [ylin@cr-ylin-001 CPPLearning (master)]$ /opt/cresearch/bin/g++ -std=c++14 -fno-elide-constructors returnValueOptimization.cpp -o returnValueOptimization.exe
 * [ylin@cr-ylin-001 CPPLearning (master)]$ ./returnValueOptimization.exe
 * Hello World!
 * Create 0x7ffc7c770dff
 * A copy was made.
 * from 0x7ffc7c770dff to 0x7ffc7c770e2f
 * Destruct 0x7ffc7c770dff
 * A copy was made.
 * from 0x7ffc7c770e2f to 0x7ffc7c770e2e
 * Destruct 0x7ffc7c770e2f
 * Destruct 0x7ffc7c770e2e
 */

/*
 * [ylin@cr-ylin-001 CPPLearning (master)]$ /opt/cresearch/bin/g++ -std=c++14 returnValueOptimization.cpp -o returnValueOptimization.exe
 * [ylin@cr-ylin-001 CPPLearning (master)]$ ./returnValueOptimization.exe
 * Hello World!
 * Create 0x7ffc8fae567f
 * Destruct 0x7ffc8fae567f
 */