// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef THING_H_
#define THING_H_

#include <string>

class Thing {
 public:
  virtual std::string toString();  // = 0;
  virtual ~Thing() {}
};

class IntegerThing : public Thing {
 public:
  explicit IntegerThing(int value);
  ~IntegerThing();
  std::string toString();
 private:
  int _value;
};

class StringThing : public Thing {
 public:
  explicit StringThing(const char* contents);
  ~StringThing();
  std::string toString();
 private:
  std::string _contents;
};

#endif  // THING_H_
