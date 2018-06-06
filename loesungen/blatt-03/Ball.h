// Copyright 2018, University of Freiburg
// Chair of Algorithms and Data Structures
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef BALL_H_
#define BALL_H_

// Position of the ball and dimensions of ellipse.
extern float x;
extern float y;
extern float rx;
extern float ry;
extern float vx;
extern float vy;
extern float ax;
extern float ay;

// Size of drawing area, needed for tests.
extern int maxX;
extern int maxY;

// Initialize the terminal for use with ncurses commands.
void initTerminal();

// Draw the ball (show == true: draw in black, show == true: draw in white).
void drawBall(bool show);

// Change the velocity and acceleration of the ball according to the given arrow
// key (LEFT/RIGHT: change horizontal velocity, UP/DOWN: change vertical
// acceleration). Always moves the ball by a unit vector and returns the length
// of the vector (the sleep time between two draw should be inverse proportional
// to that length which gives the illusion of velocity). When ESC was pressed,
// return a negative velocity.
float moveBall(int key);

#endif  // BALL_H_
