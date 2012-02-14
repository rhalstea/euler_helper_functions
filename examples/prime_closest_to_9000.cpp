#include <iostream>
#include "Primes.h"

using namespace projecteuler;

int main() {
  Primes p;

  std::cout << "Smallest prime number after 9000: " 
	    << p.get_next(9000)
	    << std::endl;

  return 0;
}
