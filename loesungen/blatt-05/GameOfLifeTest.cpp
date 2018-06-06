// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include "./GameOfLife.h"

TEST(GameOfLife, aliveNeighboursSingle) {
  GameOfLife game;

  // Test empty field and border handling.
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      (*game._oldGrid)[x][y] = false;
    }
  }
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_EQ(0, game.aliveNeighbours(x, y));
    }
  }

  // Test for only neigbours are counted.
  (*game._oldGrid)[2][1] = true;
  ASSERT_EQ(1, game.aliveNeighbours(1, 0));
  ASSERT_EQ(1, game.aliveNeighbours(2, 0));
  ASSERT_EQ(1, game.aliveNeighbours(3, 0));
  ASSERT_EQ(1, game.aliveNeighbours(1, 1));
  ASSERT_EQ(0, game.aliveNeighbours(2, 1));
  ASSERT_EQ(1, game.aliveNeighbours(3, 1));
  ASSERT_EQ(1, game.aliveNeighbours(1, 2));
  ASSERT_EQ(1, game.aliveNeighbours(2, 2));
  ASSERT_EQ(1, game.aliveNeighbours(3, 2));
}

TEST(GameOfLife, aliveNeighboursMultiple) {
  GameOfLife game;

  // Test for only neigbours are counted.
  (*game._oldGrid)[4][4] = true;
  (*game._oldGrid)[4][5] = true;
  (*game._oldGrid)[5][4] = true;
  (*game._oldGrid)[5][5] = true;
  ASSERT_EQ(1, game.aliveNeighbours(3, 3));
  ASSERT_EQ(2, game.aliveNeighbours(3, 4));
  ASSERT_EQ(2, game.aliveNeighbours(3, 5));
  ASSERT_EQ(1, game.aliveNeighbours(3, 6));
  ASSERT_EQ(2, game.aliveNeighbours(4, 3));
  ASSERT_EQ(3, game.aliveNeighbours(4, 4));
  ASSERT_EQ(3, game.aliveNeighbours(4, 5));
  ASSERT_EQ(2, game.aliveNeighbours(4, 6));
  ASSERT_EQ(2, game.aliveNeighbours(5, 3));
  ASSERT_EQ(3, game.aliveNeighbours(5, 4));
  ASSERT_EQ(3, game.aliveNeighbours(5, 5));
  ASSERT_EQ(2, game.aliveNeighbours(5, 6));
  ASSERT_EQ(1, game.aliveNeighbours(6, 3));
  ASSERT_EQ(2, game.aliveNeighbours(6, 4));
  ASSERT_EQ(2, game.aliveNeighbours(6, 5));
  ASSERT_EQ(1, game.aliveNeighbours(6, 6));
}

TEST(GameOfLife, processUserInputEsc) {
  GameOfLife game;
  ASSERT_EQ(-1, game.processUserInput(27));
}

TEST(GameOfLife, processUserInputSpace) {
  GameOfLife game;
  ASSERT_EQ(1, game.processUserInput(' '));
}

TEST(GameOfLife, processUserInputSmallS) {
  GameOfLife game;
  ASSERT_EQ(2, game.processUserInput('s'));
}

TEST(GameOfLife, processUserInputSmallG) {
  GameOfLife game;
  game._lastClickedX = 3;
  game._lastClickedY = 3;
  for (int x = game._lastClickedX; x < game._lastClickedX + 3; ++x) {
    for (int y = game._lastClickedY; y < game._lastClickedY + 3; ++y) {
      ASSERT_FALSE((*game._newGrid)[x][y]);
    }
  }
  ASSERT_EQ(0, game.processUserInput('g'));
  int count = 0;
  for (int x = game._lastClickedX; x < game._lastClickedX + 3; ++x) {
    for (int y = game._lastClickedY; y < game._lastClickedY + 3; ++y) {
      count += (*game._newGrid)[x][y];
    }
  }
  ASSERT_EQ(5, count);
}

