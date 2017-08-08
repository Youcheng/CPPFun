#include "queueUsingSingleLinkedList.hpp"
#include <iostream>

struct foo {
    int a;
    double b;
    char c;
};

int main() {
    threadsafe_queue<foo> q;
    foo f;
    f.a = 1;
    f.b = 2.4;
    f.c ='z';

    q.push(f);
    auto ptr = q.try_pop();
    std::cout << ptr->c << std::endl;
}