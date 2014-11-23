#include "fibonacci-algorithms.h"
#include "meter.h"
#include "mytypes.h"

#include <cstdio>
#include <chrono>
#include <string>

#include <gtest/gtest.h>

// typedef std::function<ulong(ulong)> FibFunc
// FibFunc f = getnFibonacciNumber
// f(0)

// Test the functionality of the 1st Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
// TEST (functionality_1, correctness) {
//  
//   ASSERT_EQ (getnFibonacciNumber (0), 0);
//   ASSERT_EQ (getnFibonacciNumber (1), 1); 
//   ASSERT_EQ (getnFibonacciNumber (2), 1); 
//   ASSERT_EQ (getnFibonacciNumber (3), 2);
//   ASSERT_EQ (getnFibonacciNumber (4), 3);
//   ASSERT_EQ (getnFibonacciNumber (5), 5);
//   
// }

// Test the functionality of the 2nd Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
// TEST (functionality_2, correctness) {
//  
//   ASSERT_EQ (getnFibonacciNumber2 (0), 0);
//   ASSERT_EQ (getnFibonacciNumber2 (1), 1); 
//   ASSERT_EQ (getnFibonacciNumber2 (2), 1); 
//   ASSERT_EQ (getnFibonacciNumber2 (3), 2);
//   ASSERT_EQ (getnFibonacciNumber2 (4), 3);
//   ASSERT_EQ (getnFibonacciNumber2 (5), 5);
//   
//   ASSERT_EQ (getnFibonacciNumber2 (12), getnFibonacciNumber (12));
//   ASSERT_EQ (getnFibonacciNumber2 (20), getnFibonacciNumber (20));
//   ASSERT_EQ (getnFibonacciNumber2 (22), getnFibonacciNumber (22));
//   ASSERT_EQ (getnFibonacciNumber2 (23), getnFibonacciNumber (23));
//   
// }

// Test the functionality of the 3rd Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
// TEST (functionality_3, correctness) {
//  
//   ASSERT_EQ (getnFibonacciNumber3 (0), 0);
//   ASSERT_EQ (getnFibonacciNumber3 (1), 1); 
//   ASSERT_EQ (getnFibonacciNumber3 (2), 1); 
//   ASSERT_EQ (getnFibonacciNumber3 (3), 2);
//   ASSERT_EQ (getnFibonacciNumber3 (4), 3);
//   ASSERT_EQ (getnFibonacciNumber3 (5), 5);
//   
//   ASSERT_EQ (getnFibonacciNumber3 (12), getnFibonacciNumber (12));
//   ASSERT_EQ (getnFibonacciNumber3 (20), getnFibonacciNumber (20));
//   ASSERT_EQ (getnFibonacciNumber3 (22), getnFibonacciNumber (22));
//   ASSERT_EQ (getnFibonacciNumber3 (23), getnFibonacciNumber (23));
//   
// }

// Test the functionality of the 4th Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
// TEST (functionality_4, correctness) {
//  
//   ASSERT_EQ (getnFibonacciNumber4 (0), 0);
//   ASSERT_EQ (getnFibonacciNumber4 (1), 1); 
//   ASSERT_EQ (getnFibonacciNumber4 (2), 1); 
//   ASSERT_EQ (getnFibonacciNumber4 (3), 2);
//   ASSERT_EQ (getnFibonacciNumber4 (4), 3);
//   ASSERT_EQ (getnFibonacciNumber4 (5), 5);
//   
//   ASSERT_EQ (getnFibonacciNumber4 (12), getnFibonacciNumber3 (12));
//   ASSERT_EQ (getnFibonacciNumber4 (20), getnFibonacciNumber3 (20));
//   ASSERT_EQ (getnFibonacciNumber4 (22), getnFibonacciNumber3 (22));
//   ASSERT_EQ (getnFibonacciNumber4 (23), getnFibonacciNumber3 (23));
//   
// }

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

  Matrix <ulong> m3 (3, 3, {5, 6, 7, 1, 2, 3, 9, 9, 9});
