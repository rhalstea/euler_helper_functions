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

#ifndef __EULER_PRIMES_H__
#define __EULER_PRIMES_H__

#include <iostream>
#include <vector>

namespace projecteuler {

  class Primes {
  public:

    Primes();
    /*!
      Initializes a list of prime numbers using Sieve of Eratosthenes
      @param max hightest prime number
     */
    Primes(unsigned max);
    ~Primes();
    
    /*!
      @return The number of cached primes
    */
    unsigned size();

    /*!
      @return The largest cached prime
    */
    unsigned max();

    /*!
      @return The largest cached prime
    */
    unsigned back();

    /*!
      @param pos Position of cached prime
      @return The element at position 'pos'
    */
    unsigned at(unsigned pos);

    /*!
      @param pos Position of cached prime
      @return The element at position 'pos'
    */
    unsigned operator[](unsigned pos);

    /*!
      Increases the nubmer of cached primes to all primes below, and
      including 'max'
      @param max Largest number to cache
    */
    void grow(unsigned max);

    /*!
      Gets the next prime after the largest currently cached
      @return Next largest prime
    */
    unsigned get_next();

    /*!
      Gets the closes prime number larger than 'start'
      @param start Point to begin looking for primes
      @return Next largest prime after 'start'
    */ 
    unsigned get_next(unsigned start);


  private:
    std::vector<unsigned> prime_numbers_;
  };

}

#endif
