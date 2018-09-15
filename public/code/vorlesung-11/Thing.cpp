// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <string>
#include <iostream>
#include "./Thing.h"

// ___________________________________________________________________________
std::string Thing::toString() const {
  return std::string("THING");
}

// _____________________________________________________________________________
IntegerThing::IntegerThing(int value) {
  _value = value;
}

// _____________________________________________________________________________
IntegerThing::~IntegerThing() {
  std::cout << "Destructor of IntegerThing" << std::endl;
}

// _____________________________________________________________________________
std::string IntegerThing::toString() const {
  return std::to_string(_value);
}

// _____________________________________________________________________________
StringThing::StringThing(const char* contents) {
  _contents = contents;
}

// _____________________________________________________________________________
StringThing::~StringThing() {
  std::cout << "Destructor of StringThing" << std::endl;
}

// _____________________________________________________________________________
std::string StringThing::toString() const {
  return _contents;
}

// _____________________________________________________________________________
std::string FinalThing::toString() const {
  return "Final!";
}

// _____________________________________________________________________________
std::string SemiFinalThing::toString() const {
  return "SemiFinal!";
}

// ___________________________________________________________________________
double SemiFinalThing::multiply(double x, double y) const {
  return x * y;
}