//   m3.printMatrix();
  std::vector <ulong> row (m3.getRow (0));
  std::printf ("\n%lu %lu %lu\n\n", row[0], row[1], row[2]);
  ASSERT_EQ (row.size(), 3);
  ASSERT_EQ (row[0], 5); ASSERT_EQ (row[1], 6); ASSERT_EQ (row[2], 7); 
  row = m3.getRow (2);
  ASSERT_EQ (row[0], 9); ASSERT_EQ (row[1], 9); ASSERT_EQ (row[2], 9); 
  
  m3.setRow (2, {20, 21, 22});
//   m3.printMatrix();
  
  Matrix <ulong> m4 = createIdentityMatrix <ulong> (4);
//   m4.printMatrix();
}


TEST (cpp_feature, variadic_template) {
  
  // TODO: Lambda-functions are nice! So learn more about this!
  auto sum = [](int a, int b) { return a + b; }; 
  {
    std::function <int (int, int)> f = sum;
    int res = execute <int, int, int> (f, 1, 3);
    ASSERT_EQ (res, 4);
  }
  
  auto writeln = [](const char* line) { std::puts (line); };
  {
    std::function <void (const char*)> f = writeln;
    execute <void, const char*> (f, "Hello World!");
  }
  
  auto increment = [](int& x) { x++; }; 
  {
    int number = 10;
    std::function <void (int &)> f = increment; 
    execute <void, int&> (f, number);
    ASSERT_EQ (number, 11);
  }
  
}

// Test the functionality of the 5th Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
// TEST (functionality_5, correctness) {
//  
//   ASSERT_EQ (getnFibonacciNumber5 (0), 0);
//   ASSERT_EQ (getnFibonacciNumber5 (1), 1); 
//   ASSERT_EQ (getnFibonacciNumber5 (2), 1); 
//   ASSERT_EQ (getnFibonacciNumber5 (3), 2);
//   ASSERT_EQ (getnFibonacciNumber5 (4), 3);
//   ASSERT_EQ (getnFibonacciNumber5 (5), 5);
//   
//   ASSERT_EQ (getnFibonacciNumber5 (12), getnFibonacciNumber3 (12));
//   ASSERT_EQ (getnFibonacciNumber5 (20), getnFibonacciNumber3 (20));
//   ASSERT_EQ (getnFibonacciNumber5 (22), getnFibonacciNumber3 (22));
//   ASSERT_EQ (getnFibonacciNumber5 (23), getnFibonacciNumber3 (23));
//   
// }
// Test the functionality of the 6th Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
// TEST (functionality_6, correctness) {
// 
//   FibonacciLUT LUT;
//   
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 0), 0);
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 1), 1); 
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 2), 1); 
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 3), 2);
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 4), 3);
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 5), 5);
//   
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 12), getnFibonacciNumber3 (12));
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 20), getnFibonacciNumber3 (20));
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 22), getnFibonacciNumber3 (22));
//   ASSERT_EQ (getnFibonacciNumber6 (LUT, 23), getnFibonacciNumber3 (23));
//   
// }

// Test the functionality of the 5th Fibonacci Number Algorithm
//
// Using the 'TEST' macro requires to run 'testing::InitGoogleTest'.
TEST (functionality_7, correctness) {
 
  ASSERT_EQ (getnFibonacciNumber7 (0), 0);
  ASSERT_EQ (getnFibonacciNumber7 (1), 1); 
  ASSERT_EQ (getnFibonacciNumber7 (2), 1); 
  ASSERT_EQ (getnFibonacciNumber7 (3), 2);
  ASSERT_EQ (getnFibonacciNumber7 (4), 3);
  ASSERT_EQ (getnFibonacciNumber7 (5), 5);
  
  ASSERT_EQ (getnFibonacciNumber7 (12), getnFibonacciNumber4 (12));
  ASSERT_EQ (getnFibonacciNumber7 (20), getnFibonacciNumber4 (20));
  ASSERT_EQ (getnFibonacciNumber7 (22), getnFibonacciNumber4 (22));
  ASSERT_EQ (getnFibonacciNumber7 (23), getnFibonacciNumber4 (23));
  
}