TEST(GameOfLife, processUserInputBigG) {
  GameOfLife game;
  game._lastClickedX = 3;
  game._lastClickedY = 3;
  for (int x = game._lastClickedX; x < game._lastClickedX + 36; ++x) {
    for (int y = game._lastClickedY; y < game._lastClickedY + 9; ++y) {
      ASSERT_FALSE((*game._newGrid)[x][y]);
    }
  }
  ASSERT_EQ(0, game.processUserInput('G'));
  int count = 0;
  for (int x = game._lastClickedX; x < game._lastClickedX + 36; ++x) {
    for (int y = game._lastClickedY; y < game._lastClickedY + 9; ++y) {
      count += (*game._newGrid)[x][y];
    }
  }
  ASSERT_EQ(36, count);
}

TEST(GameOfLife, processUserInputSmallR) {
  GameOfLife game;

  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_FALSE((*game._newGrid)[x][y]);
    }
  }
  ASSERT_EQ(0, game.processUserInput('r'));
  int count = 0;
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      count += (*game._newGrid)[x][y];
    }
  }
  // Chance is 1/5, so we shall have more than 1/6 ...
  ASSERT_LT((MAX_GRID_SIZE * MAX_GRID_SIZE / 6), count);
  // but less than 1/4 of total cells alive.
  ASSERT_GT((MAX_GRID_SIZE * MAX_GRID_SIZE / 4), count);
}

TEST(GameOfLife, insertPrefab0) {
  GameOfLife game;
  GameOfLifePrefab prefab;
  prefab.select(0);
  int maxX = 0;
  int maxY = 0;
  for (int i = 0; i < prefab.getNumberOfCells(); ++i) {
    maxX = prefab.getRelativeX(i) > maxX ? prefab.getRelativeX(i) : maxX;
    maxY = prefab.getRelativeY(i) > maxY ? prefab.getRelativeY(i) : maxY;
  }
  for (int x = 0; x <= maxX; ++x) {
    for (int y = 0; y <= maxY; ++y) {
      ASSERT_FALSE((*game._newGrid)[x][y]);
    }
  }
  game.insertPrefab(0, 0, prefab);
  int count = 0;
  for (int x = 0; x <= maxX; ++x) {
    for (int y = 0; y <= maxY; ++y) {
      count += (*game._newGrid)[x][y];
    }
  }
  ASSERT_EQ(prefab.getNumberOfCells(), count);
  for (int i = 0; i < prefab.getNumberOfCells(); ++i) {
    ASSERT_TRUE((*game._newGrid)[prefab.getRelativeX(i)]
                [prefab.getRelativeY(i)]);
  }
}

TEST(GameOfLife, insertPrefab1) {
  GameOfLife game;
  GameOfLifePrefab prefab;
  prefab.select(1);
  int maxX = 0;
  int maxY = 0;
  for (int i = 0; i < prefab.getNumberOfCells(); ++i) {
    maxX = prefab.getRelativeX(i) > maxX ? prefab.getRelativeX(i) : maxX;
    maxY = prefab.getRelativeY(i) > maxY ? prefab.getRelativeY(i) : maxY;
  }
  for (int x = 0; x <= maxX; ++x) {
    for (int y = 0; y <= maxY; ++y) {
      ASSERT_FALSE((*game._newGrid)[x][y]);
    }
  }
  game.insertPrefab(0, 0, prefab);
  int count = 0;
  for (int x = 0; x <= maxX; ++x) {
    for (int y = 0; y <= maxY; ++y) {
      count += (*game._newGrid)[x][y];
    }
  }
  ASSERT_EQ(prefab.getNumberOfCells(), count);
  for (int i = 0; i < prefab.getNumberOfCells(); ++i) {
    ASSERT_TRUE((*game._newGrid)[prefab.getRelativeX(i)]
                [prefab.getRelativeY(i)]);
  }
}

