// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef APPROXIMATEEULERSNUMBER_H_
#define APPROXIMATEEULERSNUMBER_H_

// Approximates e using the formula:
// e = sum(1/n!), returns -1 for negativ iterations.
double approximateEulersNumber(int iterations);

// Computes e by calculation the integral 1/x dx starting at 1. This integral
// will be 1 as soon as e is hit.
// Returns -1 for step width < 1.
double approximateEulersNumberAlternative(int n);

#endif  // APPROXIMATEEULERSNUMBER_H_