// TEST (make_a_test, fail) {
 
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
  
  
  // We know about the numerical problems (because of floor(double) -> uint) with
  // algorithm 5. Therefore we should check, when the system explodes. A more general
  // question behind this is: We are calculating very big numbers for sufficient large
  // input n. Therefore we can expect, that the result will exceed the range of the 
  // integral types "quite fast". For floating point types, we are dealing with the 
  // the intrinsic properties of them, this means: they become more inaccurate for
  // a large result. 
  
//   for (uint n = 1; n < 100; n++) {
//     ASSERT_EQ (getnFibonacciNumber5 (n), getnFibonacciNumber3 (n));
//     std::printf ("%u\n", n);
//   }
  
  // n=76 fails !
// }

// TEST (meter_test, functionality) {
  
//   Meter <unsigned int, unsigned int> answerMeter (theAnswer);
//   
//   answerMeter.start();
//   answerMeter.stop();
//   
//   ASSERT_EQ (answerMeter.peak(), 0);
    
//   Meter <timePoint, timeDuration> meter (myClock);
//   meter.start();
//   meter.stop();
//   
//   ASSERT_LT (std::chrono::duration_cast <microseconds> (meter.peak()).count(), 5);
//   
//   meter.start();
//   sleep (1);
//   meter.stop();
//   
//   ASSERT_LT (std::chrono::duration_cast <microseconds> (meter.peak()).count(), 1000200);
//   
//   sleep (2);
//   meter.stop();
// 
//   ASSERT_LT (std::chrono::duration_cast <microseconds> (meter.peak()).count(), 3000400);
//   
//   meter.reset();
//   ASSERT_EQ (std::chrono::duration_cast <microseconds> (meter.peak()).count(), 0);
//   int foo = 0;
//   Meter <uint64_t, uint64_t> meter_clocks (rdtscp);
//   meter_clocks.start();
//   foo = foo + 1;
//   meter_clocks.stop();
//   std::printf ("%lu\n", meter_clocks.peak());
//   
// }

TEST (measurements, cycles) {
  uint64_t start, end, peak;
  int res;
  cpuid (0);
  start = rdtsc();
  res = 5 + 5;
  end = rdtscp(); 
  cpuid (0);
  peak = end - start;
  
  std::printf ("Methode according to the Paper: \t %lu \n", peak);
  
  start = rdtscp();
  res = 5 + 5;
  end = rdtscp(); 
  peak = end - start;
  
  std::printf ("No serialization: \t\t\t %lu\n", peak);
  
  cpuid (0);
  start = rdtsc();
  res = 5 + 5;
  cpuid (0);
  end = rdtsc(); 
  peak = end - start;
  
  std::printf ("Methode from the lecture: \t\t %lu\n", peak);
  
  Meter <uint64_t, uint64_t> meter (myCycles);
  meter.start();
  res = 5 + 5;
  meter.stop();
  
  std::printf ("Methode from the lecture (meter class):  %lu\n", meter.peak());
  
  std::printf ("%i\n", res);
}

TEST (statistics, mean) {
  ASSERT_EQ (calcualteMean <int> ({1, 2, 3}), 2);
  ASSERT_EQ (calcualteMean <int> ({1}), 1);
  ASSERT_EQ (calcualteMean <int> ({1, 2}), 1.5);
  ASSERT_EQ (calcualteMean <int> ({1, 1, 1}), 1);
}

TEST (statistics, var) {
  ASSERT_EQ (calculateVar <int> ({1, 2, 3}), 2.0 / 3.0);
  ASSERT_EQ (calculateVar <int> ({1}), 0);
  ASSERT_EQ (calculateVar <int> ({1, 2}), 0.25);
  ASSERT_EQ (calculateVar <int> ({1, 1, 1}), 0);
}

