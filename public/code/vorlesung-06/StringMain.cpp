// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdlib.h>
#include <stdio.h>
#include "./String.h"

// Doof.
String doof() {
  String r1;
  r1.set("Doof");
  String r2;
  r2.set("Bloed");
  return drand48() < 0.5 ? r1 : r2;
}

// Main function.
int main(int argc, char** argv) {
  String s(doof());  // equivalent to: String s = doof();
  printf("The contents of my string is \"%s\"\n", s._contents);
}
