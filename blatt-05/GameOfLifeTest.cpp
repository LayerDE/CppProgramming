// Copyright 2018, Victor Maier

// IMPORTANT:
// You are not required to write this many tests in your solution.

#include <gtest/gtest.h>
#include "./GameOfLife.h"

TEST(GameOfLife, aliveNeighboursSingle) {
  GameOfLife *g = new GameOfLife();

  // Test empty field and border handling.
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      (*(g->oldGrid))[x][y] = false;
    }
  }
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_EQ(0, g->aliveNeighbours(x, y));
    }
  }

  // Test for only neigbours are counted.
  (*(g->oldGrid))[2][1] = true;
  ASSERT_EQ(1, g->aliveNeighbours(1, 0));
  ASSERT_EQ(1, g->aliveNeighbours(2, 0));
  ASSERT_EQ(1, g->aliveNeighbours(3, 0));
  ASSERT_EQ(1, g->aliveNeighbours(1, 1));
  ASSERT_EQ(0, g->aliveNeighbours(2, 1));
  ASSERT_EQ(1, g->aliveNeighbours(3, 1));
  ASSERT_EQ(1, g->aliveNeighbours(1, 2));
  ASSERT_EQ(1, g->aliveNeighbours(2, 2));
  ASSERT_EQ(1, g->aliveNeighbours(3, 2));
  delete g;
}

TEST(GameOfLife, aliveNeighboursMultiple) {
  GameOfLife *g = new GameOfLife();
  // Test for only neigbours are counted.
  (*(g->oldGrid))[4][4] = true;
  (*(g->oldGrid))[4][5] = true;
  (*(g->oldGrid))[5][4] = true;
  (*(g->oldGrid))[5][5] = true;
  ASSERT_EQ(1, g->aliveNeighbours(3, 3));
  ASSERT_EQ(2, g->aliveNeighbours(3, 4));
  ASSERT_EQ(2, g->aliveNeighbours(3, 5));
  ASSERT_EQ(1, g->aliveNeighbours(3, 6));
  ASSERT_EQ(2, g->aliveNeighbours(4, 3));
  ASSERT_EQ(3, g->aliveNeighbours(4, 4));
  ASSERT_EQ(3, g->aliveNeighbours(4, 5));
  ASSERT_EQ(2, g->aliveNeighbours(4, 6));
  ASSERT_EQ(2, g->aliveNeighbours(5, 3));
  ASSERT_EQ(3, g->aliveNeighbours(5, 4));
  ASSERT_EQ(3, g->aliveNeighbours(5, 5));
  ASSERT_EQ(2, g->aliveNeighbours(5, 6));
  ASSERT_EQ(1, g->aliveNeighbours(6, 3));
  ASSERT_EQ(2, g->aliveNeighbours(6, 4));
  ASSERT_EQ(2, g->aliveNeighbours(6, 5));
  ASSERT_EQ(1, g->aliveNeighbours(6, 6));
  delete g;
}

TEST(GameOfLife, processUserInputEsc) {
  GameOfLife *g = new GameOfLife();
  ASSERT_EQ(-1, g->processUserInput(27));
  delete g;
}

TEST(GameOfLife, processUserInputSpace) {
  GameOfLife *g = new GameOfLife();
  ASSERT_EQ(1, g->processUserInput(' '));
  delete g;
}

TEST(GameOfLife, processUserInputSmallS) {
  GameOfLife *g = new GameOfLife();
  ASSERT_EQ(2, g->processUserInput('s'));
  delete g;
}

TEST(GameOfLife, processUserInputSmallG) {
  // Glider is 3x3
  GameOfLife *g = new GameOfLife();

  g->lastClickedX = 3;
  g->lastClickedY = 3;
  for (int x = g->lastClickedX; x < g->lastClickedX + 3; ++x) {
    for (int y = g->lastClickedY; y < g->lastClickedY + 3; ++y) {
      ASSERT_FALSE((*(g->newGrid))[x][y]);
    }
  }
  ASSERT_EQ(0, g->processUserInput('g'));
  int count = 0;
  for (int x = g->lastClickedX; x < g->lastClickedX + 3; ++x) {
    for (int y = g->lastClickedY; y < g->lastClickedY + 3; ++y) {
      count += (*(g->newGrid))[x][y];
    }
  }
  ASSERT_EQ(5, count);
  delete g;
}

TEST(GameOfLife, processUserInputBigG) {
  // Cannon is 46x9

  GameOfLife *g = new GameOfLife();
  g->lastClickedX = 3;
  g->lastClickedY = 3;
  for (int x = g->lastClickedX; x < g->lastClickedX + 36; ++x) {
    for (int y = g->lastClickedY; y < g->lastClickedY + 9; ++y) {
      ASSERT_FALSE((*(g->newGrid))[x][y]);
    }
  }
  ASSERT_EQ(0, g->processUserInput('G'));
  int count = 0;
  for (int x = g->lastClickedX; x < g->lastClickedX + 36; ++x) {
    for (int y = g->lastClickedY; y < g->lastClickedY + 9; ++y) {
      count += (*(g->newGrid))[x][y];
    }
  }
  ASSERT_EQ(36, count);
  delete g;
}

