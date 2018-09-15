// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <stdio.h>
#include "./Set.h"
#include "./SetCharSize.h"

int main() {
  Set<int> iSet;
  printf("Size of Set<int>   : %ld\n", sizeof(iSet));
  Set<char> cSet;
  printf("Size of Set<char>  : %ld\n", sizeof(cSet));
  SetCharSize csSet;
  printf("Size of SetCharSize: %ld\n", sizeof(csSet));
}
