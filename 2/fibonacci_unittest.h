#ifndef FIBONACCI_UNITTEST_H
#define FIBONACCI_UNITTEST_H

#include "fibonacci.h"
#include <gtest/gtest.h>

/// Test the functionality of the 1st Fibonacci Number Algorithm
///
/// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber (0), 0);
  ASSERT_EQ (getnFibonacciNumber (1), 1); 
  ASSERT_EQ (getnFibonacciNumber (2), 1); 
  ASSERT_EQ (getnFibonacciNumber (3), 2);
  ASSERT_EQ (getnFibonacciNumber (4), 3);
  ASSERT_EQ (getnFibonacciNumber (5), 5);
  
}

#endif