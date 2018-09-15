// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdio.h>
#include <math.h>
#include <inttypes.h>
#include "./ApproximationEulersNumber.h"

// Program that computes the approximation e using the sum(1/x!) method.
int main(int argc, char** argv) {
  int n = 20;
  printf("\n");
  printf("Approximation of e        : %1.10f\n", approximateEulersNumber(n));
  printf("Internal value of e       : %1.10f\n", M_E);
  printf("\n");
}
