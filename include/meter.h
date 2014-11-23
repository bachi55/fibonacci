#ifndef METER_H
#define METER_H

#include "matrix.h"
#include "mytypes.h"

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <functional>
#include <type_traits>
#include <vector>

// TODO: How to pass arguments to _f, which could be void, without pulting the interface?
template <class Measure, class Unit>
class Meter {
  std::function <Measure (void)> _f;
  
  Measure _start, _end; 
  
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



// ---------------------------------------------------------------------
// TIME
// ---------------------------------------------------------------------

// Types and function for measurements time
// typedef std::chrono::system_clock::time_point			timePoint ;
// typedef std::chrono::microseconds 				microseconds;
// typedef std::chrono::nanoseconds 				nanoseconds;
// typedef std::chrono::duration <long, std::ratio<1,1000000000>> 	timeDuration;

// Function to return the current time of the system_clock in microseconds.
timePoint myClock (void);

// ---------------------------------------------------------------------
// CYCLES
// --------------------------------------------------------------------- 

// We need a type to store the return values of 'cpuid'
struct Register {
  Register (uint eax, uint ebx, uint ecx, uint edx) 
    : _eax (eax)
    , _ebx (ebx)
    , _ecx (ecx)
    , _edx (edx) {};
    
  uint _eax;
  uint _ebx;
  uint _ecx;
  uint _edx;
}; 
  
// This function calls the 'cpuid' instructions (in assembler) and returns the result.
// 
// A side effect of the 'cpuid' instruction is the serialization of the cpu.
Register cpuid (uint eax);

// This function checks, whether the current CPU supports the 'cpuid' instruction
//
// TODO: implement this function
inline bool hasCPUID (void) { return true; };

// This functions reads the cpu instruction time stamp and serializes the cpu 
//
// NOTE: only instructions before are prevent to move behind 'rdtscp'
uint64_t rdtscp (void);

// This function checks, whether the current CPU supports the 'rdtscp' instruction
// 
// TODO: implement this function
inline bool hasRDTSCP (void) { return true; };

// This functions reads the cpu instruction time stamp
uint64_t rdtsc (void);

// This function checks, whether the current CPU supports the 'rdtsc' instruction
// 
// TODO: implement this function
inline bool hasRDTSC (void) { return true; };


// This function return the cpu instruction time stamp.
//
// Before the time stamp is read, the cpu will be serialized using the 'cpuid' command.
uint64_t myCycles (void);

// This function can write out measurements
//
// NOTE: parameterIdentifier identifies a certain set of parameters
//
// It can be used in the follwing way: 
// 1) run your algorithm each parameter set (lets say of size N) M-times
// 2) store your measurements into a matrix (N times M)
// 3) call this function with an appropriate name
// TODO: How to handly a given format string? 
// TODO: Realize with string streams!
template <typename T>
void writeMeasurements (const std::string & oFilename
		      , const std::string & header
// 		      , const std::string & format
		      , const std::vector <uint> & parameterIdentifier 
		      , const Matrix <T> measurements);

// This function can benchmark a given algorithm using a given measure
template <typename Unit, typename Measure, typename T, typename... Args>
std::vector <Unit> benchmark (std::function <Measure (void)> measuringFunction
			    , uint nRuns
			    , std::function <T (Args...)> algorithm
			    , Args... algorithmParameter);

// This function is dummy function to test the variadic templates
template <typename T, typename... Args>
T execute (const std::function  <T (Args...)> f, Args... parameter) {
  
  return f (parameter...);
}

// NOTE: Never, Never, Never ... forget this again!!!!!
#include "meter.tpp"

#endif