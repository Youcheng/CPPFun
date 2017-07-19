#include <iostream>
#include <vector>

template <class Tp>
struct NAlloc {
    typedef Tp value_type;
    NAlloc() = default;
    template <class T> NAlloc(const NAlloc<T>&) {}
    Tp* allocate(std::size_t n) {
        n *= sizeof(Tp);
        std::cout << "allocating " << n << " bytes\n";
        return static_cast<Tp*>(::operator new(n));
    }
    void deallocate(Tp* p, std::size_t n) {
        std::cout << "deallocating " << n*sizeof*p << " bytes\n";
        ::operator delete(p);
    }
};
template <class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&) { return true; }
template <class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&) { return false; }

int main()
{
    int sz = 4;
    std::cout << "using reserve: \n";
    {
        std::vector<int, NAlloc<int>> v1;
        v1.reserve(sz);
        for(int n = 0; n < sz; ++n) {
            v1.push_back(n);
            for(auto& x : v1) {
                std::cout << "address " << &x << " " << x << " ";
            }
            std::cout << std::endl;

            std::cout << "v1.size " << v1.size() << std::endl
                      << "v1.max_size " << v1.max_size() << std::endl
                      << "v1.capacity " << v1.capacity() << std::endl << std::endl;
        }

    }

    // we are not reserving the memory when constructing a new vector object
    // each time when we push a new element in the vector, we will need to reallocate
    // a block of memory on the heap to copy the previous values to this new memory and the latest new value.
    std::cout << "\nnot using reserve: \n";
    {
        std::vector<int, NAlloc<int>> v1;
        for(int n = 0; n < sz; ++n) {
            v1.push_back(n);
            for(auto& x : v1) {
                std::cout << "address " << &x << " " << x << " ";
            }
            std::cout << std::endl;

            std::cout << "v1.size " << v1.size() << std::endl
                      << "v1.max_size " << v1.max_size() << std::endl
                      << "v1.capacity " << v1.capacity() << std::endl << std::endl;
        }
    }
}