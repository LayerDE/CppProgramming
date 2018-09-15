// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef SETCHARSIZE_H_
#define SETCHARSIZE_H_

#include <stdint.h>
#include <gtest/gtest.h>

class SetCharSize {
 public:
  // Insert char into set.
  void insert(char item);

  // Remove char from set.
  void erase(char item);

  // Check if char is in the set.
  bool lookup(char item) const;

 private:
  // fixed size storage field.
  uint64_t _elements[4] = {0};
};

#endif  // SETCHARSIZE_H_
