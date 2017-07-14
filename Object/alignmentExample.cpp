#include <iostream>

struct foo {
    char a;
    int b;
    char c;
    // memory layout
    //-xxx
    //----
    //-xxx
};

struct goo {
    char a;
    double b;
    char c;
    // memory layout
    //-xxxxxxx
    //--------
    //-xxxxxxx
};

struct aoo {
    char a;
    int b;
    char c;
    double d;
    // memory layout
    //-xxx----
    //-xxxxxxx
    //--------
};

struct boo {
    char a;
    double b;
    aoo c;
    int d;
    // memory layout
    // -xxxxxx
    // --------
    //-xxx----
    //-xxxxxxx
    //--------
    //----xxxx

};

struct alignas(16) coo {
    char a;
    int b;
    char c;
    double d;
    // memory layout
    //-xxx ---- -xxxxxxx
    //-------- xxxxxxxx
};


int main() {
    std::cout << "Alignment" << std::endl
              << "char " << alignof(char) << std::endl
            << "int " << alignof(int) << std::endl
            << "double " << alignof(double) << std::endl
            << "char* " << alignof(char*) << std::endl
            << "int*  " << alignof(int*) << std::endl
            << "double*  " << alignof(double*) << std::endl
            << "foo  " << alignof(foo) << std::endl
            << "goo  " << alignof(goo) << std::endl
            << "aoo  " << alignof(aoo) << std::endl
            << "boo  " << alignof(boo) << std::endl
            << "coo  " << alignof(coo) << std::endl;

    std::cout << "Size" << std::endl
              << "char " << sizeof(char) << std::endl
              << "int " << sizeof(int) << std::endl
              << "double " << sizeof(double) << std::endl
              << "char* " << sizeof(char*) << std::endl
              << "int*  " << sizeof(int*) << std::endl
              << "double*  " << sizeof(double*) << std::endl
              << "foo  " << sizeof(foo) << std::endl
              << "goo  " << sizeof(goo) << std::endl
            << "aoo  " << sizeof(aoo) << std::endl
            << "boo  " << sizeof(boo) << std::endl
            << "coo  " << sizeof(coo) << std::endl;


}