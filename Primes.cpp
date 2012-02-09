#include "Primes.h"

namespace projecteuler {
  Primes::Primes() {
    prime_numbers_.push_back(2);
  }

  Primes::Primes(unsigned init) {
    if (init < 2)
      init = 2;

    std::vector<bool> tmp;

    for (unsigned i = 0; i <= init; ++i) 
      tmp.push_back(true);

    for (unsigned i = 2; i < tmp.size(); ++i) {
      if (tmp[i])
	prime_numbers_.push_back(i);

      for (unsigned j = i; j < tmp.size(); j += i)
	tmp[j] = false;
    }
  }

  Primes::~Primes() {
    prime_numbers_.clear();
  }

  unsigned Primes::size() {
    return prime_numbers_.size();
  }

  unsigned Primes::max() {
    return prime_numbers_.back();
  }

  unsigned Primes::back() {
    return prime_numbers_.back();
  }

  unsigned Primes::at(unsigned pos) {
    return prime_numbers_.at(pos);
  }

  unsigned Primes::operator[](unsigned pos) {
    return prime_numbers_[pos];
  }

  void Primes::grow(unsigned end) {
    unsigned start = this->max();
    if (end <= start)
      return;

    unsigned i, j, i_tmp, j_offset, j_start;
    std::vector<bool> tmp;

    for (i = start; i <= end; ++i )
      tmp.push_back(true);

    // remark with old primes
    for (i = 0; i < prime_numbers_.size(); ++i) {
      i_tmp = prime_numbers_[i];
      j_offset = start % i_tmp;
      j_start = (j_offset == 0)? start : start + i_tmp - j_offset;

      for (j = j_start; j < tmp.size() + start; j += i_tmp)
	tmp[j - start] = false;
    }

    // find the new primes
    for (i = start; i < tmp.size() + start; ++i) {
      if (tmp[i - start])
	prime_numbers_.push_back(i);
      
      for (j = i; j < tmp.size() + start; j += i)
	tmp[j - start] = false;
    }
  }

  unsigned Primes::get_next() {
    unsigned check = this->max();
    bool is_prime = true;

    do {
      is_prime = true;
      ++check;

      for (unsigned i = 0; i < this->size(); ++i)
	if (check % prime_numbers_[i] == 0) {
	  is_prime = false;
	  break;
	}

    } while(!is_prime);

    prime_numbers_.push_back(check);
    return check;
  }

  unsigned Primes::get_next(unsigned start) {

    if (start < this->max()) {
      // modified binary search to get the position
      int min = 0;
      int mid = 0;
      int max = prime_numbers_.size();

      do {
	mid = min + (max - min) / 2;
	
	if (prime_numbers_[mid] > start)
	  max = mid - 1;
	else
	  min = mid + 1;

      } while(prime_numbers_[mid] != start && min <= max);

      if (prime_numbers_[mid] <= start)
	++mid;

      return prime_numbers_[mid];
    }

    if (start > max())
      this->grow(start);

    return this->get_next();

  }

}
