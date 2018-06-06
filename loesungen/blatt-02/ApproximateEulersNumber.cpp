// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include "./ApproximateEulersNumber.h"

// ___________________________________________________________________________
double approximateEulersNumber(int iterations) {
  // Only allow positive iteration number
  if (iterations < 0) {
    return -1.0;
  }
  // 0! = 1 => 1/0! = 1/1! = 1
  double result = 1.0;

  // Compute factorial iterativly on-the-fly.
  double factor = 1.0;
  for (int i = 1; i < iterations; ++i) {
    factor *= i;
    result += 1/factor;
  }
  return result;
}

// ___________________________________________________________________________
double approximateEulersNumberAlternative(int n) {
  // Only stepwidth > 1 is ok.
  if (n < 1) {
    return -1.0;
  }

  double sum = 0.0;
  int i = 0;
  while (sum <= 1) {
    sum += 1.0 / (n + i);
    i++;
  }

  // 1.0 * n instead of static_cast<double>(n) as that is currently unknown.
  return 1.0 + i / (1.0 * n);
}
