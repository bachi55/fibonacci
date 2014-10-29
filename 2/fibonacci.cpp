#include "fibonacci.h"
/// Excluding this header file  would lead to 0 tests,
/// but would not prevent gtest to try to run a test.
#include "fibonacci_unittest.h"
#include <cstdio>
#include <gtest/gtest.h>

/// Function containing the functionality RUN_ALL_TESTS
///
/// This function has to have a void return value, to run the tests!
/// Using this function (or the way of invoking the test) does not 
/// require 'testing::InitGoogleTest'.
void unittest () {
 
  ASSERT_EQ (getnFibonacciNumber (0), 0);
  ASSERT_EQ (getnFibonacciNumber (1), 1); 
  ASSERT_EQ (getnFibonacciNumber (2), 1); 
  ASSERT_EQ (getnFibonacciNumber (3), 2);
  ASSERT_EQ (getnFibonacciNumber (4), 3);
  ASSERT_EQ (getnFibonacciNumber (5), 5);
  
}

int main (int argc, char* argv[]) {
  
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  
  //unittest();
  //return 0;
  
}

/// Implementation, see header-file for description
int getnFibonacciNumber (int n) {
    
  if (n == 0) return 0;
  if (n == 1) return 1; 
  
  return getnFibonacciNumber (n - 1) + getnFibonacciNumber (n - 2);
  
}