#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>

struct Box {
    explicit Box(int num) : num_things{num} {}

    int num_things;
    std::mutex m;
};

void transfer(Box &from, Box &to, int num)
{
//////// deadlock-possible implementation //////////////
    std::lock_guard<std::mutex> lock1(from.m);
    using namespace std::chrono_literals;
    std::this_thread::sleep_for(100ms);
    std::lock_guard<std::mutex> lock2(to.m);
    std::cout << std::this_thread::get_id() << std::endl;
    from.num_things -= num;
    to.num_things += num;


////// deadlock-free implementation /////////////////
//    // don't actually take the locks yet
//    std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
//    using namespace std::chrono_literals;
//    std::this_thread::sleep_for(100ms);
//    std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);
//    // lock both unique_locks without deadlock
//    std::lock(lock1, lock2);
//    std::cout << std::this_thread::get_id() << std::endl;
//    from.num_things -= num;
//    to.num_things += num;
//    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors

}

int main()
{
    Box acc1(100);
    Box acc2(50);

    std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
    std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

    t1.join();
    t2.join();
}

