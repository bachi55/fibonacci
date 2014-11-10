#include "matrix.h"

template <class T>
Matrix <T> ::Matrix ()
  : Matrix (0, 0) {}
  
template <class T>
Matrix <T> ::Matrix (uint nrow, uint ncol) 
  : _nrow (nrow)
  , _ncol (ncol)
  , _data (std::vector<T>()) 
  , _init (false) {}

template <class T>
Matrix <T> ::Matrix (uint nrow, uint ncol, std::vector<T>&& data) 
  : _nrow (nrow)
  , _ncol (ncol)
  , _data (data) {
    
  if ((_nrow * _ncol) != data.size())
    throw std::runtime_error ("Error: matrix construction failed, nrow * ncol should be equal data.size");
    
  _init = true;
  
}

template <class T>
Matrix <T> ::Matrix (uint nrow, uint ncol, const std::vector<T>& data) 
  : Matrix (nrow, ncol, data) {}

template <class T>
void Matrix <T> ::printMatrix () {
  
  std::printf ("Sorry! There is no \'printMatrix\' implementation for type T right now.\n");
  
}

template <class T>
T& Matrix <T> ::operator() (const uint row, const uint col) {
  
  if ((row > (_nrow - 1)) || (col > (_ncol - 1)))
    throw std::runtime_error ("Error: index out of bounce.");
  
  return _data[row * _ncol + col];
  
}

template <class T>
const T & Matrix <T> ::operator() (const uint row, const uint col) const {
  
  if ((row > (_nrow - 1)) || (col > (_ncol - 1)))
    throw std::runtime_error ("Error: index out of bounce.");
  
  return _data[row * _ncol + col];
  
}


template <class T>
Matrix <T> Matrix <T> ::operator* (const Matrix <T> & rhs) {
  
  if ((*this)._ncol != rhs._nrow)
     throw std::runtime_error ("Error: matrix dimension does not fit.");
  
  Matrix <T> res ((*this)._nrow, rhs._ncol, std::vector <T> ((*this)._nrow * rhs._ncol, 0));
  
  for (uint i = 0; i < (*this)._nrow; i++) 
    for (uint j = 0; j < rhs._ncol; j++)
      for (uint k = 0; k < rhs._nrow; k++) 
	res (i, j) += (*this) (i, k) * rhs (k, j);
      
  return res;
  
}

// Specializing a member function template need to be done in an .cpp file, since otherwise the
// template would need be anymore a template.
template <>
void Matrix <ulong> ::printMatrix ();