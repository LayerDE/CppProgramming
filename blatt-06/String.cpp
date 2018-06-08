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
String::String(char* s, int length) {
  _contents = new char[length + 1];
  _contents[length] = 0;
  for (int i = 0; i < length + 1; i++) { _contents[i] = s[i]; }
  _length = strlen(_contents);
  _id = ++_numObjects;
  // printf("Copy constructor ... created object #%d\n", _id);
}

// ___________________________________________________________________________
String::~String() {
  delete[] _contents;
}


int String::count(char c) {
  int retVal = 0;
  for (int i = 0; i < _length; i++) {
    retVal += _contents[i] == c;
  }
  return retVal;
}

unsigned char String::char2dez(char c) {
  return c-'0';
}

float String::toFloat() {
  float retVal = 0;
  int i = 0, factor = -1;
  if (_contents[0] == '-')
    i = 1;
  else
    factor = 1;
  for (; i < _length && _contents[i] != '.'; i++) {
    retVal = retVal * 10 + char2dez(_contents[i]);
  }
  i++;
  for (int j = 10; i < _length && _contents[i] != '\n'; i++, j *= 10) {
    retVal += static_cast<float>(char2dez(_contents[i]))
      / static_cast<float>(j);
  }
  return retVal * factor;
}

void String::split(char c, int strSize, String str[]) {
  for (int i = 0, curLen = 0, strIndex = 0; i < _length
    && strIndex < strSize; i++, curLen++) {
    if (_contents[i] == c) {
      str[strIndex++] = *(new String(&_contents[i-curLen], curLen));
      curLen = 0;
    }
  }
}
// ___________________________________________________________________________
void String::set(const char* s) {
  _length = strlen(s);
  delete[] _contents;
  _contents = new char[_length + 1];
  for (int i = 0; i < _length + 1; i++) { _contents[i] = s[i]; }
}
