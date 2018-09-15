// Copyright 2018, University of Freiburg,Victor Maier
// Chair of Algorithms and Data Structures.
// Author: Victor Maier

#include <gtest/gtest.h>
#include <math.h>
#include "./ApproximationEulersNumber.h"
// Test for the faculty function and the approximation function for e.
TEST(ApproximationEulersNumber, ApproximationEulersNumber) {
  ASSERT_EQ(1, calc_fac(1, 1));
  ASSERT_EQ(2, calc_fac(1, 2));
  ASSERT_EQ(6, calc_fac(2, 3));
  ASSERT_EQ(24, calc_fac(6, 4));
  ASSERT_EQ(1.0, approximateEulersNumber(0));
  ASSERT_EQ(2.0, approximateEulersNumber(1));
  ASSERT_EQ(2.5, approximateEulersNumber(2));
  ASSERT_DOUBLE_EQ(M_E, approximateEulersNumber(30));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
