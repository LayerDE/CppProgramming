// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef THING_H_
#define THING_H_

#include <string>

class Thing {
 public:
  virtual std::string toString() const;  // = 0;
  virtual ~Thing() {}
};

class IntegerThing : public Thing {
 public:
  explicit IntegerThing(int value);
  ~IntegerThing();
  std::string toString() const override;
 private:
  int _value;
};

class StringThing : public Thing {
 public:
  explicit StringThing(const char* contents);
  ~StringThing();
  std::string toString() const override;
 private:
  std::string _contents;
};

class FinalThing final : public Thing {
 public:
  std::string toString() const override;
};

// class OtherThing : public FinalThing {};

class SemiFinalThing : public Thing {
 public:
  std::string toString() const final;
  virtual double multiply(double x, double y) const;
};


class AnotherThing : public SemiFinalThing {
 public:
  // std::string toString() const override;
  double multiply(double x, double y) const override;
};

#endif  // THING_H_
