// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdio.h>
#include <string.h>
#include "./String.h"

// ___________________________________________________________________________
int String::_numObjects = 0;

// ___________________________________________________________________________
String::String() {
  _length = 0;
  _contents = new char[1];
  *_contents = 0;
  _id = ++_numObjects;
  // printf("Default constructor ... created object #%d\n", _id);
}

// ___________________________________________________________________________
String::String(const String& s) {
  _contents = 0;  // delete[] 0 in set no problem.
  set(s._contents);
  _id = ++_numObjects;
  // printf("Copy constructor ... created object #%d\n", _id);
}

// ___________________________________________________________________________
String::~String() {
  delete[] _contents;
}

// ___________________________________________________________________________
void String::set(const char* s) {
  _length = strlen(s);
  delete[] _contents;
  _contents = new char[_length + 1];
  for (int i = 0; i < _length + 1; i++) { _contents[i] = s[i]; }
}
