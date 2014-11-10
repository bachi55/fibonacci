#include "fibonacci-algorithms.h"

// Implementation; see header-file for description
//
// TODO: Check for overflow.
ulong getnFibonacciNumber (uint n) {
  if (n < 2) return n; 
  
  return getnFibonacciNumber (n - 1) + getnFibonacciNumber (n - 2);
}

// Implementation; see header-file for description
ulong getnFibonacciNumber2 (uint n) {
  if (n < 2) return n;
  
  std::vector <ulong> res (n + 1);
  res[0] = 0; res[1] = 1;
  
  for (uint i = 2; i < res.size(); i++) {
    res[i] = res[i - 1] + res[i - 2];
    
    if (res[i] < res[i - 1]) throw std::overflow_error ("An overflow occured");
  }
  
  return res[res.size() - 1];
}

// Implementation; see header-file for description
ulong getnFibonacciNumber3 (uint n) {
  if (n < 2) return n;
  
  ulong s1 = 0, s2 = 1;
  
  for (uint i = 2; i < (n + 1); i++) {
    s2 = s1 + s2;
    s1 = s2 - s1;
    
    if (s2 < s1) throw std::overflow_error ("An overflow occured");
  }
  
  return s2;
}

// Implementation; see header-file for description
ulong getnFibonacciNumber4 (uint n) {
  if (n < 2) return n;
  
  Matrix <ulong> v (2, 1, {0, 1});
  Matrix <ulong> m (2, 2, {0, 1, 1, 1}); 
  
  Matrix <ulong> res = exponentiationBySquaring (m, n) * v;
  
  return res (0, 0);
}

//Implementation; see header-file for description
Matrix <ulong> exponentiationBySquaring (Matrix <ulong> x, uint n) {
  if (n == 0) 		return (Matrix <ulong> (1, 1, {1}));
  if (n == 1) 		return (x);
  if (n % 2 == 0) 	return (exponentiationBySquaring (x * x, n / 2));
  else 			return (x * exponentiationBySquaring (x * x, (n - 1) / 2));
}

// Implementation; see header-file for description
ulong getnFibonacciNumber5 (uint n) {
  if (n < 2) return n;
  
  return std::floor (1.0 / std::sqrt (5) * exponentiationBySquaring (((1.0 + std::sqrt (5)) / 2.0), n) + 1.0 / 2.0);
}

double exponentiationBySquaring (double x, uint n) {
  if (n == 0) 		return (1.0);
  if (n == 1) 		return (x);
  if (n % 2 == 0) 	return (exponentiationBySquaring (x * x, n / 2));
  else 			return (x * exponentiationBySquaring (x * x, (n - 1) / 2));
}

// Implementation; see header-file for description
// TODO: Is there really something happaning while compile time?
constexpr ulong getnFibonacciNumber6 (uint n) {
  
  return n >= 2 ? getnFibonacciNumber3 (n) : n;
  
}

// TODO: fixed size if LUT (94 elements) because of overflow
ulong getnFibonacciNumberLUT (uint n) {
  
  std::vector <ulong> fib_values (94);
  for (std::vector <ulong>::iterator it = fib_values.begin (); it != fib_values.end(); ++it) {
    std::printf ("%lu\n", it - fib_values.begin());
    (*it) = getnFibonacciNumber6 (it - fib_values.begin());
  }
  return fib_values[n];
  
}


