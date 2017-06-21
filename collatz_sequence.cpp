#include <iostream>
#include <cstdlib>
#include <string>

#include "bigint/BigIntegerLibrary.hh"

int main(int argc, char* argv[]) {
  BigUnsigned n = 100;
  if (argc > 1) {
    std::string A(argv[1]);
    n = stringToBigUnsigned(A);
  }
  while (n != 1) {
    std::cout << n << std::endl;
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n *= 3;
      n += 1;
    }
  }
  std::cout << 1 << std::endl;
  return 0;
}
