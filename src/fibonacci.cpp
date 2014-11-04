#include "fibonacci.h"

#include <algorithm>
#include <cstdio>
#include <stdexcept>
#include <vector>

#ifdef UNITTEST
  #include "fibonacci_unittest.h"
#endif

int main (int argc, char* argv[]) {
  
#ifdef UNITTEST
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#endif
  
  return 0;

}

/// Implementation; see header-file for description
///
/// TODO: Check for overflow.
ulong getnFibonacciNumber (uint n) {

  if (n < 2) return n; 
  
  return getnFibonacciNumber (n - 1) + getnFibonacciNumber (n - 2);
  
}

/// Implementation; see header-file for description
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

/// Implementation; see header-file for description
///
/// TODO: implement without 'res'
ulong getnFibonacciNumber3 (uint n) {

  if (n < 2) return n;
  
  ulong res = 1, s1 = 0, s2 = 1;
  
  for (uint i = 2; i < (n + 1); i++) {
    
    res = s1 + s2;
    s1 = s2;
    s2 = res;
    
    if (res < s2) throw std::overflow_error ("An overflow occured");
    
  }
  
  return res;
}