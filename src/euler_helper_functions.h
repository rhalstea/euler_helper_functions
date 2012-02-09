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
