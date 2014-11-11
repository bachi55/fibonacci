#ifndef FIBONACCI_ALGORITHMS_h
#define FIBONACCI_ALGORITHMS_h

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <stdexcept>
#include <sys/types.h>
#include <vector>

#include "matrix.h"

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
// TODO: check for rvalue moving? 
// TODO: check for template!
double exponentiationBySquaring (double x, uint n);

// Function to calculate the n-th Fibonacci
//
// This implementation creates a look up table at compile time.
// constexpr ulong getnFibonacciNumber6 (uint n);
// 
// ulong getnFibonacciNumberLUT (uint n);

#endif