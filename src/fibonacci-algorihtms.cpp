#include "fibonacci-algorithms.h"

FibonacciLUT:: FibonacciLUT (uint nMax) 
  : _nMax (nMax)
{
  _LUT.resize (_nMax);
  
  for (auto it = _LUT.begin(); it != _LUT.end(); ++it) 
    (*it) = getnFibonacciNumber5 (it - _LUT.begin());
}

ulong FibonacciLUT:: lookfor (uint n) const {
  if (n > _nMax) {
    char buffer[128]; 
    std::sprintf (buffer, "Error: No Fibonacci-LUT entry for %i (nMax = %i)\n", n, _nMax);
    
    throw std::invalid_argument (std::string (buffer));
  }
    
  return _LUT[n];
}

// Implementation; see header-file for description
//
// No check for overflow needed. If one would occure, the user would be alread
// quite old.
ulong getnFibonacciNumber (uint n) {
  if (n < 2) return n;
  
  return getnFibonacciNumber (n - 1) + getnFibonacciNumber (n - 2);
}

// Implementation; see header-file for description
ulong getnFibonacciNumber2 (uint n) {
  
  
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

Matrix <ulong> exponentiationBySquaring_iterativ (Matrix <ulong> x, uint n) {
  if (n == 0) 		return (Matrix <ulong> (1, 1, {1}));
  if (n == 1) 		return (x);
  
  Matrix <ulong> orig = createIdentityMatrix <ulong> (x.rows());
  
  while (n > 1) {			// recursive descend
    if (n % 2 == 0) {
      x = x * x;
      n = n / 2;
    } else {
      orig = orig * x;
      x = x * x;
      n = (n - 1) / 2;
    }
  }
  
  return orig * x;
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

ulong getnFibonacciNumber6 (const FibonacciLUT & LUT, uint n) {
  return LUT.lookfor(n);
}

ulong getnFibonacciNumber7 (uint n) {
  if (n < 2) return n;
  
  Matrix <ulong> v (2, 1, {0, 1});
  Matrix <ulong> m (2, 2, {0, 1, 1, 1}); 
  
  Matrix <ulong> res = exponentiationBySquaring_iterativ (m, n) * v;
  
  return res (0, 0);
}