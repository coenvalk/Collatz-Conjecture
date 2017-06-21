#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
  unsigned int n = 100;
  if (argc > 1) {
    n = (unsigned int) strtoul(argv[1], NULL, 0);
  }
  while (n != 1) {
    std::cout << n << std::endl;
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
  }
  std::cout << 1 << std::endl;
  return 0;
}
