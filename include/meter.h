#ifndef METER_H
#define METER_H

#include <chrono>
#include <functional>

template <class Measure, class Unit>
class Meter {
  std::function <Measure (void)> _f;
  
  Measure _start, _end; 
  
  bool _is_set_start, _is_set_end;
  
public:
  // constructor
  Meter (std::function <Measure (void)> f);
  
  // start measurement
  void start ();
  // stop measurement
  void stop ();
  // gives the elapsed measurement
  Unit peak ();
  // resets the Meter
  void reset ();

};

// NOTE: Never, Never, Never ... forget this again!!!!!
#include "meter.tpp"

// ---------------------------------------------------------------------
// TIME
// ---------------------------------------------------------------------

// Types and function for measurements time
typedef std::chrono::system_clock::time_point			timePoint ;
typedef std::chrono::microseconds 				microseconds;
typedef std::chrono::duration <long, std::ratio<1,1000000000>> 	timeDuration;

// Function to return the current time of the system_clock in microseconds.
timePoint myClock (void);

unsigned int theAnswer (void);

#endif