TEST(GameOfLife, updateStateEmptyGrid) {
  GameOfLife game;
  // Empty stays empty
  game.updateState();
  ASSERT_EQ(0, game._livingCells);
  for (int x = 0; x < MAX_GRID_SIZE; ++x) {
    for (int y = 0; y < MAX_GRID_SIZE; ++y) {
      ASSERT_FALSE((*game._oldGrid)[x][y]);
      ASSERT_FALSE((*game._newGrid)[x][y]);
    }
  }
}

TEST(GameOfLife, updateStateStaticObject) {
  GameOfLife game;
  // Static object stays in place
  (*game._oldGrid)[4][4] = 1;
  (*game._oldGrid)[4][5] = 1;
  (*game._oldGrid)[5][4] = 1;
  (*game._oldGrid)[5][5] = 1;
  game.updateState();
  ASSERT_EQ(4, game._livingCells);
  ASSERT_FALSE((*game._newGrid)[3][3]);
  ASSERT_FALSE((*game._newGrid)[3][4]);
  ASSERT_FALSE((*game._newGrid)[3][5]);
  ASSERT_FALSE((*game._newGrid)[3][6]);
  ASSERT_FALSE((*game._newGrid)[4][3]);
  ASSERT_TRUE((*game._newGrid)[4][4]);
  ASSERT_TRUE((*game._newGrid)[4][5]);
  ASSERT_FALSE((*game._newGrid)[4][6]);
  ASSERT_FALSE((*game._newGrid)[5][3]);
  ASSERT_TRUE((*game._newGrid)[5][4]);
  ASSERT_TRUE((*game._newGrid)[5][5]);
  ASSERT_FALSE((*game._newGrid)[5][6]);
  ASSERT_FALSE((*game._newGrid)[6][3]);
  ASSERT_FALSE((*game._newGrid)[6][4]);
  ASSERT_FALSE((*game._newGrid)[6][5]);
  ASSERT_FALSE((*game._newGrid)[6][6]);
}

TEST(GameOfLife, updateStateP2Blinker) {
  GameOfLife game;
  // Tests updateState function with a period 2 blinker.
  // -
  (*game._oldGrid)[4][4] = 1;
  (*game._oldGrid)[4][5] = 1;
  (*game._oldGrid)[4][6] = 1;
  // |
  game.updateState();
  ASSERT_EQ(3, game._livingCells);
  ASSERT_FALSE((*game._newGrid)[3][4]);
  ASSERT_TRUE((*game._newGrid)[3][5]);
  ASSERT_FALSE((*game._newGrid)[3][6]);
  ASSERT_FALSE((*game._newGrid)[4][4]);
  ASSERT_TRUE((*game._newGrid)[4][5]);
  ASSERT_FALSE((*game._newGrid)[4][6]);
  ASSERT_FALSE((*game._newGrid)[5][4]);
  ASSERT_TRUE((*game._newGrid)[5][5]);
  ASSERT_FALSE((*game._newGrid)[5][6]);
  // -
  bool (*tempGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE] = game._newGrid;
  game._newGrid = game._oldGrid;
  game._oldGrid = tempGrid;
  game.updateState();
  ASSERT_EQ(3, game._livingCells);
  ASSERT_FALSE((*game._newGrid)[3][4]);
  ASSERT_FALSE((*game._newGrid)[3][5]);
  ASSERT_FALSE((*game._newGrid)[3][6]);
  ASSERT_TRUE((*game._newGrid)[4][4]);
  ASSERT_TRUE((*game._newGrid)[4][5]);
  ASSERT_TRUE((*game._newGrid)[4][6]);
  ASSERT_FALSE((*game._newGrid)[5][4]);
  ASSERT_FALSE((*game._newGrid)[5][5]);
  ASSERT_FALSE((*game._newGrid)[5][6]);
}
