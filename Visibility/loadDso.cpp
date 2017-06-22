#include <iostream>
#include "dso.h"

int main() {
  publicFunction();
  //privateFunction(); // error: undefined reference to 'privateFunction()'
}