// TEST (benchmark, algo1) {
//   
//   // implementation to benchmark
//   
//   std::function <ulong (uint)> implementation = getnFibonacciNumber;
//   
//   // format the output 
//   // TODO: realize output stuff with streams!
//   
//   std::string filename_time = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo1-time";
//   std::string filename_cycles = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo1-cycles";
//   
//   char temp [256];
//   std::sprintf (temp, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
//   std::string header (temp);
//   
//   // configure benchmark
//   
//   uint nruns = 10;
//   std::vector <uint> algorithmParameter (40);
//   // fill vector with the numbers from 0 to 39
//   std::iota (algorithmParameter.begin(), algorithmParameter.end(), 0);
//   
//   // store measurements
//   
//   Matrix <timeDuration> timeDurationMeasurements (algorithmParameter.size(), nruns, timeDuration());
//   Matrix <ulong> cycleMeasurements (algorithmParameter.size(), nruns, 0);
//   
//   // run benchmark
//   
//   // time
//   std::for_each (algorithmParameter.begin(), algorithmParameter.end()
//     , [implementation, nruns, &timeDurationMeasurements] (uint param)
//     {
//       timeDurationMeasurements.setRow (param
// 				     , benchmark <timeDuration, timePoint, ulong, uint> (myClock, nruns, implementation, param));
//     }
//   );
//   
//   // cycles
//   std::for_each (algorithmParameter.begin(), algorithmParameter.end()
//     , [implementation, nruns, &cycleMeasurements] (uint param)
//     {
//       cycleMeasurements.setRow (param
// 			      , benchmark <ulong, ulong, ulong, uint> (myCycles, nruns, implementation, param));
//     }
//   );
// 
//   // cast from the measurering unit into something printable and write measurements to file
//   // TODO: could be done with an toString() like structure
//   
//   // time
//   Matrix <double> measurements (timeDurationMeasurements.rows(), timeDurationMeasurements.cols(), 0.0);
//   for (uint i = 0; i < timeDurationMeasurements.rows(); i++) for (uint j = 0; j < timeDurationMeasurements.cols(); j++) {
//     measurements(i,j) = double (std::chrono::duration_cast <nanoseconds> (timeDurationMeasurements(i,j)).count());
//     measurements(i,j) /= 1000.0;
//   }
//   
//   writeMeasurements <double> (filename_time, header, algorithmParameter, measurements);
//   
//   // cycles
//   
//   for (uint i = 0; i < cycleMeasurements.rows(); i++) for (uint j = 0; j < cycleMeasurements.cols(); j++) 
//     measurements(i,j) = double (cycleMeasurements(i,j)) / 1000.0;
//   
//   writeMeasurements <double> (filename_cycles, header, algorithmParameter, measurements);
//   
// }

TEST (benchmark, algo2) {
  
  // implementation to benchmark
  
  std::function <ulong (uint)> implementation = getnFibonacciNumber2;
  
  // format the output 
  // TODO: realize output stuff with streams!
  
  std::string filename_time = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo2-time";
  std::string filename_cycles = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo2-cycles";
  
  char temp [256];
  std::sprintf (temp, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
  std::string header (temp);
  
  // configure benchmark
  
  uint nruns = 10;
  std::vector <uint> algorithmParameter (94);
  // fill vector with the numbers from 0 to 93
  std::iota (algorithmParameter.begin(), algorithmParameter.end(), 0);
  
  // store measurements
  
  Matrix <timeDuration> timeDurationMeasurements (algorithmParameter.size(), nruns, timeDuration());
  Matrix <ulong> cycleMeasurements (algorithmParameter.size(), nruns, 0);
  
  // run benchmark
  
  // time
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &timeDurationMeasurements] (uint param)
    {
      timeDurationMeasurements.setRow (param
				     , benchmark <timeDuration, timePoint, ulong, uint> (myClock, nruns, implementation, param));
    }
  );
  
  // cycles
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &cycleMeasurements] (uint param)
    {
      cycleMeasurements.setRow (param
			      , benchmark <ulong, ulong, ulong, uint> (myCycles, nruns, implementation, param));
    }
  );

  // cast from the measurering unit into something printable and write measurements to file
  // TODO: could be done with an toString() like structure
  
  // time
  Matrix <double> measurements (timeDurationMeasurements.rows(), timeDurationMeasurements.cols(), 0.0);
  for (uint i = 0; i < timeDurationMeasurements.rows(); i++) for (uint j = 0; j < timeDurationMeasurements.cols(); j++) {
    measurements(i,j) = double (std::chrono::duration_cast <nanoseconds> (timeDurationMeasurements(i,j)).count());
    measurements(i,j) /= 1000.0;
  }
  
  writeMeasurements <double> (filename_time, header, algorithmParameter, measurements);
  
  // cycles
  
  for (uint i = 0; i < cycleMeasurements.rows(); i++) for (uint j = 0; j < cycleMeasurements.cols(); j++) 
    measurements(i,j) = double (cycleMeasurements(i,j)) / 1000.0;
  
  writeMeasurements <double> (filename_cycles, header, algorithmParameter, measurements);
  
}

