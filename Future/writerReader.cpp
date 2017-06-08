#include <future>
#include <iostream>
#include <thread>

void doTheWork(){
    std::cout << "Processing shared data." << std::endl;
}

void waitingForWork(std::future<int>&& fut){
        try {
            std::cout << "Worker: Waiting for work." << std::endl;
            fut.wait();
            doTheWork();
            std::cout << "Got " << fut.get() << std::endl;
        } catch (const std::future_error& e) {
            std::cout << e.what() << std::endl;
        }

}
void setDataReady(std::promise<int>&& prom){
        int tmp;
        std::cin >> tmp;
        std::cout << "Sender: Data is ready." << std::endl;
        prom.set_value(tmp);
}


int main() {
    std::promise<int> sendReady;
    auto fut = sendReady.get_future();
    std::thread t1(waitingForWork, std::move(fut));
    std::thread t2(setDataReady, std::move(sendReady));

    t1.join();
    t2.join();
}