// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <gtest/gtest.h>
#include "./GameOfLife.h"

// _____________________________________________________________________________
TEST(GameOfLifeTest, updateState) {
  GameOfLife game1;
  // printf("%p\n", static_cast<void*>(&game1));

  game1._state[0][0] = 0;
  game1._state[0][1] = 0;
  game1._state[0][2] = 0;
  game1._state[1][0] = 0;
  game1._state[1][1] = 1;
  game1._state[1][2] = 0;
  game1._state[2][0] = 0;
  game1._state[2][1] = 0;
  game1._state[2][2] = 0;
  ASSERT_EQ(1, game1._state[1][1]);
  game1.updateState();
  ASSERT_EQ(0, game1._state[1][1]);

  GameOfLife game2;
  // printf("%p\n", static_cast<void*>(&game2));

  game2._state[0][0] = 0;
  game2._state[0][1] = 0;
  game2._state[0][2] = 1;
  game2._state[1][0] = 0;
  game2._state[1][1] = 0;
  game2._state[1][2] = 0;
  game2._state[2][0] = 1;
  game2._state[2][1] = 1;
  game2._state[2][2] = 0;
  ASSERT_EQ(0, game2._state[1][1]);
  game2.updateState();
  ASSERT_EQ(1, game2._state[1][1]);
}
