#include <iostream>
#include <future>

void task(int number) {
    std::cout << "executing task " << number << " on thread " << std::this_thread::get_id() << std::endl;

}

int main() {
    std::cout << "on thread " << std::this_thread::get_id() << std::endl;
    int i=0;
    auto handle = std::async(std::launch::deferred, task, i++);
    auto handle1 = std::async(std::launch::async, task, i++);
    auto handle2 = std::async(task, i++);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // When get or wait is invoked, task() will execute synchronously, i.e., the caller will block until
    // task() finishes running. If neither get nor wait is called, task() will never run.
    handle.get();
}

