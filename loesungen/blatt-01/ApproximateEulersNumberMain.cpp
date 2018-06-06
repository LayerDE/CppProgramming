// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <stdio.h>
#include <math.h>
#include "./ApproximateEulersNumber.cpp"

int main(int argc, char** argv) {
  // Store n for both algorithms.
  int a1 = 15;
  int a2 = 100000000;
  // Print results for bot algorithms and the internal value.
  printf("Eulers number after %2d iterations (using method 1): %1.10f\n",
      a1, approximateEulersNumber(a1));
  printf("Eulers with step width 1/%d (method 2)     : %1.10f\n",
      a2, approximateEulersNumberAlternative(a2));
  printf("Internal value of E                               : %1.10f\n", M_E);
}
