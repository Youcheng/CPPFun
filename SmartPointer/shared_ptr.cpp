#include<memory>
#include<iostream>
#include<vector>

// std::shared_ptr<T>
// pointer to T ----> T Object
// pointer to control block ---> Reference Count
//                            ---> Weak count
//                            ---> Other Data (like custom deleter, allocator)


class MyClass;

std::vector<std::shared_ptr<MyClass>> processedMyClasses;

class MyClass : public std::enable_shared_from_this<MyClass> {
//class MyClass {
public:
    MyClass() { std::cout << "MyClass::MyClass()" << this << std::endl; }
    MyClass(const MyClass& rhs) { std::cout << "MyClass::MyClass(cosnt MyClass&)" << std::endl; }
    MyClass(MyClass&& rhs) { std::cout << "MyClass::MyClass(MyClass&&)" << std::endl; }
    ~MyClass() { std::cout << "MyClass::~MyClass()" <<  this << std::endl;}

    void process() {
        std::cout << "MyClass::process()" << std::endl;

        // when shared_ptr constructor is called with a raw pointer, it will creates a control block.
        // shared_ptr from a single raw pointer gives you a complimentary rid on the particle accelerator
        // of undefined behaviour, because the pointed-to object will have multiple control blocks.

        // Multiple control blocks means multiple reference counts, and multiple reference counts means the object
        // will be destroyed multiple times(once for each reference count.)

        // pass this to a container of shared_ptrs
        // the shared_ptr constructed will create a new control block for the pointed-to *this.
        // however, there are shared_ptrs outside this member function that already point to *this.

        //enabled_shared_from_this::shared_from_this() creates a std::shared_ptr to the currect object but
        // it does it without duplicating the control blocks.
        processedMyClasses.emplace_back(shared_from_this());
    }
};

int main() {
    std::shared_ptr<MyClass> spm1(new MyClass);
    std::cout << "use_count: " << spm1.use_count() << std::endl;

    std::shared_ptr<MyClass> spm2(spm1);
    std::cout << "use_count: " << spm2.use_count() << std::endl;


    spm1->process();
    spm2->process();




}
