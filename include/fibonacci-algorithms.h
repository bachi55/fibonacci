#ifndef FIBONACCI_ALGORITHMS_h
#define FIBONACCI_ALGORITHMS_h

#include <algorithm>
#include <cstdio>
#include <stdexcept>
#include <vector>

typedef unsigned int uint;
typedef unsigned long ulong;

// Function to calculate the n-th Fibonacci 
//
// This algorithm is derived from the definition
ulong getnFibonacciNumber (uint n);

// Function to calculate the n-th Fibonacci
//
// This implementation uses linear memory in n and runs in lineare time 
// n.
ulong getnFibonacciNumber2 (uint n);

// Function to calculate the n-th Fibonacci
//
// This implementation uses constant and runs in lineare time 
// n.
ulong getnFibonacciNumber3 (uint n);

#endif