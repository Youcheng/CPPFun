#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

template<typename T>
void f(std::vector<T>&& param)
{
}

void g(int n)
{
    std::chrono::seconds sec(n);
    std::this_thread::sleep_for(sec);
}


int main()
{
    std::vector<int> v;
    // f(v); //error: cannot bind 'std::__debug::vector<int>' lvalue to 'std::__debug::vector<int>&&
    f(std::vector<int>());


    auto timeFuncInvocation =
            [](auto&& func, auto&&... params)  // func is a universal reference which could be bound to any callable object, lvalue or rvalue;
                                               // prams is zero or more universal reference(a universal reference parameter pack)
            {
                auto start = std::chrono::high_resolution_clock::now();

                std::forward<decltype(func)>(func)(
                    std::forward<decltype(params)>(params)...
                    );

                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> diff = end-start;
                std::cout << "Time elapsed for function execution is " << diff.count() << " seconds." << std::endl;
            };

    timeFuncInvocation(g, 5);

}