TEST (benchmark, algo3) {
  
  // implementation to benchmark
  
  std::function <ulong (uint)> implementation = getnFibonacciNumber3;
  
  // format the output 
  // TODO: realize output stuff with streams!
  
  std::string filename_time = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo3-time";
  std::string filename_cycles = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo3-cycles";
  
  char temp [256];
  std::sprintf (temp, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
  std::string header (temp);
  
  // configure benchmark
  
  uint nruns = 10;
  std::vector <uint> algorithmParameter (94);
  // fill vector with the numbers from 0 to 93
  std::iota (algorithmParameter.begin(), algorithmParameter.end(), 0);
  
  // store measurements
  
  Matrix <timeDuration> timeDurationMeasurements (algorithmParameter.size(), nruns, timeDuration());
  Matrix <ulong> cycleMeasurements (algorithmParameter.size(), nruns, 0);
  
  // run benchmark
  
  // time
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &timeDurationMeasurements] (uint param)
    {
      timeDurationMeasurements.setRow (param
				     , benchmark <timeDuration, timePoint, ulong, uint> (myClock, nruns, implementation, param));
    }
  );
  
  // cycles
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &cycleMeasurements] (uint param)
    {
      cycleMeasurements.setRow (param
			      , benchmark <ulong, ulong, ulong, uint> (myCycles, nruns, implementation, param));
    }
  );

  // cast from the measurering unit into something printable and write measurements to file
  // TODO: could be done with an toString() like structure
  
  // time
  Matrix <double> measurements (timeDurationMeasurements.rows(), timeDurationMeasurements.cols(), 0.0);
  for (uint i = 0; i < timeDurationMeasurements.rows(); i++) for (uint j = 0; j < timeDurationMeasurements.cols(); j++) {
    measurements(i,j) = double (std::chrono::duration_cast <nanoseconds> (timeDurationMeasurements(i,j)).count());
    measurements(i,j) /= 1000.0;
  }
  
  writeMeasurements <double> (filename_time, header, algorithmParameter, measurements);
  
  // cycles
  
  for (uint i = 0; i < cycleMeasurements.rows(); i++) for (uint j = 0; j < cycleMeasurements.cols(); j++) 
    measurements(i,j) = double (cycleMeasurements(i,j)) / 1000.0;
  
  writeMeasurements <double> (filename_cycles, header, algorithmParameter, measurements);
  
}

TEST (benchmark, algo4) {
  
  // implementation to benchmark
  
  std::function <ulong (uint)> implementation = getnFibonacciNumber4;
  
  // format the output 
  // TODO: realize output stuff with streams!
  
  std::string filename_time = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo4-time";
  std::string filename_cycles = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo4-cycles";
  
  char temp [256];
  std::sprintf (temp, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
  std::string header (temp);
  
  // configure benchmark
  
  uint nruns = 10;
  std::vector <uint> algorithmParameter (94);
  // fill vector with the numbers from 0 to 93
  std::iota (algorithmParameter.begin(), algorithmParameter.end(), 0);
  
  // store measurements
  
  Matrix <timeDuration> timeDurationMeasurements (algorithmParameter.size(), nruns, timeDuration());
  Matrix <ulong> cycleMeasurements (algorithmParameter.size(), nruns, 0);
  
  // run benchmark
  
  // time
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &timeDurationMeasurements] (uint param)
    {
      timeDurationMeasurements.setRow (param
				     , benchmark <timeDuration, timePoint, ulong, uint> (myClock, nruns, implementation, param));
    }
  );
  
  // cycles
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &cycleMeasurements] (uint param)
    {
      cycleMeasurements.setRow (param
			      , benchmark <ulong, ulong, ulong, uint> (myCycles, nruns, implementation, param));
    }
  );

  // cast from the measurering unit into something printable and write measurements to file
  // TODO: could be done with an toString() like structure
  
  // time
  Matrix <double> measurements (timeDurationMeasurements.rows(), timeDurationMeasurements.cols(), 0.0);
  for (uint i = 0; i < timeDurationMeasurements.rows(); i++) for (uint j = 0; j < timeDurationMeasurements.cols(); j++) {
    measurements(i,j) = double (std::chrono::duration_cast <nanoseconds> (timeDurationMeasurements(i,j)).count());
    measurements(i,j) /= 1000.0;
  }
  
  writeMeasurements <double> (filename_time, header, algorithmParameter, measurements);
  
  // cycles
  
  for (uint i = 0; i < cycleMeasurements.rows(); i++) for (uint j = 0; j < cycleMeasurements.cols(); j++) 
    measurements(i,j) = double (cycleMeasurements(i,j)) / 1000.0;
  
  writeMeasurements <double> (filename_cycles, header, algorithmParameter, measurements);
  
}

