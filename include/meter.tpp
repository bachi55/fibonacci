#include "meter.h" 

template <class T>
Meter <T>:: Meter (std::function <T (void)> f) 
  : _f (f)
  , _start (T (0))
  , _end (T (0)) {}
  
template <class T>
void Meter <T>:: start () {
  _start = _f();
}

template <class T>
void Meter <T>:: stop () {
  _end = _f();
}

template <class T>
T Meter <T>:: peak () {
  return _end - _start;
}

template <class T>
void Meter <T>:: reset () {
  _start = T (0);
  _end = T (0);
}