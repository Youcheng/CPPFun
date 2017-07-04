#include<iostream>
#include<memory>

class MyClass{
public:
    MyClass(int i):i_(i) {
        std::cout << i << std::endl;
    }

    void print() {
        std::cout << "haha: "  <<  i_ << std::endl;
    }

    int i_;
};

int main() {
    int i = 3;
    auto tmp = [&]{
        return std::make_unique<MyClass>(i);
    }();

    tmp->print();

}
