#include <iostream>
#include <bitset>

struct S {
    // will usually occupy 2 bytes:
    // 3 bits: value of b1
    // 5 bits: unused
    // 6 bits: value of b2
    // 2 bits: value of b3
    unsigned char b1 : 3;
    unsigned char :0; // start a new byte
    unsigned char b2 : 6;
    unsigned char b3 : 2;
};

int main() {
  S* pt = new S;

  // --------   --------   --------   --------

  pt->b1 = 0x6; // 3 bits
               // new byte
  pt->b2 =0x2; // 6 bits
  pt->b3 = 0x3; // 2 bits

  char* cp1 = reinterpret_cast<char*>(pt);
  std::bitset<8> b1(*cp1);
  std::bitset<8> b2(*(cp1+1));

  std::cout << b1 << std::endl
            << b2 << std::endl;
//    00000110
//    11000010

}