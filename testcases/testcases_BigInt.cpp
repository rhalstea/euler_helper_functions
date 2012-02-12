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
#include <cstdlib>
#include <sstream>
#include <cassert>

#include "BigInt.h"

using namespace projecteuler;

bool verify_match(BigInt a, int b) {
  return ( atoi(a.value().c_str()) == b );
}

void handle_addition(BigInt a, BigInt b) {
  BigInt result = a + b;

  std::cout << a.value() << " + " 
	    << b.value() << " = " 
	    << result.value() << std::endl;

}

void handle_multiplication(BigInt a, BigInt b) {
  BigInt result = a * b;

  std::cout << a << " * "
	    << b << " = "
	    << result.value() << std::endl;
}

int main() {
  
  std::cout << " ----- ----- Test 1: Constructor ----- ----- " << std::endl;
  BigInt test_1;
  std::cout << test_1 << std::endl;
  test_1 = "-12345";
  std::cout << test_1 << std::endl;
  test_1 = (long)2;
  std::cout << test_1 << std::endl;
  test_1 = (long long)-234557;
  std::cout << test_1 << std::endl;



  std::cout << " ----- ----- Test 2: Constructor ----- ----- " << std::endl;
  for (int i = -10; i < 10; i += 2) {
    BigInt test_2 = BigInt(i);
    std::cout << test_2.value() << " ";
  }
  std::cout << std::endl;



  std::cout << " ----- ----- Test 3: Constructor ----- ----- " << std::endl;
  for (int i = -9; i < 10; i += 2) {
    std::stringstream ss;
    ss << i;
    BigInt test_3 = BigInt(ss.str());
    std::cout << test_3.value() << " ";
  }
  std::cout << std::endl;



  std::cout << " ----- ----- Test 4: GT ----- ----- " << std::endl;
  BigInt test_4_left = 1;
  BigInt test_4_right = 2;
  assert( test_4_right > test_4_left );
  assert( !(test_4_left > test_4_right) );

  test_4_left = -20;
  test_4_right = -10;
  assert( test_4_right > test_4_left );
  assert( !(test_4_left > test_4_right) );

  test_4_left = -1000;
  test_4_right = -1000;
  assert( !(test_4_right > test_4_left) );
  assert( !(test_4_left > test_4_right) );

  test_4_left = 1000;
  test_4_right = 1000;
  assert( !(test_4_right > test_4_left) );
  assert( !(test_4_left > test_4_right) );

  test_4_left = -12345;
  test_4_right = 128;
  assert( test_4_right > test_4_left );
  assert( !(test_4_left > test_4_right) );

  std::cout << " ----- ----- Test 5: EQ ----- ----- " << std::endl;
  BigInt test_5_left = 1234;
  BigInt test_5_right = 1234;
  assert( test_5_left == test_5_right);

  test_5_left = 124567;
  assert( !(test_5_left == test_5_right) );
  assert( !(test_5_right == test_5_left) );

  std::cout << " ----- ----- Test 6: LT ----- ----- " << std::endl;
  BigInt test_6_left = 4567;
  BigInt test_6_right = 23456;
  assert( test_6_left < test_6_right );
  assert( !(test_6_right < test_6_left) );

  test_6_left = 4567;
  test_6_right = 4567;
  assert( !(test_6_left < test_6_right) );

  std::cout << " ----- ----- Test 7: NEQ GTE LTE ----- ----- " << std::endl;
  BigInt test_7_left = 234234;
  BigInt test_7_right = -2;
  assert( test_7_left != test_7_right );
  assert( test_7_right != test_7_left );
  assert( test_7_left >= test_7_right );
  assert( !(test_7_right >= test_7_left) );
  assert( !(test_7_left <= test_7_right) );
  assert( test_7_right <= test_7_left );
  
  test_7_left = -1234567;
  test_7_right = -1234567;
  assert( !(test_7_left != test_7_right) );
  assert( !(test_7_right != test_7_left) );
  assert( test_7_left >= test_7_right );
  assert( test_7_right >= test_7_left );
  assert( test_7_left <= test_7_right );
  assert( test_7_right <= test_7_left );
  
  std::cout << " ----- ----- test 8: Addition ----- ----- " << std::endl;
  handle_addition(1, 2);
  handle_addition(-1, -4);
  handle_addition(8, 3);
  handle_addition(-8, -4);
  handle_addition(12, -4);
  handle_addition(-12, 5);
  handle_addition(99, 5);
  handle_addition(-97, -9);
  handle_addition(100, -100);
  handle_addition(-100, 100);
  handle_addition(1234567, -1234566);
  handle_addition(-1234566, 1234567);
  handle_addition(-1234567, 1234566);
  handle_addition(1234566, -1234567);

  std::cout << "verifying 400,000 compairsons ... ";
  std::cout.flush();
  for (int i = -100; i <= 100; ++i) {
    for (int j = -1000; j <= 1000; ++j) {
      BigInt a = i;
      BigInt b = j;
      assert( verify_match(a + b, i + j) );
    }
  }
  std::cout << "done" << std::endl;


  std::cout << " ----- ----- test 9: Subtracton ----- ----- " << std::endl;
  std::cout << "verifying 400,000 compairsons ... ";
  std::cout.flush();  
  for (int i = -100; i <= 100; ++i) {
    for (int j = -1000; j <= 1000; ++j) {
      BigInt a = i;
      BigInt b = j;
      assert (verify_match(a - b, i - j));
    }
  }
  std::cout << "done" << std::endl;

  std::cout << " ----- ----- test 10: ++ ----- ----- " << std::endl;
  BigInt test_10_pre = 0;
  BigInt test_10_post = 0;
  for (int i = 0; i < 20; ++i) {
    assert( verify_match(test_10_pre, i) );
    assert( verify_match(test_10_post, i) );
    ++test_10_pre;
    test_10_post++;
  }

  std::cout << " ----- ----- test 11: -- ----- ----- " << std::endl;
  BigInt test_11_pre = 10;
  BigInt test_11_post = 10;
  for (int i = 10; i > -20; --i) {
    assert( verify_match(test_11_pre, i) );
    assert( verify_match(test_11_post, i) );
    --test_11_pre;
    test_11_post--;
  }

  std::cout << " ----- ----- test 12: += ----- ----- " << std::endl;
  std::cout << "print even # [0, 20)" << std::endl;
  for (BigInt test_12 = 0; test_12 < 20; test_12 += 2)
    std::cout << test_12.value() << " ";
  std::cout << std::endl;

  std::cout << " ----- ----- test 13: -= ----- ----- " << std::endl;
  std::cout << "print oddnumbers # [99, 80)" << std::endl;
  for (BigInt test_13 = 99; test_13 > 80; test_13 -= 2)
    std::cout << test_13.value() << " ";
  std::cout << std::endl;

  std::cout << " ----- ----- test 14: Multiply ----- ----- " << std::endl;
  handle_multiplication(4, 2);
  handle_multiplication(-4, 2);
  handle_multiplication(4, -2);
  handle_multiplication(4, 4);
  handle_multiplication(100, 20);
  std::cout << "verifying 20,000 compairsons ... ";  
  std::cout.flush();
  for (int i = -100; i <= 100; ++i) {
    for (int j = -100; j <= 100; ++j) {
      BigInt a = i;
      BigInt b = j;
      assert( verify_match( a * b, i * j) );
      a *= b;
      assert( verify_match(a, i * j) );
    }
  }
  std::cout << "done" << std::endl;

  std::cout << " ----- ----- test 15: get_digit ----- ----- " << std::endl;
  BigInt test_15 = 1234567890;
  std::cout << test_15.value() << ": ";
  for (int i = 0; i < test_15.size(); ++i) 
    std::cout << test_15.get_digit(i) << " ";
  std::cout << std::endl;

  test_15 = -876543210;
  std::cout << test_15 << ": ";
  for (int i = 0; i < test_15.size(); ++i) 
    std::cout << test_15.get_digit(i) << " ";
  std::cout << std::endl;

  test_15 = -123000;
  std::cout << test_15 << ": ";
  for (int i = 0; i < test_15.size(); ++i) 
    std::cout << test_15[i] << " ";
  std::cout << std::endl;

  return 0;
}
