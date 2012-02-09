#ifndef __EULER_BIGINT_H__
#define __EULER_BIGINT_H__

#include <iostream>
#include <vector>
#include <string>

namespace projecteuler {

  class BigInt {
  public:
    BigInt();
    BigInt(int val);
    BigInt(long val);
    BigInt(long long val);
    BigInt(const char *val);
    BigInt(std::string val);

    ~BigInt();

    /*!
      @return Value of a string. (Negative numbers will be prefixed with a '-')
    */
    std::string value();

    /*!
      @return Total number of digits
    */
    unsigned int number_digits();

    /*!
      @return Total number of digits
    */
    unsigned int size();

    /*!
      position starts at 0
      @param position of digit to return
      @return Digit at a given position.
      @return Last digit if position is out of bounds
    */
    int get_digit(unsigned int position);

    /*!
      Gets the digit at a given position, starting at 0
      @param position of digit to return
      @return Digit at a given position.
      @return Last digit if position is out of bounds
    */
    int operator[](unsigned int position);

    bool operator>(BigInt b);
    bool operator<(BigInt b);
    bool operator==(BigInt b);
    bool operator!=(BigInt b);
    bool operator>=(BigInt b);
    bool operator<=(BigInt b);

    BigInt operator+(BigInt b);
    BigInt operator-(BigInt b);
    BigInt operator*(BigInt b);

    void operator++();
    void operator++(int);
    void operator--();
    void operator--(int);
    void operator+=(BigInt b);
    void operator-=(BigInt b);
    void operator*=(BigInt b);

    friend std::ostream& operator<<(std::ostream &output, BigInt &val);

    // Member Functions to implement
    // iterators

  private:
    std::vector<int> value_;
    bool negative_;

    /*!
      sets the class's value_ variable to digits stored in val
      @param val number as a string
     */
    void set_value(std::string val);

    /*!
      in two's complement, converts between positive and negative numbers
      @param val number to complement
    */
    void complement(std::vector<int> &val);

    /*!
      Compares two values, and integer indicating the larger one.
      @return -1 if left is larger
      @return 0 if equal
      @return 1 if right is larger
    */
    int compare(std::vector<int> &left, std::vector<int> &right);

    /*!
      Splits a BigInt roughly in half.
      @param in BigInt to be split
      @param out0 digits from top half of 'in'
      @param out1 digits from bottom half of 'in'
      @return the number of digits in 'out0'.
     */
    int split(BigInt &in, BigInt &out0, BigInt &out1);

    /*!
      @return True if number contains all 0's
      @return False otherwise
    */
    bool all_zero(std::vector<int> &val);

    /*!
      Increases the number of digits by adding zeros to the front of a number
      @param val Number to be increased
      @param increase Number of digits to increase by
    */
    void extend(BigInt &val, int increase); 

    /*!
      Adds zeros to end of the number. (val = val * 10^num)
      @param val Number to add zeros after
      @param num Number of zeros
    */
    void preappend(BigInt &val, int num);

    /*!
      Matches the number of digits in 'a' and 'b' by extending the smaller
    */
    void match_size_of_digits(BigInt &a, BigInt &b);

    /*!
      Removes unnecessary leading digits
    */
    void clean_leading_digits(BigInt &a);

    /*!
      Helper function to add value of 'b' into 'a'
      @param a value added to
      @param b value to add
    */
    void add_vector(std::vector<int> &a, std::vector<int> &b);

    /*!
      @param remainder (a + b) / 10
      @return (a + b) & 10
    */
    int add_digits(int a, int b, int &remainder);

    /*!
      This Karatsuba Implementation has only been tested with positive
      BigInts
      @return (a * b)
    */
    BigInt karatsuba(BigInt a, BigInt b);
  };

}

#endif
