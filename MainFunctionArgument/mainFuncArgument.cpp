#include <iostream>
#include <cstdlib>

void foo () {
    std::cout << __FUNCTION__ << std::endl;
}


class fooClass {
public:
    fooClass() {
        std::cout << __FUNCTION__ << std::endl;
    }

    ~fooClass(){
        std::cout << __FUNCTION__ << std::endl;
    }
};

int main(int argc, char* argv[]) {
    std::cout << "argc " << argc << std::endl;
    for(int i = 0; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    fooClass fc;
    static fooClass sfc;

    abort();
    // Process finished with exit code 134 (interrupted by signal 6: SIGABRT
    // The program is terminated without destroying any object.


    exit(EXIT_FAILURE);
    // fc is not destroyed
    // ~fooClass, Objects with static storage duration are destroyed
    // Process finished with exit code 1

    return 0;
}