// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef GAMEOFLIFEPREFAB_H_
#define GAMEOFLIFEPREFAB_H_

#include <gtest/gtest.h>

const int MAX_PREFAB_SIZE = 36;

class GameOfLifePrefab {
 public:
  GameOfLifePrefab();

  // Select the specific prefab.
  void select(int kind);

  // Returns number of cells for the currently selected prefab.
  int getNumberOfCells();
  FRIEND_TEST(GameOfLifePrefab, getNumberOfCells);

  // Returns the x-coordinate of the i-th cell.
  int getRelativeX(int i);

  // Returns the y-coordinate of the i-th cell.
  int getRelativeY(int i);

 private:
  // Length of the current prefab.
  int _length;

  // Pointer to the currently selected prefab array.
  const int (*_cells)[MAX_PREFAB_SIZE][2];

  // Glider coordinates.
  static const int _glider[MAX_PREFAB_SIZE][2];

  // Factory coordinates.
  static const int _factory[MAX_PREFAB_SIZE][2];
};

#endif  // GAMEOFLIFEPREFAB_H_
