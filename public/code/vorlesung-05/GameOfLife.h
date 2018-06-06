// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef GAMEOFLIFE_H_
#define GAMEOFLIFE_H_

#include <gtest/gtest.h>

// A class to play the game of life. Partial contents only, for demonstration
// purposes.
class GameOfLife {
 private:
  // The current state (for demonstration purposes only 3 x 3).
  bool _state[3][3];

  // Number of objects of this class.
  static int _numObjects;

 public:
  // Constructors.
  GameOfLife();
  explicit GameOfLife(int x);

  // Destructor.
  ~GameOfLife();

  // Method for updating the current state according to the rules.
  void updateState();
  FRIEND_TEST(GameOfLifeTest, updateState);

  void someOtherFunctionDieIrgendwasTut();
};

#endif  // GAMEOFLIFE_H_
