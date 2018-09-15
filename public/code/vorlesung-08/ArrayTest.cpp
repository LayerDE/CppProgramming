// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <gtest/gtest.h>
// #include <iostream>
#include "./Array.h"

// _____________________________________________________________________________
TEST(ArrayTest, Array) {
  {
    int array[3] = { 1, 2, 3 };
    Array<int> ai(array, 3);
    ASSERT_EQ(3, ai._size);
    ASSERT_EQ(1, ai.get(0));
    ASSERT_EQ(2, ai.get(1));
    ASSERT_EQ(3, ai.get(2));
  }

  {
    float array[3] = { 1.1, 2.2, 42.0 };
    Array<float> af(array, 3);
    ASSERT_FLOAT_EQ(3, af._size);
    ASSERT_FLOAT_EQ(1.1, af.get(0));
    ASSERT_FLOAT_EQ(2.2, af.get(1));
    ASSERT_FLOAT_EQ(42.0, af.get(2));
    // std::cout << af << std::endl;
  }

  {
    bool array[3] = { true, false, true };
    Array<bool> af(array, 3);
    ASSERT_EQ(3, af._size);
    ASSERT_TRUE(af.get(0));
    ASSERT_FALSE(af.get(1));
    ASSERT_TRUE(af.get(2));
  }
}



// OLD NON-TEMPLATED CODE

// _____________________________________________________________________________
TEST(ArrayTest, ArrayInt) {
  int array[3] = { 1, 2, 3 };
  ArrayInt ai(array, 3);
  ASSERT_EQ(3, ai._size);
  ASSERT_EQ(1, ai.get(0));
  ASSERT_EQ(2, ai.get(1));
  ASSERT_EQ(3, ai.get(2));
}

// _____________________________________________________________________________
TEST(ArrayTest, ArrayFloat) {
  float array[3] = { 1.1, 2.2, 42.0 };
  ArrayFloat af(array, 3);
  ASSERT_FLOAT_EQ(3, af._size);
  ASSERT_FLOAT_EQ(1.1, af.get(0));
  ASSERT_FLOAT_EQ(2.2, af.get(1));
  ASSERT_FLOAT_EQ(42.0, af.get(2));
}
