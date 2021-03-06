#ifndef FIBONACCI_ALGORITHMS_h
#define FIBONACCI_ALGORITHMS_h

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <sys/types.h>
#include <vector>

#include "matrix.h"

class FibonacciLUT {
  uint _nMax;
  std::vector <ulong> _LUT;
  
  
public:
  // constructor
  FibonacciLUT (uint nMax=93);
  
  // get nth Fibonacci number
  ulong lookfor (uint n) const;
};

// Function to calculate the n-th Fibonacci 
//
// This algorithm is derived from the definition
ulong getnFibonacciNumber (uint n);

// Function to calculate the n-th Fibonacci
//
// This implementation uses linear memory in n and runs in lineare time n.
ulong getnFibonacciNumber2 (uint n);

// Function to calculate the n-th Fibonacci
//
// This implementation uses constant memory and runs in lineare time n.
ulong getnFibonacciNumber3 (uint n);

// Function to calculate the n-th Fibonacci
//
// This implementation uses exponentiation by squaring.
ulong getnFibonacciNumber4 (uint n);

// Function which realizes the exponentiation by squaring for Matrix <ulong>.
//
// TODO: check for rvalue moving? 
// TODO: check for template!
Matrix <ulong> exponentiationBySquaring (Matrix <ulong> x, uint n);

// Function to calculate the n-th Fibonacci
//
// This implementation uses the formula derived from the eigenvectors. 
ulong getnFibonacciNumber5 (uint n);

// Function which realizes the exponentiation by squaring for double.
//
// TODO: check for template!
double exponentiationBySquaring (double x, uint n);

// Function to looks up the n-th Fibonacci
//
// The LUT needs to be initialized beforehand.
ulong getnFibonacciNumber6 (const FibonacciLUT& LUT, uint n);

// Function which realizes the exponentiation by squaring for Matrix <ulong> in an itterative manner
Matrix <ulong> exponentiationBySquaring_iterativ (Matrix <ulong> x, uint n);

// Function to calculate the n-th Fibonacci
//
// This function uses an iterative implementation of the exponentiation by squaring algorithm.
ulong getnFibonacciNumber7 (uint n);

#endif