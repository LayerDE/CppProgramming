// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include "./GameOfLifePrefab.h"

TEST(GameOfLifePrefab, getNumberOfCellsDefault) {
  GameOfLifePrefab prefab;
  ASSERT_EQ(0, prefab.getNumberOfCells());
}

TEST(GameOfLifePrefab, getNumberOfCells) {
  GameOfLifePrefab prefab;
  prefab._length = 4;
  ASSERT_EQ(4, prefab.getNumberOfCells());
}

TEST(GameOfLifePrefab, select) {
  GameOfLifePrefab prefab;
  ASSERT_EQ(0, prefab.getNumberOfCells());
  prefab.select(0);
  ASSERT_EQ(5, prefab.getNumberOfCells());
  prefab.select(1);
  ASSERT_EQ(36, prefab.getNumberOfCells());
}

TEST(GameOfLifePrefab, getRelativeX) {
  GameOfLifePrefab prefab;
  prefab.select(0);
  ASSERT_EQ(1, prefab.getRelativeX(0));
  ASSERT_EQ(2, prefab.getRelativeX(1));
  ASSERT_EQ(0, prefab.getRelativeX(2));
}

TEST(GameOfLifePrefab, getRelativeY) {
  GameOfLifePrefab prefab;
  prefab.select(0);
  ASSERT_EQ(0, prefab.getRelativeY(0));
  ASSERT_EQ(1, prefab.getRelativeY(1));
  ASSERT_EQ(2, prefab.getRelativeY(2));
}
