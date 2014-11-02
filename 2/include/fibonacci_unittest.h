#ifndef FIBONACCI_UNITTEST_H
#define FIBONACCI_UNITTEST_H

#include <gtest/gtest.h>

/// Test the functionality of the 1st Fibonacci Number Algorithm
///
/// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_1, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber (0), 0);
  ASSERT_EQ (getnFibonacciNumber (1), 1); 
  ASSERT_EQ (getnFibonacciNumber (2), 1); 
  ASSERT_EQ (getnFibonacciNumber (3), 2);
  ASSERT_EQ (getnFibonacciNumber (4), 3);
  ASSERT_EQ (getnFibonacciNumber (5), 5);
  
}

/// Test the functionality of the 2nd Fibonacci Number Algorithm
///
/// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_2, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber2 (0), 0);
  ASSERT_EQ (getnFibonacciNumber2 (1), 1); 
  ASSERT_EQ (getnFibonacciNumber2 (2), 1); 
  ASSERT_EQ (getnFibonacciNumber2 (3), 2);
  ASSERT_EQ (getnFibonacciNumber2 (4), 3);
  ASSERT_EQ (getnFibonacciNumber2 (5), 5);
  
}

/// Test the functionality of the 3rd Fibonacci Number Algorithm
///
/// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_3, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber3 (0), 0);
  ASSERT_EQ (getnFibonacciNumber3 (1), 1); 
  ASSERT_EQ (getnFibonacciNumber3 (2), 1); 
  ASSERT_EQ (getnFibonacciNumber3 (3), 2);
  ASSERT_EQ (getnFibonacciNumber3 (4), 3);
  ASSERT_EQ (getnFibonacciNumber3 (5), 5);
  
}

#endif