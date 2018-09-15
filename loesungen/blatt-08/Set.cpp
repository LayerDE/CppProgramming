// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include "./Set.h"

// _____________________________________________________________________________
template<class T>
Set<T>::Set() {
  _elements = new T[0];
  _size = 0;
}

// _____________________________________________________________________________
template<class T>
Set<T>::~Set() {
  delete[] _elements;
}

// _____________________________________________________________________________
template<class T>
void Set<T>::insert(const T& item) {
  if (lookup(item)) { return; }

  // Increase size, copy all and append the new item.
  T* new_elements = new T[_size + 1];
  for (size_t i = 0; i < _size; i++) { new_elements[i] = _elements[i]; }
  new_elements[_size] = item;
  _size++;
  delete[] _elements;
  _elements = new_elements;
}

// _____________________________________________________________________________
template<class T>
void Set<T>::erase(const T& item) {
  if (!lookup(item)) { return; }

  // Reduce size and copy into the new field...
  T* new_elements = new T[_size - 1];
  size_t j = 0;
  for (size_t i = 0; i < _size; i++) {
    // ... if it's not the element we want to remove.
    if (_elements[i] != item) {
      new_elements[j] = _elements[i];
      j++;
    }
  }
  _size--;
  delete[] _elements;
  _elements = new_elements;
}

// _____________________________________________________________________________
template<class T>
bool Set<T>::lookup(const T& item) const {
  for (size_t i = 0; i < _size; i++) {
    if (_elements[i] == item) {
      return true;
    }
  }
  return false;
}

// _____________________________________________________________________________
template class Set<int>;

// _____________________________________________________________________________
void Set<char>::insert(char item) {
  _elements[static_cast<unsigned char>(item)] = true;
}

// _____________________________________________________________________________
void Set<char>::erase(char item) {
  _elements[static_cast<unsigned char>(item)] = false;
}

// _____________________________________________________________________________
bool Set<char>::lookup(char item) const {
  return _elements[static_cast<unsigned char>(item)];
}
