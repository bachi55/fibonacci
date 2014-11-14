#include "meter.h" 

template <class Measure, class Unit>
Meter <Measure, Unit>:: Meter (std::function <Measure (void)> f) 
  : _f (f)
  , _start (Measure ())
  , _end (Measure ()) {}
  
template <class Measure, class Unit>
void Meter <Measure, Unit>:: start () {
  _start = _f();
}

template <class Measure, class Unit>
void Meter <Measure, Unit>:: stop () {
  _end = _f();
}

template <class Measure, class Unit>
Unit Meter <Measure, Unit>:: peak () {
  return _end - _start;
}

template <class Measure, class Unit>
void Meter <Measure, Unit>:: reset () {
  _start = Measure ();
  _end = Measure ();
}