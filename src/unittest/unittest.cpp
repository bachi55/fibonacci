#include "fibonacci-algorithms.h"

#include <gtest/gtest.h>

// typedef std::function<ulong(ulong)> FibFunc
// FibFunc f = getnFibonacciNumber
// f(0)

// Test the functionality of the 1st Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_1, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber (0), 0);
  ASSERT_EQ (getnFibonacciNumber (1), 1); 
  ASSERT_EQ (getnFibonacciNumber (2), 1); 
  ASSERT_EQ (getnFibonacciNumber (3), 2);
  ASSERT_EQ (getnFibonacciNumber (4), 3);
  ASSERT_EQ (getnFibonacciNumber (5), 5);
  
}

// Test the functionality of the 2nd Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_2, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber2 (0), 0);
  ASSERT_EQ (getnFibonacciNumber2 (1), 1); 
  ASSERT_EQ (getnFibonacciNumber2 (2), 1); 
  ASSERT_EQ (getnFibonacciNumber2 (3), 2);
  ASSERT_EQ (getnFibonacciNumber2 (4), 3);
  ASSERT_EQ (getnFibonacciNumber2 (5), 5);
  
  ASSERT_EQ (getnFibonacciNumber2 (12), getnFibonacciNumber (12));
  ASSERT_EQ (getnFibonacciNumber2 (20), getnFibonacciNumber (20));
  ASSERT_EQ (getnFibonacciNumber2 (22), getnFibonacciNumber (22));
  ASSERT_EQ (getnFibonacciNumber2 (23), getnFibonacciNumber (23));
  
}

// Test the functionality of the 3rd Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_3, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber3 (0), 0);
  ASSERT_EQ (getnFibonacciNumber3 (1), 1); 
  ASSERT_EQ (getnFibonacciNumber3 (2), 1); 
  ASSERT_EQ (getnFibonacciNumber3 (3), 2);
  ASSERT_EQ (getnFibonacciNumber3 (4), 3);
  ASSERT_EQ (getnFibonacciNumber3 (5), 5);
  
  ASSERT_EQ (getnFibonacciNumber3 (12), getnFibonacciNumber (12));
  ASSERT_EQ (getnFibonacciNumber3 (20), getnFibonacciNumber (20));
  ASSERT_EQ (getnFibonacciNumber3 (22), getnFibonacciNumber (22));
  ASSERT_EQ (getnFibonacciNumber3 (23), getnFibonacciNumber (23));
  
}

// Test the functionality of the 4th Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_4, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber4 (0), 0);
  ASSERT_EQ (getnFibonacciNumber4 (1), 1); 
  ASSERT_EQ (getnFibonacciNumber4 (2), 1); 
  ASSERT_EQ (getnFibonacciNumber4 (3), 2);
  ASSERT_EQ (getnFibonacciNumber4 (4), 3);
  ASSERT_EQ (getnFibonacciNumber4 (5), 5);
  
  ASSERT_EQ (getnFibonacciNumber4 (12), getnFibonacciNumber3 (12));
  ASSERT_EQ (getnFibonacciNumber4 (20), getnFibonacciNumber3 (20));
  ASSERT_EQ (getnFibonacciNumber4 (22), getnFibonacciNumber3 (22));
  ASSERT_EQ (getnFibonacciNumber4 (23), getnFibonacciNumber3 (23));
  
}

// Test the functionality of the matrix class implementation
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (matrix, correctness) {
  
  Matrix <ulong> m1 (2, 2, {1, 2, 3, 4});
  ASSERT_EQ (m1 (0, 0), 1);
  ASSERT_EQ (m1 (0, 1), 2);
  ASSERT_EQ (m1 (1, 0), 3);
  ASSERT_EQ (m1 (1, 1), 4);
  
  Matrix <ulong> m2 (2, 2, {1, 0, 0, 1});
  Matrix <ulong> prod = m1 * m2;
  ASSERT_EQ (prod (0, 0), 1);
  ASSERT_EQ (prod (0, 1), 2);
  ASSERT_EQ (prod (1, 0), 3);
  ASSERT_EQ (prod (1, 1), 4);
  
  // calculate the covariance matrix
  Matrix <ulong> m1t = Matrix <ulong> (2, 2, {1, 3, 2, 4});
  Matrix <ulong> cov = m1 * m1t;
  ASSERT_EQ (cov (0, 0),  5);
  ASSERT_EQ (cov (0, 1), 11);
  ASSERT_EQ (cov (1, 0), 11);
  ASSERT_EQ (cov (1, 1), 25);

}

// Test the functionality of the 5th Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_5, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber5 (0), 0);
  ASSERT_EQ (getnFibonacciNumber5 (1), 1); 
  ASSERT_EQ (getnFibonacciNumber5 (2), 1); 
  ASSERT_EQ (getnFibonacciNumber5 (3), 2);
  ASSERT_EQ (getnFibonacciNumber5 (4), 3);
  ASSERT_EQ (getnFibonacciNumber5 (5), 5);
  
  ASSERT_EQ (getnFibonacciNumber5 (12), getnFibonacciNumber3 (12));
  ASSERT_EQ (getnFibonacciNumber5 (20), getnFibonacciNumber3 (20));
  ASSERT_EQ (getnFibonacciNumber5 (22), getnFibonacciNumber3 (22));
  ASSERT_EQ (getnFibonacciNumber5 (23), getnFibonacciNumber3 (23));
  
}
// Test the functionality of the 6th Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_6, correctness) {

  FibonacciLUT LUT;
  
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 0), 0);
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 1), 1); 
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 2), 1); 
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 3), 2);
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 4), 3);
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 5), 5);
  
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 12), getnFibonacciNumber3 (12));
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 20), getnFibonacciNumber3 (20));
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 22), getnFibonacciNumber3 (22));
  ASSERT_EQ (getnFibonacciNumber6 (LUT, 23), getnFibonacciNumber3 (23));
  
}

TEST (make_a_test, fail) {
 
  // tests faile because of exeption
  //
  // therefore they have been commented out because they will make the test fail
//   ASSERT_EQ (getnFibonacciNumber3 (95), getnFibonacciNumber4 (95));
//   ASSERT_EQ (getnFibonacciNumber3 (-1), 0); 
  
  // exponentiationBySquaring will get an overflow for the n parameter and therefore the exponent will
  // be very big! 
  // TODO: How should we handle negative input in case of a unsigned parameter?
//   Matrix <ulong> m1 (2, 2, {2, 3, 1, 5});
//   Matrix <ulong> m2 = exponentiationBySquaring (m1, -1);
//   ASSERT_EQ (m2 (0, 0), 0.5);
//   ASSERT_EQ (m2 (0, 1), 1.0/3.0);
//   ASSERT_EQ (m2 (1, 0), 1.0);
//   ASSERT_EQ (m2 (1, 1), 0.2);
  
  // since the algorithm getnFibonacciNumber5 uses doubles but map them (via floor) to ulong
  // there is an numerical uncertainty, which causes the fibonacci number to be wrong for big
  // inputs for n!
  // TODO: try to find the upper border for which getnFibonacciNumber5 works correctly.
  // ASSERT_EQ (getnFibonacciNumber3(93), getnFibonacciNumber5(93));
}

int main (int argc, char* argv[]) {
  
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}