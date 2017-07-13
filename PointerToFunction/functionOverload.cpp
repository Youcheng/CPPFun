#include <iostream>

// the number or types of the parameters in the functions differ.
// not the return type differs
int func(int a, int b) {
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}

//void func(int a, int b) {
//    std::cout << __FUNCTION__ << std::endl;
//}

int main() {
    func(1, 2);
}