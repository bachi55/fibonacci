#include "meter.h"

timePoint myClock (void) { 
  return std::chrono::system_clock::now(); 
}

uint theAnswer (void) {
  return 42;
}

ulong myCycles (void) {
#ifdef RDTSCP_SUPPORT
  unsigned int lo, hi;
  __asm__ __volatile__ ("rdtscp" : "=a" (lo), "=d" (hi));
  return ((ulong)hi << 32) | lo;
#else
  throw std::logic_error ("Error: No cycle measure implementation for your CPU\n\tRight now \'rdtscp\'-Support is needed.");
  return -1;
#endif
}