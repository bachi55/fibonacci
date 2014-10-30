#include "fibonacci.h"
/// Excluding this header file  would lead to 0 tests,
/// but would not prevent gtest to try to run a test.
#include "fibonacci_unittest.h"

#include <algorithm>
#include <cstdio>
#include <exception>
#include <vector>

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
  
  int result;
  
//   unittest();
  
  try {
   
    result = RUN_ALL_TESTS();
    
  } catch (std::runtime_error& ermsg) {
   
    fprintf (stdout, "Runtime-Error occured: %s\n", ermsg.what());
    
    return result;
    
  }
  
  return result;
  
}

/// Implementation; see header-file for description
int getnFibonacciNumber (int n) {

  if (n < 0) throw std::runtime_error ("Invalid Input: no negative number allowed!");
  
  if (n < 2) return n; 
  
  return getnFibonacciNumber (n - 1) + getnFibonacciNumber (n - 2);
  
}

/// Implementation; see header-file for description
int getnFibonacciNumber2 ( int n ) {
  
  if (n < 0) throw std::runtime_error ("Invalid Input: no negative number allowed!");
  
  if (n < 2) return n;
  
  std::vector <int> res (n + 1);
  res[0] = 0; res[1] = 1;
  
  for (int i = 2; i < res.size(); i++) {
   
    res[i] = res[i - 1] + res[i - 2];
    
  }
  
  return res[res.size() - 1];
  
}
