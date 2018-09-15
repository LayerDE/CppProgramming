// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdio.h>
#include <stdlib.h>
#include "./InputOutput.h"

// Main function.
int main(int argc, char** argv) {
  InputOutput io;
  io.parseCommandLineArguments(argc, argv);
  io.process();
}
