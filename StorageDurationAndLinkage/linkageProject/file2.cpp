#include "file2.hpp"
#include <iostream>

static int y = 66;


void g() {
    std::cout << __FILE__ << " " << __FUNCTION__ << std::endl;
    std::cout << "y = " << y << std::endl;

    x = f();
}

