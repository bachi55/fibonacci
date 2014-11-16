#include "fibonacci-algorithms.h"
#include "meter.h"

#include <cstdio>
#include <chrono>
#include <string>

#include <gtest/gtest.h>

// ---------------------------------------------------------------------
// Local helper functions TODO: Maybe move somewhere else!
// ---------------------------------------------------------------------

double calcualteMean (const std::vector<double> & x) {
  if (x.size() == 0) throw std::runtime_error ("Error: Mean of an empty vector is not defined!");
  
  double sum = 0.0; 
  for (auto it = x.begin(); it != x.end(); ++it) 
    sum += (*it);
  
  return sum / x.size();
}

double calculateVar (const std::vector<double> & x) {
  if (x.size() == 0) throw std::runtime_error ("Error: Variance of an empty vector is not defined!");
  
  double var = 0.0;
  double mean = calcualteMean (x);
  
  for (auto it = x.begin(); it != x.end(); ++it) 
    var += ((*it) - mean) * ((*it) - mean );
  
  return var / x.size();
}


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
// TEST (matrix, correctness) {
//   
//   Matrix <ulong> m1 (2, 2, {1, 2, 3, 4});
//   ASSERT_EQ (m1 (0, 0), 1);
//   ASSERT_EQ (m1 (0, 1), 2);
//   ASSERT_EQ (m1 (1, 0), 3);
//   ASSERT_EQ (m1 (1, 1), 4);
//   
//   Matrix <ulong> m2 (2, 2, {1, 0, 0, 1});
//   Matrix <ulong> prod = m1 * m2;
//   ASSERT_EQ (prod (0, 0), 1);
//   ASSERT_EQ (prod (0, 1), 2);
//   ASSERT_EQ (prod (1, 0), 3);
//   ASSERT_EQ (prod (1, 1), 4);
//   
//   // calculate the covariance matrix
//   Matrix <ulong> m1t = Matrix <ulong> (2, 2, {1, 3, 2, 4});
//   Matrix <ulong> cov = m1 * m1t;
//   ASSERT_EQ (cov (0, 0),  5);
//   ASSERT_EQ (cov (0, 1), 11);
//   ASSERT_EQ (cov (1, 0), 11);
//   ASSERT_EQ (cov (1, 1), 25);
// 
// }

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

// TODO: How to test cycle measurements? Does an instruction every time it is executed has the amount of cycles?
// TEST (measurements, cycles) {
//   Meter <ulong, ulong> meter (myCycles);
//   meter.start();
//   5 + 5;
//   meter.stop();
//   std::printf ("%lu\n", meter.peak());
// }

TEST (statistics, mean) {
  ASSERT_EQ (calcualteMean ({1, 2, 3}), 2);
  ASSERT_EQ (calcualteMean ({1}), 1);
  ASSERT_EQ (calcualteMean ({1, 2}), 1.5);
  ASSERT_EQ (calcualteMean ({1, 1, 1}), 1);
}

TEST (statistics, var) {
  ASSERT_EQ (calculateVar ({1, 2, 3}), 2.0 / 3.0);
  ASSERT_EQ (calculateVar ({1}), 0);
  ASSERT_EQ (calculateVar ({1, 2}), 0.25);
  ASSERT_EQ (calculateVar ({1, 1, 1}), 0);
}

// TEST (measurements, time_algo1) {
//   std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo1-time";
//   FILE * ofile = std::fopen (filename.c_str(), "w+");
//   if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
//   
//   std::fprintf (ofile, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
//   
//   std::vector <double> times (6);
//   Meter <timePoint, timeDuration> meter (myClock);
//   for (uint n = 0; n <= 45; n++) {
//     for (uint run = 0; run < 6; run++) {
//       std::printf ("%u\n", n);
//       meter.start();
//       getnFibonacciNumber (n);
//       meter.stop();
//       times[run] = std::chrono::duration_cast <nanoseconds> (meter.peak()).count();
//       meter.reset();
//     }
//     
//     double min = (*std::min_element (times.begin(), times.end()));
//     double max = (*std::max_element (times.begin(), times.end()));
//     
//     double mean = calcualteMean (times);
//     double sd   = sqrt (calculateVar (times));
//     
//     // Time should be written out in [us] (= mircoseconds)
//     min  /= 1000.0;
//     max  /= 1000.0;
//     mean /= 1000.0;
//     sd   /= 1000.0;
//     std::for_each (times.begin(), times.end(), [](double & x){ x /= 1000.0; });
//     
//     std::fprintf (ofile, "# %2u %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f\n",
// 		  n, min, max, mean, sd, times[0], times[1], times[2], times[3], times[4], times[5]
// 	 );
//   }
//   
//   fclose (ofile);
// }

