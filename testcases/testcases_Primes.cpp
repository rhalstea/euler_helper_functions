#include <iostream>
#include <cassert>
#include "Primes.h"

using namespace projecteuler;

int main() {

  std::cout << " ----- ----- Test 1: Constructor ----- ----- " << std::endl;
  Primes test_1;
  assert( test_1.size() == 1 );
  assert( test_1.back() == 2 );
  assert( test_1.max() == 2 );
  assert( test_1[0] == 2);
  assert( test_1.at(0) == 2);
  
  std::cout << " ----- ----- Test 2: Constructor 2 ----- ----- " << std::endl;
  Primes test_2(20);
  std::cout << "Primes less than 20: " << std::endl;
  for (int i = 0; i < test_2.size(); ++i)
    std::cout << test_2[i] << " ";
  std::cout << std::endl;
  for (int i = 0; i < test_2.size(); ++i)
    std::cout << test_2.at(i) << " ";
  std::cout << std::endl;

  std::cout << " ----- ----- Test 3: grow ----- ----- " << std::endl;
  Primes test_3;
  std::cout << "largest prime smaller than numbers divisable by 100: " 
	    << std::endl;
  for (int i = 0; i <= 1000; i += 100) {
    test_3.grow(i);
    std::cout << test_3.max() << " ";
  }
  std::cout << std::endl;

  std::cout << " ----- ----- Test 4: get_next ----- ----- " << std::endl;
  Primes test_4(100);
  std::cout << "First 10 primes larger than 100" << std::endl;
  for (int i = 0; i < 10; ++i)
    std::cout << test_4.get_next() << " ";
  std::cout << std::endl;

  std::cout << " ----- ----- Test 4: get_next(val) ----- ----- " << std::endl;
  Primes test_5;
  std::cout << "Primes after 5x + 1" << std::endl;
  for (int i = 1; i < 100; i += 5)
    std::cout << test_5.get_next(i) << " ";
  std::cout << std::endl;

  return 0;
}
