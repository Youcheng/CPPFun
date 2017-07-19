#include <iostream>
#include <cstdlib>

class Employee {
public:
    Employee() { std::cout << __FUNCTION__ << " " << this << std::endl; }
    Employee(double m) : m_(m) {
        std::cout << __FUNCTION__ << " " << this << std::endl;
        std::cout << "pause" << std::endl;
    }

    virtual ~Employee() { std::cout << __FUNCTION__ << " " << this << std::endl; }

    double m_;
    char c_;

    void* operator new(size_t sz) {
        std::cout << __FUNCTION__ << std::endl
                  << "sz " << sz << std::endl;

        // even though I don't do this malloc and return,
        // the c++ will still go to the constructor to create an object
        // and return that address
        auto p = std::malloc(sz);
        std::cout << p << std::endl;
        return p;

    } // when falling off the end of this function, the execution will go to the constructors

    void* operator new[](size_t sz) { //operator new[](N∗sizeof(X))
        std::cout << __FUNCTION__ << std::endl
                  << "sz " << sz << std::endl;
        // I have to malloc(sz) and return the pointer,
        // otherwise I will get following error at run time
        // Process finished with exit code 139 (interrupted by signal 11: SIGSEGV)
        auto p = std::malloc(sz);
        std::cout << p << std::endl;
        return p;
    }

    void* operator new(size_t sz, void* pt) {
        std::cout << __FUNCTION__ << std::endl
                  << "sz " << sz << std::endl
                  << "pt " << pt << std::endl;
        // this return is important, which seems to pass the known address
        // to the constructor
        // if I don't put return here, when going to constructor,
        // it seems we are in a different object than known address
        return pt;
    }

    void operator delete(void* p, size_t sz){
        // before following visible codes are executed,
        // it seems the destructor will be called first even though I didn't call free(p)
        std::cout << __FUNCTION__ << std::endl
                << "p " << p << std::endl
                  << "sz " << sz << std::endl;
    }

    void operator delete[](void* p, size_t sz){
        std::cout << __FUNCTION__ << std::endl
                  << "p " << p << std::endl
                  << "sz " << sz << std::endl;
    }

};


class Manager: public Employee {
public:
    Manager() { std::cout << __FUNCTION__ << " " << this << std::endl; }
    ~Manager() { std::cout << __FUNCTION__ << " " << this << std::endl; }

    int a_;
};

int main() {
    std::cout << "sizeof(Employee) " << sizeof(Employee) << std::endl;

    Employee* p = new Employee(3.2);
    // new
    // steps into the body of overloaded operator new function
    // steps into the body of constructor when falling off the end of the body of overloaded new operator function

    std::cout << p << std::endl;
    delete p;
    // delete
    // steps into the body of destructor
    // steps into the body of overloaded operator delete function

    std::cout << "----------" << std::endl;
    Employee *pa = new Employee[2];
    // new []
    // steps into the body of overloaded operator new[] function
    // steps into the body of constructor 4 times when falling off the end of the body of overloaded new operator function


    delete[] pa;
    // delete[]
    // steps into the body of destructor 4 times
    // steps into the body of overloaded opearator delete[] function

    std::cout << "----------" << std::endl;
    Employee* q = new Manager();
    delete q;

    std::cout << "----------" << std::endl;
    Employee* w = new Employee;
    Employee* qq = new(w) Employee (3.2);
}