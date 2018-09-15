// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./InputOutput.h"

// _____________________________________________________________________________
TEST(InputOutputTest, parseCommandLineArguments) {
  InputOutput io;
  int argc = 3;
  char* argv[3] = {
    const_cast<char*>("./InputOutputMain"),
    const_cast<char*>("--head=10"),
    const_cast<char*>("-n"),
  };
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ASSERT_DEATH(io.parseCommandLineArguments(argc, argv), "Usage: .*");
}
