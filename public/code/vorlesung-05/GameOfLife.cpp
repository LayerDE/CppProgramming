// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdio.h>
#include "./GameOfLife.h"

// ____________________________________________________________________________
int GameOfLife::_numObjects = 0;

// ____________________________________________________________________________
GameOfLife::GameOfLife() {
  _numObjects++;
  printf("Hello, I am Object #%d\n", _numObjects);
}

// ____________________________________________________________________________
GameOfLife::GameOfLife(int x) {
  printf("Hello, I was called with argument %d\n", x);
}

// ____________________________________________________________________________
GameOfLife::~GameOfLife() {
  printf("Bye bye\n");
}

// ____________________________________________________________________________
void GameOfLife::updateState() {
  // For demonstration purposes, just update the state of the middle cell. Note:
  // 1 = alive, 0 = dead (sleeping).
  bool state = _state[1][1];
  int numAlive = -state;
  for (int x = 0; x < 3; x++) {
    for (int y = 0; y < 3; y++) {
      numAlive += _state[x][y];
    }
  }
  if (state == 1 && (numAlive < 2 || numAlive > 3)) {
    state = 0;
  }
  if (state == 0 && numAlive == 3) {
    state = 1;
  }
  _state[1][1] = state;

  // printf("%p\n", static_cast<void*>(this));
}
