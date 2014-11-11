//TODO: Come clear about the return type of function for complex objects (for ex. like matrices). 
// 	Keywords are: const reference, rvalue moving, const access, copies
//TODO: Come clear about moving-constructor
//	Key questions: Do I need to delete something? When the constructor will be called?

#ifndef MATRIX_H
#define MATRIX_H

#include <cstdio>
#include <stdexcept>
#include <sys/types.h>
#include <vector>

template <class T>
class Matrix {
  uint _nrow, _ncol;
  std::vector <T> _data;
  bool _init; 
  
public: 
  Matrix ();
  // constructs an not initialized matrix
  //
  // The matrix has a give size, but no data. 
  // TODO: write method to fill up the matrix
  Matrix (uint nrow, uint ncol);
  
  // constructor _move_ data from vector: requires c++11 or later
  Matrix (uint nrow, uint ncol, std::vector <T> && data);
  
  // constructor _copy_ data from vector 
  Matrix (uint nrow, uint ncol, const std::vector <T> & data);
  
  // print matrix
  void printMatrix ();
  
  // access operator (e.g. matrix (i,j) = 0 --> lvalue) 
  T & operator() (const uint row, const uint col); 
  
  // access operator (for access from constant objects)
  const T & operator() (const uint row, const uint col) const; 
  
  // matrix multiplication
  Matrix <T> operator* (const Matrix <T> & rhs);
  
};

#include "matrix.tpp"

#endif