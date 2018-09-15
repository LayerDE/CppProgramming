// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>.

#ifndef ARRAY_H_
#define ARRAY_H_

#include <gtest/gtest.h>

// A simple array that knows its size. Element type: arbitrary T.
template<class T>
class Array {
 public:
  // Create from given C-style array.
  Array(T* array, int n);

  // Destructor.
  ~Array();

  // Get the element with index i.
  T get(int i) const;

 private:
  // The elements of the array.
  T* _elements;

  // The number of elements.
  int _size;

  FRIEND_TEST(ArrayTest, Array);
};

// A special and more efficient implementation for the type bool. For
// simplicity, just implement an array which can hold at most 8 bits.
template<>
class Array<bool> {
 public:
  // Create from given C-style array.
  Array(bool* array, int n);

  // Destructor.
  ~Array();

  // Get the element with index i.
  bool get(int i) const;

 private:
  // The elements of the array, stored in a single byte.
  unsigned char _elements;

  // The number of elements.
  int _size;

  FRIEND_TEST(ArrayTest, Array);
};



// OLD NON-TEMPLATED CODE

// A simple array that knows its size. Element type: int.
class ArrayInt {
 public:
  // Create from given C-style array.
  ArrayInt(int* array, int n);

  // Destructor.
  ~ArrayInt();

  // Get the element with index i.
  int get(int i) const;

 private:
  // The elements of the array.
  int* _elements;

  // The number of elements.
  int _size;

  FRIEND_TEST(ArrayTest, ArrayInt);
};


// A simple array that knows its size. Element type: float.
class ArrayFloat {
 public:
  // Create from given C-style array.
  ArrayFloat(float* array, int n);

  // Destructor.
  ~ArrayFloat();

  // Get the element with index i.
  float get(int i) const;

 private:
  // The elements of the array.
  float* _elements;

  // The number of elements.
  int _size;

  FRIEND_TEST(ArrayTest, ArrayFloat);
};


#endif  // ARRAY_H_
