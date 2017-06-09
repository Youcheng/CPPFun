#include <iostream>
#include <string>
#include <thread>
#include <mutex>


std::mutex mu;

class foo {
public:
    foo() = default;
    foo(int a) : m_a(a) { std::cout << this << " in constructed from thread " << std::this_thread::get_id() << std::endl; }
    foo(const foo& rhs) {
        std::cout << "foo:foo(const foo&)" << std::endl;
        std::cout << "from " << &rhs << " to " << this << std::endl;
    }
    ~foo() { std::cout << this << " is destroyed from thread " << std::this_thread::get_id() << std::endl; }

    int m_a = 1;
};

// it seems this object has to be defined outside of
// the main function in order to have each thread
// to create a copy of it.
// Also I don't see the copy constructor gets called
// to create that thread_local copy.

static thread_local foo f(5);

int main() {

    std::thread t1([]() {
                            std::lock_guard<std::mutex> lock(mu);
                            std::cout << "   "  << std::this_thread::get_id()<< " printing " << f.m_a
                                        << std::endl;
                        });


    {
        std::lock_guard<std::mutex> lock(mu);
        std::cout << "    " << std::this_thread::get_id()<< " printing " << f.m_a
                  << std::endl;
    }

    t1.join();
}
