// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

// IMPORTANT:
// You are not required to write this many tests in your solution.

#include <gtest/gtest.h>
#include "./GameOfLife.h"

TEST(GameOfLife, aliveNeighboursSingle) {
  bool grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  oldGrid = &grid;

  // Test empty field and border handling.
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      (*oldGrid)[x][y] = false;
    }
  }
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_EQ(0, aliveNeighbours(x, y));
    }
  }

  // Test for only neigbours are counted.
  (*oldGrid)[2][1] = true;
  ASSERT_EQ(1, aliveNeighbours(1, 0));
  ASSERT_EQ(1, aliveNeighbours(2, 0));
  ASSERT_EQ(1, aliveNeighbours(3, 0));
  ASSERT_EQ(1, aliveNeighbours(1, 1));
  ASSERT_EQ(0, aliveNeighbours(2, 1));
  ASSERT_EQ(1, aliveNeighbours(3, 1));
  ASSERT_EQ(1, aliveNeighbours(1, 2));
  ASSERT_EQ(1, aliveNeighbours(2, 2));
  ASSERT_EQ(1, aliveNeighbours(3, 2));
}

TEST(GameOfLife, aliveNeighboursMultiple) {
  bool grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  oldGrid = &grid;

  // Test for only neigbours are counted.
  (*oldGrid)[4][4] = true;
  (*oldGrid)[4][5] = true;
  (*oldGrid)[5][4] = true;
  (*oldGrid)[5][5] = true;
  ASSERT_EQ(1, aliveNeighbours(3, 3));
  ASSERT_EQ(2, aliveNeighbours(3, 4));
  ASSERT_EQ(2, aliveNeighbours(3, 5));
  ASSERT_EQ(1, aliveNeighbours(3, 6));
  ASSERT_EQ(2, aliveNeighbours(4, 3));
  ASSERT_EQ(3, aliveNeighbours(4, 4));
  ASSERT_EQ(3, aliveNeighbours(4, 5));
  ASSERT_EQ(2, aliveNeighbours(4, 6));
  ASSERT_EQ(2, aliveNeighbours(5, 3));
  ASSERT_EQ(3, aliveNeighbours(5, 4));
  ASSERT_EQ(3, aliveNeighbours(5, 5));
  ASSERT_EQ(2, aliveNeighbours(5, 6));
  ASSERT_EQ(1, aliveNeighbours(6, 3));
  ASSERT_EQ(2, aliveNeighbours(6, 4));
  ASSERT_EQ(2, aliveNeighbours(6, 5));
  ASSERT_EQ(1, aliveNeighbours(6, 6));
}

TEST(GameOfLife, processUserInputEsc) {
  ASSERT_EQ(-1, processUserInput(27));
}

TEST(GameOfLife, processUserInputSpace) {
  ASSERT_EQ(1, processUserInput(' '));
}

TEST(GameOfLife, processUserInputSmallS) {
  ASSERT_EQ(2, processUserInput('s'));
}

TEST(GameOfLife, processUserInputSmallG) {
  // Glider is 3x3
  bool grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  newGrid = &grid;

  lastClickedX = 3;
  lastClickedY = 3;
  for (int x = lastClickedX; x < lastClickedX + 3; ++x) {
    for (int y = lastClickedY; y < lastClickedY + 3; ++y) {
      ASSERT_FALSE(grid[x][y]);
    }
  }
  ASSERT_EQ(0, processUserInput('g'));
  int count = 0;
  for (int x = lastClickedX; x < lastClickedX + 3; ++x) {
    for (int y = lastClickedY; y < lastClickedY + 3; ++y) {
      count += grid[x][y];
    }
  }
  ASSERT_EQ(5, count);
}

TEST(GameOfLife, processUserInputBigG) {
  // Cannon is 46x9
  bool grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  newGrid = &grid;

  lastClickedX = 3;
  lastClickedY = 3;
  for (int x = lastClickedX; x < lastClickedX + 36; ++x) {
    for (int y = lastClickedY; y < lastClickedY + 9; ++y) {
      ASSERT_FALSE(grid[x][y]);
    }
  }
  ASSERT_EQ(0, processUserInput('G'));
  int count = 0;
  for (int x = lastClickedX; x < lastClickedX + 36; ++x) {
    for (int y = lastClickedY; y < lastClickedY + 9; ++y) {
      count += grid[x][y];
    }
  }
  ASSERT_EQ(36, count);
}

