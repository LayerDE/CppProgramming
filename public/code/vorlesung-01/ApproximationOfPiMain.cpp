// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdio.h>
#include <math.h>
#include "./ApproximationOfPi.cpp"

// Program that computes the approximation of Pi using the circle method.
int main(int argc, char** argv) {
  int n = 10000;
  int count = approximatePiUsingCircleMethod(n);
  int numGridPoints = (2 * n + 1) * (2 * n + 1);
  printf("\n");
  printf("Dimensions of the grid     : [-%d, +%d] x [-%d, +%d]\n", n, n, n, n);
  printf("Number of grid points      : %d\n", numGridPoints);
  printf("Number of points in circle : %d\n", count);
  printf("\n");
  printf("Approximation of Pi        : %1.10f\n", 4.0 * count / numGridPoints);
  printf("Internal value of Pi       : %1.10f\n", M_PI);
  printf("\n");
}
