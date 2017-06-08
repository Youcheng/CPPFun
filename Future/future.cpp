#include <iostream>
#include <future>
#include <thread>
#include <chrono>


int main()
{
    auto begin1= std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // future from a packaged_task
    std::packaged_task<std::chrono::time_point<std::chrono::system_clock>()> task([](){ return std::chrono::system_clock::now(); }); // wrap the function
    std::future< std::chrono::time_point<std::chrono::system_clock>> f1 = task.get_future();  // get a future
    std::cout << std::boolalpha << f1.valid() << std::endl;
    std::thread(std::move(task)).detach(); // launch on a thread

    auto begin2= std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // future from an async()
    std::future< std::chrono::time_point<std::chrono::system_clock>> f2 = std::async(std::launch::deferred, [](){ return std::chrono::system_clock::now(); });
    std::cout << std::boolalpha << f2.valid() << std::endl;

    auto begin3= std::chrono::system_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    // future from a promise
    std::promise< std::chrono::time_point<std::chrono::system_clock>> p;
    std::future< std::chrono::time_point<std::chrono::system_clock>> f3 = p.get_future();
    std::cout << std::boolalpha << f3.valid() << std::endl;
    std::thread( [&p]{ p.set_value_at_thread_exit(std::chrono::system_clock::now()); }).detach();

    std::cout << "Waiting..." << std::flush;
    f1.wait();
    f2.wait();
    f3.wait();

    auto f1Duration = f1.get() - begin1;
    auto f2Duration = f2.get() - begin2;
    auto f3Duration = f3.get() - begin3;

    std::cout << "Done!\nResults are: "
              <<  std::chrono::duration_cast<std::chrono::milliseconds>(f1Duration).count() << std::endl
            << std::chrono::duration_cast<std::chrono::milliseconds>(f2Duration).count() << std::endl
            << std::chrono::duration_cast<std::chrono::milliseconds>(f3Duration).count() << std::endl;


}

