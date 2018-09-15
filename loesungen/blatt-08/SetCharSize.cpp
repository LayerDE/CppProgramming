// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <stdio.h>
#include "./SetCharSize.h"

// _____________________________________________________________________________
void SetCharSize::insert(char item) {
  uint index = static_cast<unsigned char>(item) / 64;
  uint subindex = static_cast<unsigned char>(item) % 64;
  _elements[index] |= (uint64_t(1) << subindex);
}

// _____________________________________________________________________________
void SetCharSize::erase(char item) {
  uint index = static_cast<unsigned char>(item) / 64;
  uint subindex = static_cast<unsigned char>(item) % 64;
  _elements[index] &= ~(uint64_t(1) << subindex);
}

// _____________________________________________________________________________
bool SetCharSize::lookup(char item) const {
  uint index = static_cast<unsigned char>(item) / 64;
  uint subindex = static_cast<unsigned char>(item) % 64;
  return _elements[index] & (uint64_t(1) << subindex);
}
