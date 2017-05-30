#include <exception>
#include <iostream>
#include <signal.h>
#include <unistd.h>

class Foo {
public:
    Foo() = default;



   ~Foo() {
       try {
           throw std::runtime_error("Thrown from ~Foo.");
       }
       catch(std::exception &e) {
           std::cout << "caught " << e.what() << std::endl;
       }
    }

/*
    ~Foo() {
        throw std::runtime_error("Thrown from ~Foo.");
        //warning: throw will always call terminate()
    }
*/
};

void f(int tmp) {
    Foo f;
    if (tmp == 3) {
        // During stack unwinding, an exception has been raised but is not yet handled.
        // If a new exception is thrown during stack unwinding and not caught in the function
        // that threw it, terminate is called.
        // Because destructors may be invoked during the stack unwinding, they should never throw
        // exceptions that the destructor itself doe not handle. Otherwise the program will be terminated.
        throw std::runtime_error("Throw from f(int tmp)");
    }
}


void sighandler(int signum)
{
    printf("Process %d got signal %d\n", getpid(), signum);
    signal(signum, SIG_DFL);
    kill(getpid(), signum);
}



int main() {

    signal(SIGSEGV, sighandler);

    try {
        f(3);
        int *ip = nullptr;
        std::cout << *ip << std::endl;
        std::cout << "end of main try" << std::endl;
    }catch(std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout <<  "end of main" << std::endl;

    return 0;
}