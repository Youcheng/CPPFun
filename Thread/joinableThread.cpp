#include <iostream>
#include <thread>

int main() {
    int i;
    {
        std::thread t(
                []() {
                    std::cout << "sleeping..." << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }
        );

        // t is still joinable at this point,
        // if the destructor for a joinable thread is invoked,
        // execution of the program is terminated.

        // terminate called without an active exception
        // Signal: SIGABRT (Aborted)
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

}