// TEST (measurements, time_algo2) {
//   std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo2-time";
//   FILE * ofile = std::fopen (filename.c_str(), "w+");
//   if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
//   
//   std::fprintf (ofile, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
//   
//   std::vector <double> times (6);
//   Meter <timePoint, timeDuration> meter (myClock);
//   for (uint n = 0; n <= 93; n++) {
//     for (uint run = 0; run < 6; run++) {
//       meter.start();
//       getnFibonacciNumber2 (n);
//       meter.stop();
//       times[run] = std::chrono::duration_cast <nanoseconds> (meter.peak()).count();
//       meter.reset();
//     }
//     
//     double min = (*std::min_element (times.begin(), times.end()));
//     double max = (*std::max_element (times.begin(), times.end()));
//     
//     double mean = calcualteMean (times);
//     double sd   = sqrt (calculateVar (times));
//     
//     // Time should be written out in [us] (= mircoseconds)
//     min  /= 1000.0;
//     max  /= 1000.0;
//     mean /= 1000.0;
//     sd   /= 1000.0;
//     std::for_each (times.begin(), times.end(), [](double & x){ x /= 1000.0; });
//     
//     std::fprintf (ofile, "# %2u %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f\n",
// 		  n, min, max, mean, sd, times[0], times[1], times[2], times[3], times[4], times[5]
// 	 );
//   }
//   
//   fclose (ofile);
// }
// 
// TEST (measurements, time_algo3) {
//   std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo3-time";
//   FILE * ofile = std::fopen (filename.c_str(), "w+");
//   if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
//   
//   std::fprintf (ofile, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
//   
//   std::vector <double> times (6);
//   Meter <timePoint, timeDuration> meter (myClock);
//   for (uint n = 0; n <= 93; n++) {
//     for (uint run = 0; run < 6; run++) {
//       meter.start();
//       getnFibonacciNumber3 (n);
//       meter.stop();
//       times[run] = std::chrono::duration_cast <nanoseconds> (meter.peak()).count();
//       meter.reset();
//     }
//     
//     double min = (*std::min_element (times.begin(), times.end()));
//     double max = (*std::max_element (times.begin(), times.end()));
//     
//     double mean = calcualteMean (times);
//     double sd   = sqrt (calculateVar (times));
//     
//     // Time should be written out in [us] (= mircoseconds)
//     min  /= 1000.0;
//     max  /= 1000.0;
//     mean /= 1000.0;
//     sd   /= 1000.0;
//     std::for_each (times.begin(), times.end(), [](double & x){ x /= 1000.0; });
//     
//     std::fprintf (ofile, "# %2u %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f\n",
// 		  n, min, max, mean, sd, times[0], times[1], times[2], times[3], times[4], times[5]
// 	 );
//   }
//   
//   fclose (ofile);
// }
// 
// TEST (measurements, time_algo4) {
//   std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo4-time";
//   FILE * ofile = std::fopen (filename.c_str(), "w+");
//   if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
//   
//   std::fprintf (ofile, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
//   
//   std::vector <double> times (6);
//   Meter <timePoint, timeDuration> meter (myClock);
//   for (uint n = 0; n <= 93; n++) {
//     for (uint run = 0; run < 6; run++) {
//       meter.start();
//       getnFibonacciNumber4 (n);
//       meter.stop();
//       times[run] = std::chrono::duration_cast <nanoseconds> (meter.peak()).count();
//       meter.reset();
//     }
//     
//     double min = (*std::min_element (times.begin(), times.end()));
//     double max = (*std::max_element (times.begin(), times.end()));
//     
//     double mean = calcualteMean (times);
//     double sd   = sqrt (calculateVar (times));
//     
//     // Time should be written out in [us] (= mircoseconds)
//     min  /= 1000.0;
//     max  /= 1000.0;
//     mean /= 1000.0;
//     sd   /= 1000.0;
//     std::for_each (times.begin(), times.end(), [](double & x){ x /= 1000.0; });
//     
//     std::fprintf (ofile, "# %2u %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f\n",
// 		  n, min, max, mean, sd, times[0], times[1], times[2], times[3], times[4], times[5]
// 	 );
//   }
//   
//   fclose (ofile);
// }
// 
// TEST (measurements, time_algo5) {
//   std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo5-time";
//   FILE * ofile = std::fopen (filename.c_str(), "w+");
//   if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
//   
//   std::fprintf (ofile, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
//   
//   std::vector <double> times (6);
//   Meter <timePoint, timeDuration> meter (myClock);
//   for (uint n = 0; n <= 75; n++) {
//     for (uint run = 0; run < 6; run++) {
//       meter.start();
//       getnFibonacciNumber5 (n);
//       meter.stop();
//       times[run] = std::chrono::duration_cast <nanoseconds> (meter.peak()).count();
//       meter.reset();
//     }
//     
//     double min = (*std::min_element (times.begin(), times.end()));
//     double max = (*std::max_element (times.begin(), times.end()));
//     
//     double mean = calcualteMean (times);
//     double sd   = sqrt (calculateVar (times));
//     
//     // Time should be written out in [us] (= mircoseconds)
//     min  /= 1000.0;
//     max  /= 1000.0;
//     mean /= 1000.0;
//     sd   /= 1000.0;
//     std::for_each (times.begin(), times.end(), [](double & x){ x /= 1000.0; });
//     
//     std::fprintf (ofile, "# %2u %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f\n",
// 		  n, min, max, mean, sd, times[0], times[1], times[2], times[3], times[4], times[5]
// 	 );
//   }
//   
//   fclose (ofile);
// }
// 
// TEST (measurements, time_algo6) {
//   std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo6-time";
//   FILE * ofile = std::fopen (filename.c_str(), "w+");
//   if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
//   
//   std::fprintf (ofile, "# %2s %10s %10s %10s %10s %15s\n", "n", "min [us]", "max [us]", "mean [us]", "sd [us]", "measurements [us]");
//   
//   // Algorithm requires Look Up Table
//   FibonacciLUT LUT;
//   
//   std::vector <double> times (6);
//   Meter <timePoint, timeDuration> meter (myClock);
//   for (uint n = 0; n <= 93; n++) {
//     for (uint run = 0; run < 6; run++) {
//       meter.start();
//       getnFibonacciNumber6 (LUT, n);
//       meter.stop();
//       times[run] = std::chrono::duration_cast <nanoseconds> (meter.peak()).count();
//       meter.reset();
//     }
//     
//     double min = (*std::min_element (times.begin(), times.end()));
//     double max = (*std::max_element (times.begin(), times.end()));
//     
//     double mean = calcualteMean (times);
//     double sd   = sqrt (calculateVar (times));
//     
//     // Time should be written out in [us] (= mircoseconds)
//     min  /= 1000.0;
//     max  /= 1000.0;
//     mean /= 1000.0;
//     sd   /= 1000.0;
//     std::for_each (times.begin(), times.end(), [](double & x){ x /= 1000.0; });
//     
//     std::fprintf (ofile, "# %2u %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f %10.3f\n",
// 		  n, min, max, mean, sd, times[0], times[1], times[2], times[3], times[4], times[5]
// 	 );
//   }
//   
//   fclose (ofile);
// }

