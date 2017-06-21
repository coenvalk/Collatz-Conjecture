#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "bigint/BigIntegerLibrary.hh"

struct collatz_node {
  struct collatz_node* from_even; // should be data * 2
  struct collatz_node* from_odd; // should be (data - 1) / 3
  BigInteger data;
};
typedef struct collatz_node* cn_T;

cn_T new_cn(BigInteger n) {
  cn_T new_cn_T = (cn_T) malloc(sizeof(struct collatz_node));
  new_cn_T->data = n;
  new_cn_T->from_even = NULL;
  new_cn_T->from_odd = NULL;
  return new_cn_T;
}

void expand(cn_T cn) {
  cn->from_even = new_cn(cn->data * 2);
  if (cn->data % 3 == 1 && ((cn->data - 1) / 3) % 2 == 1 && cn->data > 4) {
    cn->from_odd = new_cn((cn->data - 1) / 3);
  } else {
    cn->from_odd = NULL;
  }
}

void print_cn(cn_T base, int indent) {
  if (base == NULL) return;
  for (int i = 0; i < indent; i++) {
    std::cout << "      ";
  }
  std::cout << std::left << std::setfill(' ') << std::setw(6) << base->data << std::endl;
  print_cn(base->from_odd, indent + 1);
  print_cn(base->from_even, indent);
}

void r_expand(cn_T cn, BigInteger MAX) {
  if (cn == NULL) return;
  if (cn->data > MAX) return;
  expand(cn);
  r_expand(cn->from_even, MAX);
  r_expand(cn->from_odd, MAX);
}

void delete_cn(cn_T cn) {
  if (cn == NULL) return;
  delete_cn(cn->from_even);
  delete_cn(cn->from_odd);
  free(cn);
  cn = NULL;
}

int main() {
  cn_T Base = new_cn(1);
  BigInteger MAX = 100;
  r_expand(Base, MAX);
  print_cn(Base, 0);
  delete_cn(Base);
  return 0;
}