TEST(GameOfLife, processUserInputSmallR) {
  GameOfLife *g = new GameOfLife();

  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_FALSE((*(g->newGrid))[x][y]);
    }
  }
  ASSERT_EQ(0, g->processUserInput('r'));
  int count = 0;
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      count += (*(g->newGrid))[x][y];
    }
  }
  // Chance is 1/5, so we shall have more than 1/6 ...
  ASSERT_LT((MAX_GRID_SIZE * MAX_GRID_SIZE / 6), count);
  // but less than 1/4 of total cells alive.
  ASSERT_GT((MAX_GRID_SIZE * MAX_GRID_SIZE / 4), count);
  delete g;
}

TEST(GameOfLife, updateStateEmptyGrid) {
  // Empty stays empty
  GameOfLife *g = new GameOfLife();
  g->updateState();
  ASSERT_EQ(0, g->livingCells);
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_FALSE((*(g->oldGrid))[x][y]);
      ASSERT_FALSE((*(g->newGrid))[x][y]);
    }
  }
  delete g;
}

TEST(GameOfLife, updateStateStaticObject) {
  GameOfLife *g = new GameOfLife();
  // Static object stays in place
  (*(g->oldGrid))[4][4] = 1;
  (*(g->oldGrid))[4][5] = 1;
  (*(g->oldGrid))[5][4] = 1;
  (*(g->oldGrid))[5][5] = 1;
  g->updateState();
  ASSERT_EQ(4, g->livingCells);
  ASSERT_FALSE((*(g->newGrid))[3][3]);
  ASSERT_FALSE((*(g->newGrid))[3][4]);
  ASSERT_FALSE((*(g->newGrid))[3][5]);
  ASSERT_FALSE((*(g->newGrid))[3][6]);
  ASSERT_FALSE((*(g->newGrid))[4][3]);
  ASSERT_TRUE((*(g->newGrid))[4][4]);
  ASSERT_TRUE((*(g->newGrid))[4][5]);
  ASSERT_FALSE((*(g->newGrid))[4][6]);
  ASSERT_FALSE((*(g->newGrid))[5][3]);
  ASSERT_TRUE((*(g->newGrid))[5][4]);
  ASSERT_TRUE((*(g->newGrid))[5][5]);
  ASSERT_FALSE((*(g->newGrid))[5][6]);
  ASSERT_FALSE((*(g->newGrid))[6][3]);
  ASSERT_FALSE((*(g->newGrid))[6][4]);
  ASSERT_FALSE((*(g->newGrid))[6][5]);
  ASSERT_FALSE((*(g->newGrid))[6][6]);
  delete g;
}

TEST(GameOfLife, updateStateP2Blinker) {
  // Tests updateState function with a period 2 blinker.
  GameOfLife *g = new GameOfLife();
  // -
  (*(g->oldGrid))[4][4] = 1;
  (*(g->oldGrid))[4][5] = 1;
  (*(g->oldGrid))[4][6] = 1;
  // |
  g->updateState();
  ASSERT_EQ(3, g->livingCells);
  ASSERT_FALSE((*(g->newGrid))[3][4]);
  ASSERT_TRUE((*(g->newGrid))[3][5]);
  ASSERT_FALSE((*(g->newGrid))[3][6]);
  ASSERT_FALSE((*(g->newGrid))[4][4]);
  ASSERT_TRUE((*(g->newGrid))[4][5]);
  ASSERT_FALSE((*(g->newGrid))[4][6]);
  ASSERT_FALSE((*(g->newGrid))[5][4]);
  ASSERT_TRUE((*(g->newGrid))[5][5]);
  ASSERT_FALSE((*(g->newGrid))[5][6]);
  // -
  g->updateState();
  ASSERT_EQ(3, g->livingCells);
  ASSERT_FALSE((*(g->oldGrid))[3][4]);
  ASSERT_FALSE((*(g->oldGrid))[3][5]);
  ASSERT_FALSE((*(g->oldGrid))[3][6]);
  ASSERT_TRUE((*(g->oldGrid))[4][4]);
  ASSERT_TRUE((*(g->oldGrid))[4][5]);
  ASSERT_TRUE((*(g->oldGrid))[4][6]);
  ASSERT_FALSE((*(g->oldGrid))[5][4]);
  ASSERT_FALSE((*(g->oldGrid))[5][5]);
  ASSERT_FALSE((*(g->oldGrid))[5][6]);
  delete g;
}
