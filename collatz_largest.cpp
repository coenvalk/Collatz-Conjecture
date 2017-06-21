#include <iostream>

#include "BigInt/BigIntegerLibrary.hh"

BigUnsigned collatz(BigUnsigned n) {
  BigUnsigned i = 0;
  while (n != 1) {
    if (n % 2 == 1) {
      n *= 3;
      n += 1;
    } else {
      n /= 2;
    }
    i++;
  }
  return i;
}

int main(int argc, char* argv[]) {
  BigUnsigned N = 100;
  if (argc > 1) {
    std::string A(argv[1]);
    N = stringToBigUnsigned(A);
  }
  BigUnsigned largest = 1;
  BigUnsigned largest_collatz = 0;
  for (BigUnsigned i = 1; i < N; i++) {
    BigUnsigned tmp = collatz(i);
    if (tmp > largest_collatz) {
      largest_collatz = tmp;
      largest = i;
    }
  }
  std::cout << largest << ": " << largest_collatz << std::endl;
  return 0;
}
