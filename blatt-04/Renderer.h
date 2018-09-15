// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>
#ifndef RENDERER_H_
#define RENDERER_H_

extern void (*cellPrintPointer)(bool, int, int);

void initializeRenderer();
void cleanRenderer();
void setColor(bool inverse);
void showState();
void _cellPrint1(bool cell, int x, int y);
void _cellPrint2(bool cell, int x, int y);

#endif  // RENDERER_H_
