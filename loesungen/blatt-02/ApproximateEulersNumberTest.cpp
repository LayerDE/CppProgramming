// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include "./ApproximateEulersNumber.h"

// ___________________________________________________________________________
TEST(ApproximateEulersNumberTest, approximateEulersNumber) {
  ASSERT_DOUBLE_EQ(1.0, approximateEulersNumber(0));
  ASSERT_DOUBLE_EQ(1.0, approximateEulersNumber(1));
  ASSERT_DOUBLE_EQ(2.0, approximateEulersNumber(2));
  ASSERT_DOUBLE_EQ(2.5, approximateEulersNumber(3));
}

TEST(ApproximateEulersNumberTest, approximateEulersNumberAlternative) {
  ASSERT_DOUBLE_EQ(3.0, approximateEulersNumberAlternative(1));
  ASSERT_DOUBLE_EQ(2.5, approximateEulersNumberAlternative(2));
  ASSERT_DOUBLE_EQ(2.75, approximateEulersNumberAlternative(4));
  ASSERT_DOUBLE_EQ(2.6, approximateEulersNumberAlternative(5));
}

// Main programm for executing the tests
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
