// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <stdio.h>
#include "./GameOfLifePrefab.h"

// ____________________________________________________________________________
const int GameOfLifePrefab::_glider[MAX_PREFAB_SIZE][2] = {
  {1, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2}
};

// ____________________________________________________________________________
const int GameOfLifePrefab::_factory[MAX_PREFAB_SIZE][2] = {
  {24, 0},
  {22, 1}, {24, 1},
  {12, 2}, {13, 2}, {20, 2}, {21, 2}, {34, 2}, {35, 2},
  {11, 3}, {15, 3}, {20, 3}, {21, 3}, {34, 3}, {35, 3},
  {0, 4}, {1, 4}, {10, 4}, {16, 4}, {20, 4}, {21, 4},
  {0, 5}, {1, 5}, {10, 5}, {14, 5}, {16, 5}, {17, 5}, {22, 5}, {24, 5},
  {10, 6}, {16, 6}, {24, 6},
  {11, 7}, {15, 7},
  {12, 8}, {13, 8}
};

// ____________________________________________________________________________
GameOfLifePrefab::GameOfLifePrefab() {
  _length = 0;
  _cells = NULL;
}

// ____________________________________________________________________________
void GameOfLifePrefab::select(int kind) {
  switch (kind) {
    case 0:
      _cells = &GameOfLifePrefab::_glider;
      _length = 5;
      break;
    case 1:
      _cells = &GameOfLifePrefab::_factory;
      _length = 36;
  }
}

// ____________________________________________________________________________
int GameOfLifePrefab::getNumberOfCells() {
  return _length;
}

// ____________________________________________________________________________
int GameOfLifePrefab::getRelativeX(int i) {
  return (*_cells)[i][0];
}

// ____________________________________________________________________________
int GameOfLifePrefab::getRelativeY(int i) {
  return (*_cells)[i][1];
}
