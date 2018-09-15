// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef SET_H_
#define SET_H_

#include <gtest/gtest.h>

template<class T>
class Set {
 public:
  // Construct a new set instance.
  Set();

  // Destructor.
  ~Set();

  // Insert item of type T into the set.
  void insert(const T& item);

  // Remove item of type T from the set.
  void erase(const T& item);

  // Check if item is in the set.
  bool lookup(const T& item) const;

 private:
  // Field for storing uniqe entries.
  T* _elements;

  // Size of the storage field.
  size_t _size;
};

template<>
class Set<char> {
 public:
  // Insert char into set.
  void insert(char item);

  // Remove char from set.
  void erase(char item);

  // Check if char is in the set.
  bool lookup(char item) const;

 private:
  // fixed size storage field.
  bool _elements[256] = {0};
};

#endif  // SET_H_
