#define LOG(message) std::cout << message << std::endl \
                               << "Current function: " << __FUNCTION__ << std::endl \
                               << "Line: " << __LINE__ << std::endl;


#include <iostream>

int main() {
    int a;
    LOG("yeah!!" << a);
}


