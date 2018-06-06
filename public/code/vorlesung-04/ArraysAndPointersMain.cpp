// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdio.h>

// Showing some things about arrays and pointers.
int main(int argc, char** argv) {
  // int x = 42;
  // printf("%d\n", x);
  // printf("%zu\n", sizeof(x));
  // printf("%p\n", &x);

  // int* p = &x;
  // printf("%p\n", p);
  // printf("%zu\n", sizeof(p));

  // p = p + 1;
  // printf("%p\n", p);
  // printf("%zu\n", sizeof(p));

  // int y = 137;
  // int a[3] = { 1, 2, 3 };
  // printf("%d\n", y);
  // printf("%d\n", a[-1]);
  // a[-1] = 138;
  // printf("%d\n", y);

  // printf("%d\n", a[0]);
  // printf("%d\n", a[1]);
  // printf("%d\n", a[2]);
  // printf("%zu\n", sizeof(a));
  // printf("%p\n", a);
  // int* p = a;
  // printf("%p\n", p);
  // printf("%d\n", *p);
  // printf("%d\n", *(p + 1));
  // printf("%d\n", *(p + 2));
  // printf("%d\n", p[0]);
  // printf("%d\n", p[1]);
  // printf("%d\n", p[2]);
  // printf("\n");
  // p[10] = 42;
  // printf("%d\n", p[10]);

  // int b[4][2] = { { 10, 11}, { 20, 21 }, { 30, 31}, { 40, 41} };
  // // int b[4][2] = { 10, 11, 20, 21, 30, 31, 40, 41 };
  // printf("%d\n", b[3][1]);  // Element at position 3 * 2 + 1 = 7.
  // // printf("%d\n", b[7]);     // Element at position 7.
  // printf("%zu\n", sizeof(b));
  // printf("%p\n", b);
  // // int** q = b;  // Does NOT compile.
  // int (*q)[2] = b;
  // printf("%p\n", q);
  // printf("%d\n", q[3][1]);  // Element at position 3 * 2 + 1 = 7.

  // int* p = &b[0][0];  // Same as &(b[0][0]).
  // printf("%p\n", p);
  // printf("%d\n", p[7]);

  char s[5] = { 'D', 'o', 'o', 'f' };
  // const char* s = "Doof";
  // printf("%c\n", s[0]);
  // printf("%c\n", s[1]);
  // printf("%c\n", s[2]);
  // printf("%c\n", s[3]);
  printf("%d\n", s[0]);
  printf("%d\n", s[1]);
  printf("%d\n", s[2]);
  printf("%d\n", s[3]);
  printf("%d\n", s[4]);
}
