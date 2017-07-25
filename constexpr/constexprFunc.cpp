#include <iostream>
#include <cmath>
#include <array>

// constexpr doesn't mean this function will return a const value,
// it only says if base and exp are compile-time constants, myPow's
// result may be used as a compile-time constant.
constexpr
int myPow(int base, int exp) {
    return ::pow(base, exp);
}



int main() {

  const int numConds = 2;
  std::array<int, myPow(2, numConds)> results{1,2,3};

  for (const auto& x : results) {
      std::cout << x << std::endl;
  }

  int x = 3, y = 4;
    // since x, y are not compile-time constants, myPow will be used
    // like a normal function
  std::cout << myPow(x, y) << std::endl;

}