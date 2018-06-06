// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#include <gtest/gtest.h>
#include "./GameOfLifePrefab.h"

// Size of the grid.
const int MAX_GRID_SIZE = 1000;

class GameOfLife {
 public:
  // Constructor, initializes grids.
  GameOfLife();

  // Destructor doing cleanup.
  ~GameOfLife();

  // Initialize the game
  void initializeGame();

  // The game of life itseld.
  void play();

 private:
  // Grids and pointers.
  bool _grid1[MAX_GRID_SIZE][MAX_GRID_SIZE];
  bool _grid2[MAX_GRID_SIZE][MAX_GRID_SIZE];
  bool (*_oldGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE];
  bool (*_newGrid)[MAX_GRID_SIZE][MAX_GRID_SIZE];

  // Last coordinate clicked inside grid.
  int _lastClickedX;
  int _lastClickedY;

  // Display size
  int _xSize;
  int _ySize;

  // Bounding box of displayed region.
  int _drawMinX;
  int _drawMaxX;
  int _drawMinY;
  int _drawMaxY;

  // State
  bool _running;
  int _steps;
  int _livingCells;

  // Handle key and mouse presses. Change the new grid.
  int processUserInput(int key);
  FRIEND_TEST(GameOfLife, processUserInputEsc);
  FRIEND_TEST(GameOfLife, processUserInputSpace);
  FRIEND_TEST(GameOfLife, processUserInputSmallS);
  FRIEND_TEST(GameOfLife, processUserInputSmallG);
  FRIEND_TEST(GameOfLife, processUserInputBigG);
  FRIEND_TEST(GameOfLife, processUserInputSmallR);
  FRIEND_TEST(GameOfLife, processUserInputSmallC);

  // Places a given prefab at the coordinates.
  void insertPrefab(int x, int y, GameOfLifePrefab prefab);
  FRIEND_TEST(GameOfLife, insertPrefab0);
  FRIEND_TEST(GameOfLife, insertPrefab1);

  // Calculate the next state and write it into new grid.
  void updateState();
  FRIEND_TEST(GameOfLife, updateStateEmptyGrid);
  FRIEND_TEST(GameOfLife, updateStateStaticObject);
  FRIEND_TEST(GameOfLife, updateStateP2Blinker);

  // Count the number of alive cells around given coordinates in the old grid.
  int aliveNeighbours(int x, int y);
  FRIEND_TEST(GameOfLife, aliveNeighboursSingle);
  FRIEND_TEST(GameOfLife, aliveNeighboursMultiple);

  // Draw the new grid using ncurses.
  void showState();
};

#endif  // GAMEOFLIFE_H_
