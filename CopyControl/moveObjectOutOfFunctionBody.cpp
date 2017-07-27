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
    // default constructor for x1

    x1 = increment(x1);
    // copy constructor from x1 to arg
    // move constructor from arg to tmp
    // move assignment from tmp to x1
    // destructor for tmp
    // destructor for arg

    std::cout << "x1 address " << &x1 << std::endl;

    xoo x2;
    // default constructor

    x1 = x2;
    // copy assignment from x2 to x1

    xoo x3(std::move(x1));
    // move constructor

    // destructor for x3, x2 and x1
}

//defaultConstructor 0x7ffe23c58680
//copyConstructor from 0x7ffe23c58680 to 0x7ffe23c586a0
//increment 0x7ffe23c586a0
//moveConstructor from 0x7ffe23c586a0 to 0x7ffe23c58690
//moveAssignment from 0x7ffe23c58690 to 0x7ffe23c58680
//destructor 0x7ffe23c58690
//destructor 0x7ffe23c586a0
//x1 address 0x7ffe23c58680

//defaultConstructor 0x7ffe23c58670
//copyAssignment from 0x7ffe23c58670 to 0x7ffe23c58680

//moveConstructor from 0x7ffe23c58680 to 0x7ffe23c58660

//destructor 0x7ffe23c58660 x3
//destructor 0x7ffe23c58670 x2
//destructor 0x7ffe23c58680 x1