TEST(GameOfLife, processUserInputSmallR) {
  bool grid[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  newGrid = &grid;

  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_FALSE(grid[x][y]);
    }
  }
  ASSERT_EQ(0, processUserInput('r'));
  int count = 0;
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      count += grid[x][y];
    }
  }
  // Chance is 1/5, so we shall have more than 1/6 ...
  ASSERT_LT((MAX_GRID_SIZE * MAX_GRID_SIZE / 6), count);
  // but less than 1/4 of total cells alive.
  ASSERT_GT((MAX_GRID_SIZE * MAX_GRID_SIZE / 4), count);
}

TEST(GameOfLife, updateStateEmptyGrid) {
  // Empty stays empty
  bool grid1[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  bool grid2[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  oldGrid = &grid1;
  newGrid = &grid2;
  updateState();
  ASSERT_EQ(0, livingCells);
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_FALSE(grid1[x][y]);
      ASSERT_FALSE(grid2[x][y]);
    }
  }
}

TEST(GameOfLife, updateStateStaticObject) {
  // Static object stays in place
  bool grid1[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  bool grid2[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  oldGrid = &grid1;
  newGrid = &grid2;
  grid1[4][4] = 1;
  grid1[4][5] = 1;
  grid1[5][4] = 1;
  grid1[5][5] = 1;
  updateState();
  ASSERT_EQ(4, livingCells);
  ASSERT_FALSE(grid2[3][3]);
  ASSERT_FALSE(grid2[3][4]);
  ASSERT_FALSE(grid2[3][5]);
  ASSERT_FALSE(grid2[3][6]);
  ASSERT_FALSE(grid2[4][3]);
  ASSERT_TRUE(grid2[4][4]);
  ASSERT_TRUE(grid2[4][5]);
  ASSERT_FALSE(grid2[4][6]);
  ASSERT_FALSE(grid2[5][3]);
  ASSERT_TRUE(grid2[5][4]);
  ASSERT_TRUE(grid2[5][5]);
  ASSERT_FALSE(grid2[5][6]);
  ASSERT_FALSE(grid2[6][3]);
  ASSERT_FALSE(grid2[6][4]);
  ASSERT_FALSE(grid2[6][5]);
  ASSERT_FALSE(grid2[6][6]);
}

TEST(GameOfLife, updateStateP2Blinker) {
  // Tests updateState function with a period 2 blinker.
  bool grid1[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  bool grid2[MAX_GRID_SIZE][MAX_GRID_SIZE] = { 0 };
  oldGrid = &grid1;
  newGrid = &grid2;
  // -
  grid1[4][4] = 1;
  grid1[4][5] = 1;
  grid1[4][6] = 1;
  // |
  updateState();
  ASSERT_EQ(3, livingCells);
  ASSERT_FALSE(grid2[3][4]);
  ASSERT_TRUE(grid2[3][5]);
  ASSERT_FALSE(grid2[3][6]);
  ASSERT_FALSE(grid2[4][4]);
  ASSERT_TRUE(grid2[4][5]);
  ASSERT_FALSE(grid2[4][6]);
  ASSERT_FALSE(grid2[5][4]);
  ASSERT_TRUE(grid2[5][5]);
  ASSERT_FALSE(grid2[5][6]);
  // -
  updateState();
  ASSERT_EQ(3, livingCells);
  ASSERT_FALSE(grid1[3][4]);
  ASSERT_FALSE(grid1[3][5]);
  ASSERT_FALSE(grid1[3][6]);
  ASSERT_TRUE(grid1[4][4]);
  ASSERT_TRUE(grid1[4][5]);
  ASSERT_TRUE(grid1[4][6]);
  ASSERT_FALSE(grid1[5][4]);
  ASSERT_FALSE(grid1[5][5]);
  ASSERT_FALSE(grid1[5][6]);
}
