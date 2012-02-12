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

#ifndef __EULER_EULER_HELPER_FUNCTIONS_H__
#define __EULER_EULER_HELPER_FUNCTIONS_H__

#include <vector>

namespace projecteuler {

  // class for primes
  //  primes from to
  //  iterator over prime numbers
  //  get prime after 
  //  verify number is prime


  // GCD

  /*!
    Basic binary search algorithm. Does not check that list is sorted
  */
  template <class T>
    bool binary_search(T key, const std::vector<T> &vec) {
    
    int min = 0;
    int mid = 0;
    int max = vec.size();

    do {
      mid = min + (max - min) / 2;

      if (vec[mid] > key)
	max = mid - 1;
      else
	min = mid + 1;

    } while(vec[mid] != key && min <= max);

    pos = mid;
    return vec[mid] == key;
  }

  // pandigital -- templatize it (not going to implement)

  // factorization
  
}

#endif
