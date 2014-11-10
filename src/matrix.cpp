#include "matrix.h"

//TODO: Try to use type_traits (header) : is_arithmetic (function) to print out.
template <>
void Matrix <ulong> ::printMatrix ()
{
  
  for (std::vector<ulong>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
    // print newline after a row has been printed
    if (((it - _data.begin()) % _ncol == 0) && (it != _data.begin())) 
      std::printf ("\n");
    
    std::printf ("%lu ", (*it));
  }
  
}