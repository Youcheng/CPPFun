#include<memory>
#include<iostream>

struct A
{
    int i=5;
    std::shared_ptr<A> ptr;

    A() { std::cout << __FUNCTION__ << " " << this << std::endl; }
    ~A() { std::cout << __FUNCTION__ << " " << this  <<std::endl; }
};

int main()
{
        std::shared_ptr<A> x = std::make_shared<A>();

        std::cout << "&x " << &x << std::endl
                  << "x.get() " << x.get() << std::endl
                  << "&(x->ptr) " << &(x->ptr) << std::endl
                  << "x->ptr.get() " << x->ptr.get() << std::endl
                  << "x.use_count() " << x.use_count() << std::endl << std::endl;

        x->ptr = x;
        std::cout << "&x " << &x << std::endl
                  << "x.get() " << x.get() << std::endl
                  << "&(x->ptr) " << &(x->ptr) << std::endl
                  << "x->ptr.get() " << x->ptr.get() << std::endl
                  << "x.use_count() " << x.use_count() << std::endl << std::endl;

        // when x goes out of scope, the destructor of X will be called
        // - decrement the reference to object of A by 1
        // - check whether the current count is 0 but it is 1 since A.ptr still points to it.
        // Therefore, A won't be destroyed.(memory leak)
}

// Example output
//    /home/ylin/CLionProjects/CPPFun/cmake-build-debug/cycliSharedPtr
//    A 0x14bbc30
//      &x 0x7ffdb235d9f0
//    x.get() 0x14bbc30
//            &(x->ptr) 0x14bbc38
//    x->ptr.get() 0
//    x.use_count() 1
//
//                  &x 0x7ffdb235d9f0
//    x.get() 0x14bbc30
//            &(x->ptr) 0x14bbc38
//    x->ptr.get() 0x14bbc30
//    x.use_count() 2

