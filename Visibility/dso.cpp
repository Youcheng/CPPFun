#include "dso.h"
#include <iostream>

void publicFunction()
{
    std::cout << "publicFunction()" << std::endl;
}

void privateFunction()
{
    std::cout << "privateFunction()" << std::endl;
}

