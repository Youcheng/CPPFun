#include "widget.h"

class widget::impl {
    int n; // private data
public:
    void draw(const widget& w) const {
        if(w.shown()) // this call to public member function requires the back-reference
            std::cout << "drawing a const widget " << n << '\n';
    }
    void draw(const widget& w) {
        if(w.shown())
            std::cout << "drawing a non-const widget " << n << '\n';
    }
    impl(int n) : n(n) {}
};

void widget::draw() const { pImpl->draw(*this); }
void widget::draw() { pImpl->draw(*this); }
widget::widget(int n) : pImpl{std::make_unique<impl>(n)} {}
widget::~widget() = default;
widget& widget::operator=(widget&&) = default;

int main()
{
    widget w(7);

    //std::experimental::propagate_const is a const-propagating wrapper for pointers and pointer-like objects.
    // It treats the wrapped pointer(std::unique_ptr<impl>) as a pointer to const
    // when accessed through a const access path(const widget w2, void widget::draw() const, void widget::impl::draw() const), hence the name.
    const widget w2(8);

    w.draw();
    w2.draw();
}


