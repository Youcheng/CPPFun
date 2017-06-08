#include <condition_variable>
#include <iostream>
#include <thread>
#include <chrono>

std::mutex mutex_;
std::condition_variable condVar;
bool dataReady= false;
int timesChecked = 0;

void doTheWork(){
    std::cout << "Processing shared data." << std::endl;
}
void waitingForWork(){
    while(1) {
        std::unique_lock<std::mutex> lck(mutex_);
        condVar.wait(lck, [] {
            std::cout << "Worker: Waiting for work. Times chekced: " << timesChecked++ << ". Value of dataReady: " << dataReady << std::endl;
            return dataReady;
        });
        doTheWork();
        std::cout << "Work done." << std::endl;
        dataReady = false;
    }
}
void setDataReady(){
    while(1) {
        std::this_thread::sleep_for(std::chrono::nanoseconds(5));
        std::lock_guard<std::mutex> lck(mutex_);
        int tmp;
        std::cin >> tmp;
        dataReady = true;
        std::cout << "Sender: Data is ready." << std::endl;
        condVar.notify_all();
    }
}


int main() {

    std::thread t2(setDataReady);
    std::thread t1(waitingForWork);


    t1.join();
    t2.join();
}