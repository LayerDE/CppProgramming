// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
#ifndef GAMEFUNCTIONS_H_
#define GAMEFUNCTIONS_H_
#include "./Config.h"
#define EVENT_NONE 0
#define EVENT_EXIT -1
#define EVENT_RUN 1
#define EVENT_STEPS 2
#define EVENT_COLOR 3
extern bool _cells[2][MAX_GRID_SIZE][MAX_GRID_SIZE];
extern bool (*currentCellPointer)[200];
extern bool (*oldCellPointer)[200];
extern int round;
void initializeGame();
void updateState();
int aliveNeighbors(int x, int y);
int processUserInput(int key);
#endif  // GAMEFUNCTIONS_H_
