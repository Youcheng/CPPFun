#include <iostream>
#include <utility>


class Widget {
public:
    Widget() = default;
};

void process(const Widget& lvalArg) {
    std::cout << "process(const Widget& lvalArg)" << std::endl;
}

void process(Widget&& rvalArg) {
    std::cout << "process(Widget&& rvalArg)" << std::endl;
}


template<typename T>
void logAndProcess(T&& param) {
    // param is variable, it is always an lvalue
    // process(param) will always call process(const Widget& lvalArg)
    std::cout << "logAndProcess(T&& param)" << std::endl;

    // std::forward<T>(param) will be rvalue if param is initialized with a rvalue
    // std::forward<T>(param) will be lvalue if param is initialized with a lvalue
    process(std::forward<T>(param));
}

int main() {
    logAndProcess(Widget());
    // Widget() is rvalue
    // T is deduced to Widget
    // void logAndProcess(T&& param) -> void logAndProcess(Widget&& param) --> Widget&& param = rvalue
    // param is initialized with an rvalue -> std::forward<T>(param) is rvalue  --> call process(Widget&& rvalArg)

    Widget w;
    logAndProcess(w);
    // w is lvalue
    // T is deduced to Widget&
    // void logAndProcess(Widget& && param) -> void logAndProcess(Widget& param) --> Widget& param = lvalue
    // param is initialized with an lvalue -> std::forward<T>(param) is lvalue -->  call process(const Widget& lvalArg)

}

