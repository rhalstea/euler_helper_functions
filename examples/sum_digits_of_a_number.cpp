#include <iostream>
#include "BigInt.h"

using namespace projecteuler;

int main() {

  for (BigInt i = 1; i < 4097; i *= 2) {

    int sum = 0;
    for (int j = 0; j < i.number_digits(); ++j)
      sum += i[j];

    std::cout << i << ": " << sum << std::endl;
  }

  return 0;
}