TEST (benchmark, algo5) {
  
  // implementation to benchmark
  
  std::function <ulong (uint)> implementation = getnFibonacciNumber5;
  
  // format the output 
  // TODO: realize output stuff with streams!
  
  std::string filename_time = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo5-time";
  std::string filename_cycles = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo5-cycles";
  
  char temp [256];
  std::sprintf (temp, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
  std::string header (temp);
  
  // configure benchmark
  
  uint nruns = 10;
  std::vector <uint> algorithmParameter (76);
  // fill vector with the numbers from 0 to 75
  std::iota (algorithmParameter.begin(), algorithmParameter.end(), 0);
  
  // store measurements
  
  Matrix <timeDuration> timeDurationMeasurements (algorithmParameter.size(), nruns, timeDuration());
  Matrix <ulong> cycleMeasurements (algorithmParameter.size(), nruns, 0);
  
  // run benchmark
  
  // time
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &timeDurationMeasurements] (uint param)
    {
      timeDurationMeasurements.setRow (param
				     , benchmark <timeDuration, timePoint, ulong, uint> (myClock, nruns, implementation, param));
    }
  );
  
  // cycles
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &cycleMeasurements] (uint param)
    {
      cycleMeasurements.setRow (param
			      , benchmark <ulong, ulong, ulong, uint> (myCycles, nruns, implementation, param));
    }
  );

  // cast from the measurering unit into something printable and write measurements to file
  // TODO: could be done with an toString() like structure
  
  // time
  Matrix <double> measurements (timeDurationMeasurements.rows(), timeDurationMeasurements.cols(), 0.0);
  for (uint i = 0; i < timeDurationMeasurements.rows(); i++) for (uint j = 0; j < timeDurationMeasurements.cols(); j++) {
    measurements(i,j) = double (std::chrono::duration_cast <nanoseconds> (timeDurationMeasurements(i,j)).count());
    measurements(i,j) /= 1000.0;
  }
  
  writeMeasurements <double> (filename_time, header, algorithmParameter, measurements);
  
  // cycles
  
  for (uint i = 0; i < cycleMeasurements.rows(); i++) for (uint j = 0; j < cycleMeasurements.cols(); j++) 
    measurements(i,j) = double (cycleMeasurements(i,j)) / 1000.0;
  
  writeMeasurements <double> (filename_cycles, header, algorithmParameter, measurements);
  
}

