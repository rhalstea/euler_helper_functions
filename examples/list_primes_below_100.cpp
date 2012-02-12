#include <iostream>
#include "Primes.h"

using namespace projecteuler;

int main() {
  Primes p(100);

  for (int i = 0; i < p.size(); ++i)
    std::cout << p[i] << " ";

  std::cout << std::endl;

  return 0;
}