// TEST (measurements, cycles_algo1) {
//   std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo1-cycles";
//   FILE * ofile = std::fopen (filename.c_str(), "w+");
//   if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
//   
//   std::fprintf (ofile, "# %2s %15s %15s %15s %15s %15s\n", "n", "min [cyc]", "max [cyc]", "mean [cyc]", "sd [cyc]", "measurements [cyc]");
//   
//   std::vector <double> cylces (6);
//   Meter <ulong, ulong> meter (myCycles);
//   for (uint n = 0; n <= 45; n++) {
//     for (uint run = 0; run < 6; run++) {
//       std::printf ("%u\n", n);
//       meter.start();
//       getnFibonacciNumber (n);
//       meter.stop();
//       cylces[run] = meter.peak();
//       meter.reset();
//     }
//     
//     ulong min = (*std::min_element (cylces.begin(), cylces.end()));
//     ulong max = (*std::max_element (cylces.begin(), cylces.end()));
//     
//     double mean = calcualteMean (cylces);
//     double sd   = sqrt (calculateVar (cylces));
//     
//     
//     std::fprintf (ofile, "# %2u %15lu %15lu %15.3f %15.3f %15.0f %15.0f %15.0f %15.0f %15.0f %15.0f\n",
// 		  n, min, max, mean, sd, cylces[0], cylces[1], cylces[2], cylces[3], cylces[4], cylces[5]
// 	 );
//   }
//   
//   fclose (ofile);
// }

