#include <iostream>

//a # operator before an identifier in the replacement-list, effectively creating a string literal
#define printArg(first, ...) std::cout << #first << "|" << #__VA_ARGS__ << std::endl

//A ## operator between any two successive identifiers in the replacement-list runs parameter replacement 
//on the two identifiers (which are not macro-expanded first) and then concatenates the result
#define FUNCTION(name, a) \
auto fun_##name() \
{ return #name; }

//predefined macros
#define cppVersion() std::cout << __cplusplus << std::endl;
#define compileDateTime() std::cout << __FILE__ << " is compiled at " << __DATE__ << " " << __TIME__ << std::endl;

FUNCTION(double, 2)
FUNCTION(xx, 2)

int main() {
    printArg(abc,456);
    printArg(456,789);
    std::cout << "double: " << fun_double() << std::endl;
    std::cout << "xx: " << fun_xx() << std::endl;

    // /opt/cresearch/bin/g++ -D TEST=10 replaceTextMacros.cpp -o replaceTextMacros.exe
    #ifdef TEST
    std::cout << TEST << std::endl;
    #else
    std::cout << "No predefined TEST" << std::endl;
    #endif 

    cppVersion();
    compileDateTime();
}
