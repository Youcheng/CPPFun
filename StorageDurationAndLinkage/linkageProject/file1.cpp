#include "file1.hpp"
#include <iostream>

// it is definition of x
int x = 99;


// static means y will not be accessible from other
// translation unit
static int y = 55;



extern const int z = 765;


int f() {
    std::cout << __FILE__ << " " << __FUNCTION__ << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    return 100;
}

