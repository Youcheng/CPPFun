// An exception might occur while processing a constructor initializer.
// Constructor initializers execute before the constructor body is entered.
// A catch inside the constructor body cannot handle such an exception.

// To handle an exception from a constructor initializer, we mush write the
// constructor as a function try block

#include <iostream>
#include <exception>
#include <chrono>
#include <thread>

struct MyException: public std::exception {
    const char* what();
};

const char* MyException::what() {
    return "My exception";
}

class Foo{
public:
    Foo(int tmp) {
        if (tmp == 3)
            throw MyException();
        else
            throw std::runtime_error("other exception");
    }

};


class Xoo {
public:
    Xoo(int tmp);
    Foo f;
};

Xoo::Xoo(int tmp)
    try:
        f(Foo(tmp)) {}
    catch(MyException &e) {
        std::cout << "Xoo:Xoo() catch: " << e.what() << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(2s);
    }
    catch(...) {
        std::cout << "Xoo:Xoo() catch: ..." << std::endl;
    }


/*
Xoo::Xoo(int tmp) : f(Foo(tmp)){}
*/

void f(int tmp) {
    Xoo x(tmp);
}

int main() {
    try {
        f(3);
    } catch (MyException &e) {
        std::cout << "Main catch: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Main catch: ..." << std::endl;
    }

    try {
        f(4);
    } catch (MyException &e) {
        std::cout << "Main catch: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Main catch: ..." << std::endl;
    }

    std::cout << "end of main" << std::endl;
}