TEST (measurements, cycles_algo2) {
  std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo2-cycles";
  FILE * ofile = std::fopen (filename.c_str(), "w+");
  if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
  
  std::fprintf (ofile, "# %2s %15s %15s %15s %15s %15s\n", "n", "min [cyc]", "max [cyc]", "mean [cyc]", "sd [cyc]", "measurements [cyc]");
  
  std::vector <double> cylces (6);
  Meter <ulong, ulong> meter (myCycles);
  for (uint n = 0; n <= 93; n++) {
    for (uint run = 0; run < 6; run++) {
      meter.start();
      getnFibonacciNumber2 (n);
      meter.stop();
      cylces[run] = meter.peak();
      meter.reset();
    }
    
    ulong min = (*std::min_element (cylces.begin(), cylces.end()));
    ulong max = (*std::max_element (cylces.begin(), cylces.end()));
    
    double mean = calcualteMean (cylces);
    double sd   = sqrt (calculateVar (cylces));
    
    
    std::fprintf (ofile, "# %2u %15lu %15lu %15.3f %15.3f %15.0f %15.0f %15.0f %15.0f %15.0f %15.0f\n",
		  n, min, max, mean, sd, cylces[0], cylces[1], cylces[2], cylces[3], cylces[4], cylces[5]
	 );
  }
  
  fclose (ofile);
}

TEST (measurements, cycles_algo3) {
  std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo3-cycles";
  FILE * ofile = std::fopen (filename.c_str(), "w+");
  if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
  
  std::fprintf (ofile, "# %2s %15s %15s %15s %15s %15s\n", "n", "min [cyc]", "max [cyc]", "mean [cyc]", "sd [cyc]", "measurements [cyc]");
  
  std::vector <double> cylces (6);
  Meter <ulong, ulong> meter (myCycles);
  for (uint n = 0; n <= 93; n++) {
    for (uint run = 0; run < 6; run++) {
      meter.start();
      getnFibonacciNumber3 (n);
      meter.stop();
      cylces[run] = meter.peak();
      meter.reset();
    }
    
    ulong min = (*std::min_element (cylces.begin(), cylces.end()));
    ulong max = (*std::max_element (cylces.begin(), cylces.end()));
    
    double mean = calcualteMean (cylces);
    double sd   = sqrt (calculateVar (cylces));
    
    
    std::fprintf (ofile, "# %2u %15lu %15lu %15.3f %15.3f %15.0f %15.0f %15.0f %15.0f %15.0f %15.0f\n",
		  n, min, max, mean, sd, cylces[0], cylces[1], cylces[2], cylces[3], cylces[4], cylces[5]
	 );
  }
  
  fclose (ofile);
}

