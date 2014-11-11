#ifndef METER_H
#define METER_H

#include <functional>

template <class T>
class Meter {
  std::function <T (void)> _f;
  
  T _start, _end; 
  
public:
  // constructor
  Meter (std::function <RetType (void)> f);
  
  // start measurement
  void start ();
  // stop measurement
  void stop ();
  // gives the elapsed measurement
  T peak ();
  // resets the Meter
  void reset ();

}

#endif