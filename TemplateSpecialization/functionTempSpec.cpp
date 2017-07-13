#include <iostream>

template<typename T>
int compare(const T& a, const T& b) {
    std::cout << "compare(const T& a, const T& b)" << std::endl;
    return 0;
}

template<size_t N, size_t M>
int compare(const char (&a)[N], const char (&b)[M]) {
    std::cout << "N " << N << " M " << M << std::endl;
    std::cout << "compare(const char (&)[N], const char (&)[M])" << std::endl;
    return 0;
};


template <>
int compare(const char* const& p1, const char* const& p2) {
    // p1 is a reference to const pointer to const character
    // T is pointer to const character
    std::cout << "compare(const char* const &p1, const char* const &p2)" << std::endl;
    return 0;
}

int main() {
    //compare(5, 6);

    char a1[3] = {'a', 'b', 'c'};
    char a2[5] = {'a', 'b', 'c', 'd', 'e'};
    compare(a2, a1);

    compare("cd", "etf");

    const char * b1 = "cde";
    const char * b2 = "hijk";
    compare(b1, b2);
    // b1 is a pointer to const char
    // ok to use b1 to initialize a const pointer to const char (securer)
    // ok to use b1 to initialize to a reference to a const pointer to const char (securerrr)

}