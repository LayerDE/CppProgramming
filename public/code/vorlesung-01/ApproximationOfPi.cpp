// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

// Function that computes the approximation of Pi using the circle method.
// Returns the number of integer grid points in the circle of radius n.
int approximatePiUsingCircleMethod(int n) {
  int count = 0;
  for (int x = -n; x <= +n; x++) {
    for (int y = -n; y <= +n; y++) {
      if (x * x + y * y <= n * n) {
        count++;
      }
    }
  }
  return count;
}
