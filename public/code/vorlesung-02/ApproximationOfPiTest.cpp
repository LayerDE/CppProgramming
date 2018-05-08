// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./ApproximationOfPi.h"

// Test for approximatePiUsingCircleMethod.
TEST(ApproximationOfPi, approximatePiUsingCircleMethod) {
  ASSERT_EQ(5, approximatePiUsingCircleMethod(1));
  ASSERT_EQ(13, approximatePiUsingCircleMethod(2));
  ASSERT_EQ(29, approximatePiUsingCircleMethod(3));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