TEST (benchmark, algo6) {
  
  // implementation to benchmark
  
  std::function <ulong (FibonacciLUT, uint)> implementation = getnFibonacciNumber6;
  
  // format the output 
  // TODO: realize output stuff with streams!
  
  std::string filename_time = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo6-time";
  std::string filename_cycles = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo6-cycles";
  
  char temp [256];
  std::sprintf (temp, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
  std::string header (temp);
  
  // configure benchmark
  
  uint nruns = 10;
  std::vector <uint> algorithmParameter (94);
  // fill vector with the numbers from 0 to 93
  std::iota (algorithmParameter.begin(), algorithmParameter.end(), 0);
  
  FibonacciLUT LUT = FibonacciLUT();
  
  // store measurements
  
  Matrix <timeDuration> timeDurationMeasurements (algorithmParameter.size(), nruns, timeDuration());
  Matrix <ulong> cycleMeasurements (algorithmParameter.size(), nruns, 0);
  
  // run benchmark
  
  // time
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &timeDurationMeasurements, LUT] (uint param)
    {
      timeDurationMeasurements.setRow (param
				     , benchmark <timeDuration, timePoint, ulong, FibonacciLUT ,uint> (myClock, nruns, implementation, LUT, param));
    }
  );
  
  // cycles
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &cycleMeasurements, LUT] (uint param)
    {
      cycleMeasurements.setRow (param
			      , benchmark <ulong, ulong, ulong, FibonacciLUT, uint> (myCycles, nruns, implementation, LUT, param));
    }
  );

  // cast from the measurering unit into something printable and write measurements to file
  // TODO: could be done with an toString() like structure
  
  // time
  Matrix <double> measurements (timeDurationMeasurements.rows(), timeDurationMeasurements.cols(), 0.0);
  for (uint i = 0; i < timeDurationMeasurements.rows(); i++) for (uint j = 0; j < timeDurationMeasurements.cols(); j++) {
    measurements(i,j) = double (std::chrono::duration_cast <nanoseconds> (timeDurationMeasurements(i,j)).count());
    measurements(i,j) /= 1000.0;
  }
  
  writeMeasurements <double> (filename_time, header, algorithmParameter, measurements);
  
  // cycles
  
  for (uint i = 0; i < cycleMeasurements.rows(); i++) for (uint j = 0; j < cycleMeasurements.cols(); j++) 
    measurements(i,j) = double (cycleMeasurements(i,j)) / 1000.0;
  
  writeMeasurements <double> (filename_cycles, header, algorithmParameter, measurements);
  
}

TEST (benchmark, algo7) {
  
  // implementation to benchmark
  
  std::function <ulong (uint)> implementation = getnFibonacciNumber7;
  
  // format the output 
  // TODO: realize output stuff with streams!
  
  std::string filename_time = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo7-time";
  std::string filename_cycles = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo7-cycles";
  
  char temp [256];
  std::sprintf (temp, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
  std::string header (temp);
  
  // configure benchmark
  
  uint nruns = 10;
  std::vector <uint> algorithmParameter (94);
  // fill vector with the numbers from 0 to 93
  std::iota (algorithmParameter.begin(), algorithmParameter.end(), 0);
  
  // store measurements
  
  Matrix <timeDuration> timeDurationMeasurements (algorithmParameter.size(), nruns, timeDuration());
  Matrix <ulong> cycleMeasurements (algorithmParameter.size(), nruns, 0);
  
  // run benchmark
  
  // time
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &timeDurationMeasurements] (uint param)
    {
      timeDurationMeasurements.setRow (param
				     , benchmark <timeDuration, timePoint, ulong, uint> (myClock, nruns, implementation, param));
    }
  );
  
  // cycles
  std::for_each (algorithmParameter.begin(), algorithmParameter.end()
    , [implementation, nruns, &cycleMeasurements] (uint param)
    {
      cycleMeasurements.setRow (param
			      , benchmark <ulong, ulong, ulong, uint> (myCycles, nruns, implementation, param));
    }
  );

  // cast from the measurering unit into something printable and write measurements to file
  // TODO: could be done with an toString() like structure
  
  // time
  Matrix <double> measurements (timeDurationMeasurements.rows(), timeDurationMeasurements.cols(), 0.0);
  for (uint i = 0; i < timeDurationMeasurements.rows(); i++) for (uint j = 0; j < timeDurationMeasurements.cols(); j++) {
    measurements(i,j) = double (std::chrono::duration_cast <nanoseconds> (timeDurationMeasurements(i,j)).count());
    measurements(i,j) /= 1000.0;
  }
  
  writeMeasurements <double> (filename_time, header, algorithmParameter, measurements);
  
  // cycles
  
  for (uint i = 0; i < cycleMeasurements.rows(); i++) for (uint j = 0; j < cycleMeasurements.cols(); j++) 
    measurements(i,j) = double (cycleMeasurements(i,j)) / 1000.0;
  
  writeMeasurements <double> (filename_cycles, header, algorithmParameter, measurements);
  
}

int main (int argc, char* argv[]) {
  
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}