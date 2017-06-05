/*
 * A deadlock is a state in which two or more threads are blocked because each threads waits
 * for the release of a resource before it releases its own resource.
 */

#include <iostream>
#include <mutex>
#include <thread>

using namespace std;
struct CriticalData{
    std::mutex mut;
};

void deadLock(CriticalData& a, CriticalData& b){
    a.mut.lock();
    std::cout << "get the first mutex\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    b.mut.lock();
    std::cout << "get the second mutex\n";
    a.mut.unlock(), b.mut.unlock();
}

void deadLockResolved(CriticalData& a, CriticalData& b){
    std::unique_lock<std::mutex>guard1(a.mut, std::defer_lock);
    cout << this_thread::get_id() << ": get the first lock" << endl;
    this_thread::sleep_for(chrono::milliseconds(1));
    unique_lock<mutex>guard2(b.mut, defer_lock);
    cout << this_thread::get_id() << ": get the second lock" << endl;
    cout << this_thread::get_id() << ": atomic locking";
    lock(guard1, guard2);
    /*
     * Because of the argument std::defer_lock of the std::unique_lock , the locking of a.mut and b.mut
     * is deferred. The locking takes place atomically in the call std::lock(guard1, guard2)
     */
}


int main() {

    CriticalData c1;
    CriticalData c2;
    //std::thread t1([&]{ deadLock(c1, c2); });
    //std::thread t2([&]{ deadLock(c2, c1); });
    //t1.join();
    //t2.join();

    std::thread t1([&]{ deadLockResolved(c1, c2); });
    std::thread t2([&]{ deadLockResolved(c2, c1); });
    t1.join();
    t2.join();
}