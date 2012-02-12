/*
Copyright (c) 2012, Robert J. Halstead
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

- Redistributions of source code must retain the above copyright
  notice, this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in
  the documentation and/or other materials provided with the
  distribution.
- Neither the name of Robert J. Halstead, or NotebookCache.com nor
  the names of its contributors may be used to endorse or promote
  products derived from this software without specific prior
  written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL Robert J.
Halstead BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
DAMAGE.
*/

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
