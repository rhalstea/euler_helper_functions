#include <iostream>
#include "Primes.h"

using namespace projecteuler;

int main() {

  Primes p;
  while (p.get_next() % 10 != 9);
  std::cout << "first prime ending in nine: " << p.back() << std::endl;

  return 0;
}
