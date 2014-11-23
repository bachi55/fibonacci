#ifndef MYTYPES_H
#define MYTYPES_H

#include <chrono>

typedef std::chrono::system_clock::time_point			timePoint ;
typedef std::chrono::microseconds 				microseconds;
typedef std::chrono::nanoseconds 				nanoseconds;
typedef std::chrono::duration <long, std::ratio<1,1000000000>> 	timeDuration;


#endif