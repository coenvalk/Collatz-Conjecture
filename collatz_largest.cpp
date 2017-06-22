#include <iostream>
#include <map>
#include <vector>

#include "BigInt/BigIntegerLibrary.hh"

BigUnsigned collatz(BigUnsigned n, std::map<BigUnsigned, BigUnsigned>& cache) {
  BigUnsigned N = n;
  BigUnsigned i = 0;
  std::map<BigUnsigned, BigUnsigned>::iterator it;
  
  std::vector<BigUnsigned> list;

  while (n != 1) {
    it = cache.find(n);
    if (it == cache.end()) {
      list.push_back(n);
      if (n % 2 == 1) {
	n *= 3;
	n += 1;
      } else {
	n /= 2;
      }
      i++;
    } else {
      i += it->second;
      break;
    }
  }
  for (BigUnsigned j = 0, n = list.size(); j < n; j++) {
    cache[list[j.toInt()]] = i - j;
  }
  return i;
}

int main(int argc, char* argv[]) {
  BigUnsigned N = 100;
  std::map<BigUnsigned, BigUnsigned> cache;
  if (argc > 1) {
    std::string A(argv[1]);
    N = stringToBigUnsigned(A);
  }
  BigUnsigned largest = 1;
  BigUnsigned largest_collatz = 0;
  for (BigUnsigned i = 1; i < N; i++) {
    BigUnsigned tmp = collatz(i, cache);
    if (tmp > largest_collatz) {
      largest_collatz = tmp;
      largest = i;
    }
  }
  std::cout << largest << ": " << largest_collatz << std::endl;
  return 0;
}
