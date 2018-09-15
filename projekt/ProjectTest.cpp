// Copyright [year] <Copyright Owner>

#include <gtest/gtest.h>
#include <./Bridge.h>
#include <./Island.h>
#include <string>

TEST(ProjectTest, BridgeComputeInput) {
  Island *iA, *iB;
  Bridge *bg;
  iA = new Island(2, 0, 0);
  iB = new Island(2, 1, 1);
  bg = new Bridge(iA, iB);
  ASSERT_EQ(0, bg->getState());
  bg->computeInput();
  ASSERT_EQ(1, bg->getState());
  bg->computeInput();
  ASSERT_EQ(2, bg->getState());
  bg->computeInput();
  ASSERT_EQ(0, bg->getState());
  delete bg;
  delete iA;
  delete iB;
}
