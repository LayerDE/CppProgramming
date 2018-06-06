// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef BALL_H_
#define BALL_H_

// Position and radii.
extern int x;
extern int y;
extern int rx;
extern int ry;
extern float fX, fY, fSpeedX, fSpeedY, fAccelY;
// Initialize screen and global variables.
void initTerminal();


// Draw the ball.
void drawBall();
// Overloading with task 1
void drawBall(bool);

// task 2
float moveBall(int key);

#endif  // BALL_H_
