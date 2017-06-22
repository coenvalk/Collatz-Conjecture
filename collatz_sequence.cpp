#include <iostream>
#include <cstdlib>
#include <string>

#include "BigInt/BigIntegerLibrary.hh"

int main(int argc, char* argv[]) {
  BigUnsigned n = 100;
  BigUnsigned i = 0;
  if (argc > 1) {
    std::string A(argv[1]);
    n = stringToBigUnsigned(A);
  }
  BigUnsigned original = n;
  while (n != 1) {
    std::cout << n << std::endl;
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n *= 3;
      n += 1;
      std::cout << n << std::endl;
      // n will be even, automatically divide by 2
      n /= 2;
      i++;
    }
    i++;
  }
  std::cout << 1 << std::endl;
  std::cout << original << ": " << i << std::endl;
  return 0;
}
