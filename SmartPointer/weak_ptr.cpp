#include<memory>
#include<iostream>

struct A
{
    int i=5;
    std::weak_ptr<A> ptr;

    A() { std::cout << __FUNCTION__ << " " << this << std::endl; }
    ~A() { std::cout << __FUNCTION__ << " " << this  <<std::endl; }
};

int main()
{
    std::shared_ptr<A> x = std::make_shared<A>();

    std::cout << "&x " << &x << std::endl
              << "x.get() " << x.get() << std::endl
              << "&(x->ptr) " << &(x->ptr) << std::endl
              << "x->ptr.get() " << x->ptr.lock().get() << std::endl
              << "x.use_count() " << x.use_count() << std::endl << std::endl;

    x->ptr = x;
    std::cout << "&x " << &x << std::endl
              << "x.get() " << x.get() << std::endl
              << "&(x->ptr) " << &(x->ptr) << std::endl
              << "x->ptr.lock().get() " << x->ptr.lock().get() << std::endl
              << "x.use_count() " << x.use_count() << std::endl << std::endl;

    // when x goes out of scope, the destructor of X will be called
    // - decrement the reference to object of A by 1
    // - check whether the current count is 0,
    // - since we are using the weak_ptr, A.ptr points to the same object of A, so the current is actually 0 now.
    // - then delete A* will be called to release that memory on the heap.
}


// Example output
//A 0xf69c30
//&x 0x7ffd5e0ca200
//x.get() 0xf69c30
//&(x->ptr) 0xf69c38
//x->ptr.get() 0
//x.use_count() 1
//
//&x 0x7ffd5e0ca200
//x.get() 0xf69c30
//&(x->ptr) 0xf69c38
//x->ptr.lock().get() 0xf69c30
//x.use_count() 1
//
//~A 0xf69c30
