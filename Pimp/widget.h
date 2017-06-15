#include <iostream>
#include <memory>
#include <experimental/propagate_const>

// interface (widget.h)
class widget {
    class impl;
    std::experimental::propagate_const<std::unique_ptr<impl>> pImpl;

public:
    void draw() const; // public API that will be forwarded to the implementation
    void draw();

    bool shown() const { return true; } // public API that implementation has to call

    widget(int);
    ~widget(); // defined in the implementation file, where impl is a complete type
    widget(widget&&) = default;  // Note: calling draw() on moved-from object is UB

    widget(const widget&) = delete;

    widget& operator=(widget&&); // defined in the implementation file
    widget& operator=(const widget&) = delete;
};


/*
Pros:

        Hide the private part of the class
        The binary compatibility ABI isn’t broken if you change something in the pimpl idiom class
        Lesser header dependencies => because most header now only needs to be in the *.cpp
        Faster compilation times

Cons:

        The pimpl idiom could slow down your code (because there is always a pointer access) but there are some technique to speed up a pimpl idiom
        Extra heap-allocation
*/

