#include "meter.h"

timePoint myClock (void) { 
  return std::chrono::system_clock::now(); 
}

unsigned int theAnswer (void) {
  return 42;
}