// Copyright 2018, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include <ncurses.h>
#include "./Ball.h"

TEST(Ball, moveBallESC) {
  ASSERT_EQ(-1, moveBall(27));
}

TEST(Ball, moveBallArrowUp) {
  x = 5;
  y = 5;
  vx = 0;
  vy = 0;
  ax = 0;
  ay = 1;
  maxX = 11;
  maxY = 11;
  moveBall(KEY_UP);
  ASSERT_FLOAT_EQ(0.99, ay);
}

TEST(Ball, moveBallArrowDown) {
  x = 5;
  y = 5;
  vx = 0;
  vy = 0;
  ax = 0;
  ay = 1;
  maxX = 11;
  maxY = 11;
  moveBall(KEY_DOWN);
  ASSERT_FLOAT_EQ(1.01, ay);
}

TEST(Ball, moveBallArrowLeft) {
  x = 5;
  y = 5;
  vx = 0;
  vy = 0;
  ax = 0;
  ay = 1;
  maxX = 11;
  maxY = 11;
  moveBall(KEY_LEFT);
  ASSERT_FLOAT_EQ(-0.01, vx);
}

TEST(Ball, moveBallArrowRight) {
  x = 5;
  y = 5;
  vx = 0;
  vy = 0;
  ax = 0;
  ay = 1;
  maxX = 11;
  maxY = 11;
  moveBall(KEY_RIGHT);
  ASSERT_FLOAT_EQ(0.01, vx);
}

TEST(Ball, moveBallReflectionTop) {
  x = 5;
  y = 0;
  vx = 1;
  vy = -1;
  ax = 0;
  ay = 0;
  maxX = 11;
  maxY = 11;
  moveBall(0);
  ASSERT_FLOAT_EQ(0.9, vx);
  ASSERT_FLOAT_EQ(0.9, vy);
}

TEST(Ball, moveBallReflectionBottom) {
  x = 5;
  y = 11;
  vx = 1;
  vy = 1;
  ax = 0;
  ay = 0;
  maxX = 11;
  maxY = 11;
  moveBall(0);
  ASSERT_FLOAT_EQ(0.9, vx);
  ASSERT_FLOAT_EQ(-0.9, vy);
}

TEST(Ball, moveBallReflectionLeft) {
  x = 0;
  y = 5;
  vx = -1;
  vy = 1;
  ax = 0;
  ay = 0;
  maxX = 11;
  maxY = 11;
  moveBall(0);
  ASSERT_FLOAT_EQ(0.9, vx);
  ASSERT_FLOAT_EQ(0.9, vy);
}

TEST(Ball, moveBallReflectionRight) {
  x = 11;
  y = 5;
  vx = 1;
  vy = 1;
  ax = 0;
  ay = 0;
  maxX = 11;
  maxY = 11;
  moveBall(0);
  ASSERT_FLOAT_EQ(-0.9, vx);
  ASSERT_FLOAT_EQ(0.9, vy);
}

TEST(Ball, moveBallGenericXAxis) {
  x = 5;
  y = 5;
  vx = 1;
  vy = 0;
  ax = 0.1;
  ay = 0;
  maxX = 11;
  maxY = 11;
  moveBall(0);
  ASSERT_FLOAT_EQ(6, x);
  ASSERT_FLOAT_EQ(5, y);
  ASSERT_FLOAT_EQ(1.1, vx);
  ASSERT_FLOAT_EQ(0, vy);
}

TEST(Ball, moveBallGenericYAxis) {
  x = 5;
  y = 5;
  vx = 0;
  vy = 1;
  ax = 0;
  ay = 0.1;
  maxX = 11;
  maxY = 11;
  moveBall(0);
  ASSERT_FLOAT_EQ(5, x);
  ASSERT_FLOAT_EQ(6, y);
  ASSERT_FLOAT_EQ(0, vx);
  ASSERT_FLOAT_EQ(1.1, vy);
}
