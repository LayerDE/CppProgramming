// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <string.h>
#include "./String.h"

// ____________________________________________________________________________
String::String() {
  _length = 0;
  _contents = new char[1];
  *_contents = 0;
}

// ____________________________________________________________________________
String::String(const String& s) {
  _contents = 0;
  set(s._contents);
}

// ____________________________________________________________________________
String::~String() {
  delete[] _contents;
}

// ____________________________________________________________________________
void String::set(const char* s) {
  delete[] _contents;
  _length = strlen(s);
  _contents = new char[_length + 1];
  for (int i = 0; i <= _length; ++i) { _contents[i] = s[i]; }
}

// ____________________________________________________________________________
int String::count(const char needle) const {
  int result = 0;
  for (int i = 0; i < _length; ++i) { result += (_contents[i] == needle); }
  return result;
}

// ____________________________________________________________________________
void String::split(const char sep, const int maxParts, String result[]) const {
  int matches = 0;
  char* buffer = new char[_length + 1];
  int c = 0;
  for (int j = 0; j <= _length; ++j) { buffer[j] = 0; }

  for (int i = 0; i < _length; ++i) {
    if (_contents[i] == sep && matches < (maxParts - 1)) {
      result[matches++].set(buffer);
      c = 0;
      for (int j = 0; j <= _length; ++j) { buffer[j] = 0; }
      continue;
    }
    buffer[c++] = _contents[i];
  }
  result[matches].set(buffer);
  delete[] buffer;
}

// ____________________________________________________________________________
float String::toFloat() const {
  return atof(_contents);
}