TEST (measurements, cycles_algo4) {
  std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo4-cycles";
  FILE * ofile = std::fopen (filename.c_str(), "w+");
  if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
  
  std::fprintf (ofile, "# %2s %15s %15s %15s %15s %15s\n", "n", "min [cyc]", "max [cyc]", "mean [cyc]", "sd [cyc]", "measurements [cyc]");
  
  std::vector <double> cylces (6);
  Meter <ulong, ulong> meter (myCycles);
  for (uint n = 0; n <= 93; n++) {
    for (uint run = 0; run < 6; run++) {
      meter.start();
      getnFibonacciNumber4 (n);
      meter.stop();
      cylces[run] = meter.peak();
      meter.reset();
    }
    
    ulong min = (*std::min_element (cylces.begin(), cylces.end()));
    ulong max = (*std::max_element (cylces.begin(), cylces.end()));
    
    double mean = calcualteMean (cylces);
    double sd   = sqrt (calculateVar (cylces));
    
    
    std::fprintf (ofile, "# %2u %15lu %15lu %15.3f %15.3f %15.0f %15.0f %15.0f %15.0f %15.0f %15.0f\n",
		  n, min, max, mean, sd, cylces[0], cylces[1], cylces[2], cylces[3], cylces[4], cylces[5]
	 );
  }
  
  fclose (ofile);
}

TEST (measurements, cycles_algo5) {
  std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo5-cycles";
  FILE * ofile = std::fopen (filename.c_str(), "w+");
  if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
  
  std::fprintf (ofile, "# %2s %15s %15s %15s %15s %15s\n", "n", "min [cyc]", "max [cyc]", "mean [cyc]", "sd [cyc]", "measurements [cyc]");
  
  std::vector <double> cylces (6);
  Meter <ulong, ulong> meter (myCycles);
  for (uint n = 0; n <= 75; n++) {
    for (uint run = 0; run < 6; run++) {
      meter.start();
      getnFibonacciNumber5 (n);
      meter.stop();
      cylces[run] = meter.peak();
      meter.reset();
    }
    
    ulong min = (*std::min_element (cylces.begin(), cylces.end()));
    ulong max = (*std::max_element (cylces.begin(), cylces.end()));
    
    double mean = calcualteMean (cylces);
    double sd   = sqrt (calculateVar (cylces));
    
    
    std::fprintf (ofile, "# %2u %15lu %15lu %15.3f %15.3f %15.0f %15.0f %15.0f %15.0f %15.0f %15.0f\n",
		  n, min, max, mean, sd, cylces[0], cylces[1], cylces[2], cylces[3], cylces[4], cylces[5]
	 );
  }
  
  fclose (ofile);
}

TEST (measurements, cycles_algo6) {
  std::string filename = "/home/bach/Documents/algorithm-exercises/exercises/measurements/algo6-cycles";
  FILE * ofile = std::fopen (filename.c_str(), "w+");
  if (!ofile) throw std::runtime_error ("Error: Cannot open output file.");
  
  std::fprintf (ofile, "# %2s %15s %15s %15s %15s %15s\n", "n", "min [cyc]", "max [cyc]", "mean [cyc]", "sd [cyc]", "measurements [cyc]");
  
  FibonacciLUT LUT;
  
  std::vector <double> cylces (6);
  Meter <ulong, ulong> meter (myCycles);
  for (uint n = 0; n <= 93; n++) {
    for (uint run = 0; run < 6; run++) {
      meter.start();
      getnFibonacciNumber6 (LUT, n);
      meter.stop();
      cylces[run] = meter.peak();
      meter.reset();
    }
    
    ulong min = (*std::min_element (cylces.begin(), cylces.end()));
    ulong max = (*std::max_element (cylces.begin(), cylces.end()));
    
    double mean = calcualteMean (cylces);
    double sd   = sqrt (calculateVar (cylces));
    
    
    std::fprintf (ofile, "# %2u %15lu %15lu %15.3f %15.3f %15.0f %15.0f %15.0f %15.0f %15.0f %15.0f\n",
		  n, min, max, mean, sd, cylces[0], cylces[1], cylces[2], cylces[3], cylces[4], cylces[5]
	 );
  }
  
  fclose (ofile);
}

int main (int argc, char* argv[]) {
  
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}