#include <iostream>
#include <memory>

struct Widget {
    Widget() { std::cout << __FUNCTION__ << " " << this << std::endl; }
    Widget(Widget&& rhs) { std::cout << __FUNCTION__ << " " << this << std::endl; }
    ~Widget() { std::cout << __FUNCTION__ << " " << this << std::endl; }
    Widget& operator= (const Widget& rhs) { std::cout << __FUNCTION__ << " " << this << std::endl;}
    Widget& operator= (Widget&& rhs) { std::cout << __FUNCTION__ << " " << this << std::endl;}
};

int main() {
    auto pw = std::make_unique<Widget>();
    std::cout << &pw << "--->" << pw.get() << std::endl;
    std::cout << "before lambda" << std::endl << std::endl;

    // pw =  std::move(pw)
    // left pw is the name of the data member in the closure classs
    // right lpw is the initializing expression
    // to create a data member lpw(left) in the closure and initialize it with the result of std::move(pw)
    auto func = [lpw =  std::move(pw)] {
                                            std::cout << "inside lambada " << &lpw << "--->" << lpw.get() << std::endl;
                                    };

    func();
}
