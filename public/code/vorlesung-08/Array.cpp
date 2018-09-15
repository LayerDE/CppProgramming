// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include "./Array.h"

// ___________________________________________________________________________
template<class T>
Array<T>::Array(T* array, int n) {
  _elements = new T[n];
  for (int i = 0; i < n; i++) { _elements[i] = array[i]; }
  _size = n;
}

// ___________________________________________________________________________
template<class T>
Array<T>::~Array() {
  delete[] _elements;
}

// ___________________________________________________________________________
template<class T>
T Array<T>::get(int i) const {
  return _elements[i];
}

// Explicit instantiation for int and float.
template class Array<int>;
template class Array<float>;

// Special implementation for Array<bool>

// ___________________________________________________________________________
Array<bool>::Array(bool* array, int n) {
  _elements = 0;
  for (int i = 0; i < n; i++) {
    if (array[i] == 1) { _elements |= 1 << i; }
  }
  _size = n;
}

// ___________________________________________________________________________
Array<bool>::~Array() {
}

// ___________________________________________________________________________
bool Array<bool>::get(int i) const {
  return (_elements & (1 << i)) != 0 ? true : false;
}




// OLD NON-TEMPLATED CODE

// ___________________________________________________________________________
ArrayInt::ArrayInt(int* array, int n) {
  _elements = new int[n];
  for (int i = 0; i < n; i++) { _elements[i] = array[i]; }
  _size = n;
}

// ___________________________________________________________________________
ArrayInt::~ArrayInt() {
  delete[] _elements;
}

// ___________________________________________________________________________
int ArrayInt::get(int i) const {
  return _elements[i];
}


// ___________________________________________________________________________
ArrayFloat::ArrayFloat(float* array, int n) {
  _elements = new float[n];
  for (int i = 0; i < n; i++) { _elements[i] = array[i]; }
  _size = n;
}

// ___________________________________________________________________________
ArrayFloat::~ArrayFloat() {
  delete[] _elements;
}

// ___________________________________________________________________________
float ArrayFloat::get(int i) const {
  return _elements[i];
}
