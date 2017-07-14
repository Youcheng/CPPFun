#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>

std::mutex mutexX;
std::mutex mutexY;

void threadAFunc() {
    while(true) {
        mutexX.lock();
        std::cout << "mutexX locked" << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);
        if (! mutexY.try_lock()) {
            std::cout << "unable to do threadA job" << std::endl;
            mutexX.unlock();
            continue;
        } else {
            // our target is to get here after locking mutexX and mutexY if possible.
            std::cout << "doing threadA job" << std::endl;
            mutexX.unlock();
        }
    }
}

void threadBFunc() {
    while(true) {
        mutexY.lock();
        std::cout << "mutexY locked" << std::endl;
        using namespace std::chrono_literals;
        std::this_thread::sleep_for(100ms);
        if (! mutexX.try_lock()) {
            std::cout << "unable to do threadB job" << std::endl;
            mutexY.unlock();
            continue;
        } else {
            // our target is to get here after locking mutexX and mutexY if possible.
            std::cout << "doing threadB job" << std::endl;
            mutexY.unlock();
        }
    }
}


// The reason why it is livelock is because we kept lock/unlock both mutexes
// but we cannot get to do the real work in either thread which requires locking
// both mutexA and mutexB successfully.

int main()
{
    std::thread threadA(threadAFunc);
    std::thread threadB(threadBFunc);

    threadA.join();
    threadB.join();
}