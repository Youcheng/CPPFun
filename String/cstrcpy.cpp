#include <cstring>
#include <iostream>
#include <string>
#include <experimental/string_view>

// std::strncpy
// char *strncpy( char *dest, const char *src, std::size_t count );
// If after copying the terminating null character from src, 
// count is not reached, additional null characters are written to 
// dest until the total of count characters have been written.
//
// If count is reached before the entire string src was copied, 
// the resulting character array is not null-terminated.
//

template<std::size_t N>
void printCharArray(const char (&arr)[N]) {
    for (int i =0; i < 10; i++) {
        if(arr[i]) std::cout << "arr[" << i << "]=" << arr[i] << '_' << (int)arr[i] << ' ';
        else std::cout << "arr[" << i << "]=" << "\\0" << '_' << (int)arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    char src1[5] = {'1', '2', '\0', '4', '5'};
    char dst1[5];
    char src2[5] = {'1', '2', '3', '4', '5'};
    char dst2[5];

    src1[5] = '8';
    dst1[5] = '9';
    src2[5] = '8';
    dst2[5] = '9';

    printCharArray(src1);
    strncpy(dst1, src1, sizeof(src1));
    //strcpy(dst1, src1);
    printCharArray(dst1);

    std::cout << atoi(std::string(src1,sizeof(src1)).c_str()) << std::endl;
    std::cout << atoi(std::string(dst1,sizeof(dst1)).c_str()) << std::endl;

    std::cout << std::endl;

    printCharArray(src2);
    strncpy(dst2, src2, sizeof(src2));
    //strcpy(dst2, src2);
    printCharArray(dst2);

    std::cout << atoi(std::string(src2,sizeof(src2)).c_str()) << std::endl;
    std::cout << atoi(std::string(dst2,sizeof(dst2)).c_str()) << std::endl;

    std::cout << std::endl;

    std::cout << "src1" << std::endl;
    printCharArray(src1);
    char dst3[5];
    dst3[5] = '7';
    strcpy(dst3, std::string(src1,sizeof(src1)).c_str());
    std::cout << "dst3" << std::endl;
    printCharArray(dst3);

    std::cout << "src2" << std::endl;
    printCharArray(src2);
    char dst4[5];
    dst4[5] = '7';
    strcpy(dst4, std::string(src2,sizeof(src2)).c_str());
    std::cout << "dst4" << std::endl;
    printCharArray(dst4);

    std::cout << "src1" << std::endl;
    printCharArray(src1);
    std::experimental::string_view dst5(src1, sizeof src1);
    std::cout << "dst5" << std::endl;
    std::cout << dst5[0] << std::endl
              << dst5[1] << std::endl
              << (int)dst5[2] << std::endl
              << dst5[3] << std::endl
              << dst5[4] << std::endl
              << dst5[5] << std::endl;

}
