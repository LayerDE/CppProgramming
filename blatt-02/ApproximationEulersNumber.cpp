// Copyright 2018, University of Freiburg,Victor Maier
// Chair of Algorithms and Data Structures.
// Author: Victor Maier
#include <inttypes.h>
#include "./ApproximationEulersNumber.h"
// A Function to calculate the faculty
// it need the last result and the next multiplayer
// x! = x_-1*x  x_0 = 1
uint64_t calc_fac(uint64_t fac_n_minus_1, int n) {
  return fac_n_minus_1*n;
}

// Approximate e with the endless sum of 1/x! method
// e=sum(1/x!) 0-inf
double approximateEulersNumber(int rounds) {
  double tmp_e = 1;
  uint64_t tmp_fac = 1, tmp_fac_n_minus_1;
  for (int x = 1; rounds; rounds--, x++) {
    tmp_fac = calc_fac(tmp_fac_n_minus_1 = tmp_fac, x);
    if (tmp_fac_n_minus_1 <= tmp_fac)
      tmp_e += 1.0 / static_cast<double>(tmp_fac);
    else  // A overflow in the faculty: n is too high!
          // the program displays the last valid result
      break;
  }
  return tmp_e;
}
