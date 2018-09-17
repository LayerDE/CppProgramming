// Copyright [year] <Copyright Owner>

#include <gtest/gtest.h>
#include "./Bridge.h"
#include "./Island.h"
#include <string>

TEST(ProjectTest, BridgeComputeInput) {
  Island *iA, *iB;
  Bridge *bg;
  iA = new Island(2, 0, 1);
  iB = new Island(2, 2, 1);
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

TEST(ProjectTest, IslandIsOK) {
  Island *iA, *iB, *iC;
  Bridge *bAB,*bAC;
  iA = new Island(3, 2, 0);
  iB = new Island(1, 1, 0);
  iC = new Island(2, 2, 3);
  bAB = new Bridge(iA, iB);
  bAC = new Bridge(iA, iC);
  ASSERT_EQ(0, bAB->getState());
  ASSERT_EQ(false, iA ->isOk());
  bAB->computeInput();
  ASSERT_EQ(1, bAB->getState());
  ASSERT_EQ(false, iA ->isOk());
  bAB->computeInput();
  ASSERT_EQ(2, bAB->getState());
  ASSERT_EQ(false, iA ->isOk());
  bAC->computeInput();
  ASSERT_EQ(1, bAC->getState());
  ASSERT_EQ(true, iA ->isOk());
  delete bAB;
  delete bAC;
  delete iA;
  delete iB;
}
