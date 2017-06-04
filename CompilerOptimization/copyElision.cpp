#include <iostream>

struct C {
    C() { std::cout << "Create " << this << std::endl; }
    C(const C& rhs) { std::cout << "A copy was made." << std::endl  << "from " << &rhs << " to " << this << std::endl; }
    C(const C&& rhs) { std::cout << "Moved from " << std::endl  << "from " << &rhs << " to " << this << std::endl; }
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
 * [ylin@cr-ylin-001 CPPLearning (master)]$ /opt/cresearch/bin/g++ -std=c++11 -fno-elide-constructors returnValueOptimization.cpp -o returnValueOptimization.exe
 * [ylin@cr-ylin-001 CPPLearning (master)]$ ./returnValueOptimization.exe
 * Hello World!
 * Create 0x7ffd99681750
 * Moved from
 * from 0x7ffd99681750 to 0x7ffd99681790
 * Destruct 0x7ffd99681750
 * Moved from
 * from 0x7ffd99681790 to 0x7ffd99681780
 * Destruct 0x7ffd99681790
 * Destruct 0x7ffd99681780
 */

/*
 * [ylin@cr-ylin-001 CPPLearning (master)]$ ./returnValueOptimization.exe
 * Hello World!
 * Create 0x7ffdce1ad140
 * Destruct 0x7ffdce1ad140
 */