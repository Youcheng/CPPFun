#include <mutex>
#include <thread>
#include <iostream>

std::mutex mutexX;
std::mutex mutexY;

void threadAFunc() {
    while(true) {
        mutexX.lock();

        if (! mutexY.try_lock()) {
            std::cout << "unable to do threadA job" << std::endl;
            mutexX.unlock();
            continue;
        } else {
            std::cout << "doing threadA job" << std::endl;
            mutexX.unlock();
        }
    }
}

void threadBFunc() {
    while(true) {
        mutexY.lock();

        if (! mutexX.try_lock()) {
            std::cout << "unable to do threadB job" << std::endl;
            mutexY.unlock();
            continue;
        } else {
            std::cout << "doing threadB job" << std::endl;
            mutexY.unlock();
        }
    }
}


int main()
{
    std::thread threadA(threadAFunc);
    std::thread threadB(threadBFunc);

    threadA.join();
    threadB.join();
}