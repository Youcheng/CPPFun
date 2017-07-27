#include <iostream>

class xoo {
public:
    xoo() { std::cout << "defaultConstructor " << this << std::endl; }
    ~xoo() {
        std::cout << "destructor " << this << std::endl;

        if  (data_ != nullptr) {
            // Delete the resource.
            std::cout << " Deleting resource " << data_ << std::endl;
            delete data_;
        }
    }

    // copy constructor
    xoo(const xoo& rhs) {
        std::cout << "copyConstructor " << "from " << &rhs << " to " << this << std::endl;

        // copy the value from the source object.
        if (rhs.data_ != nullptr) {
            // allocate new memory on the heap first
            data_ = new int;
            std::cout << "Allocate new memory " << data_ << std::endl;

            *data_ = *(rhs.data_);
        }
        length_ = rhs.length_;
    }

    // move constructor
    xoo(xoo&& rhs) {
        std::cout << "moveConstructor " << "from " << &rhs << " to " << this << std::endl;

        // Copy the data pointer and its length from the source object.
        data_ = rhs.data_;
        length_ = rhs.length_;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        rhs.data_ = nullptr;
        rhs.length_ = 0;
    }

    // copy assignment operator
    xoo& operator=(const xoo& rhs) {
        std::cout << "copyAssignment " << "from " << &rhs << " to " << this << std::endl;

        if (this != &rhs) {
            // Free the existing resource.
            if  (data_ != nullptr) {
                // Delete the resource.
                std::cout << " Deleting resource " << data_ << std::endl;
                delete data_;
            }

            // copy the value from the source object.
            if (rhs.data_ != nullptr) {
                // allocate new memory on the heap first
                data_ = new int;
                std::cout << "Allocate new memory " << data_ << std::endl;

                *data_ = *(rhs.data_);
            }

            length_ = rhs.length_;
        }

        return *this;

    }

    // move assignment operator
    xoo& operator=(xoo&& rhs) {
        std::cout << "moveAssignment " << "from " << &rhs << " to " << this << std::endl;

        // perform no operation if you try to assign the object to itself
        if (this != &rhs) {
            // Free the existing resource.
            if  (data_ != nullptr) {
                // Delete the resource.
                std::cout << " Deleting resource " << data_ << std::endl;
                delete data_;
            }

            // Copy the data pointer and its length from the source object.
            data_ = rhs.data_;
            length_ = rhs.length_;

            // Release the data pointer from the source object so that
            // the destructor does not free the memory multiple times.
            rhs.data_ = nullptr;
            rhs.length_ = 0;
        }

        return *this;
    }


    int* data_ = nullptr;
    int length_;
};

xoo increment(xoo arg) {
    std::cout << __FUNCTION__ << " " << &arg << std::endl;
    return arg;
}

int main() {

    xoo x1;

    x1 = increment(x1);

    std::cout << "x1 address " << &x1 << std::endl<< std::endl;

    xoo x2 = increment(x1);

    std::cout << "x2 address " << &x2 << std::endl<< std::endl;

    x1 = x2;

    xoo x3(std::move(x1));
    std::cout << "x3 address " << &x3 << std::endl<< std::endl;

    xoo x4;
    x4 = x3;
    std::cout << "x4 address " << &x4 << std::endl<< std::endl;

}

//defaultConstructor 0x7ffce6bc3810(x1)
//copyConstructor from 0x7ffce6bc3810(x1) to 0x7ffce6bc3830(arg)
//increment 0x7ffce6bc3830(arg)
//moveConstructor from 0x7ffce6bc3830(arg) to 0x7ffce6bc3820(tmp)
//moveAssignment from 0x7ffce6bc3820(tmp) to 0x7ffce6bc3810(x1)
//destructor 0x7ffce6bc3820(tmp)
//destructor 0x7ffce6bc3830(arg)
//x1 address 0x7ffce6bc3810
//
//copyConstructor from 0x7ffce6bc3810(x1) to 0x7ffce6bc3840(arg)
//increment 0x7ffce6bc3840(arg)
//moveConstructor from 0x7ffce6bc3840(arg) to 0x7ffce6bc3800(x2) < no tmp is created due to optimization
//destructor 0x7ffce6bc3840(arg)
//x2 address 0x7ffce6bc3800
//
//copyAssignment from 0x7ffce6bc3800(x2) to 0x7ffce6bc3810(x1)
//moveConstructor from 0x7ffce6bc3810(x1) to 0x7ffce6bc37f0(x3) < no tmp is created due to optimization
//x3 address 0x7ffce6bc37f0
//
//defaultConstructor 0x7ffce6bc37e0(x4)
//copyAssignment from 0x7ffce6bc37f0(x3) to 0x7ffce6bc37e0(x4)
//x4 address 0x7ffce6bc37e0(x4)
//
//destructor 0x7ffce6bc37e0
//destructor 0x7ffce6bc37f0
//destructor 0x7ffce6bc3800
//destructor 0x7ffce6bc3810