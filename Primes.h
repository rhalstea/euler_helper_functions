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
