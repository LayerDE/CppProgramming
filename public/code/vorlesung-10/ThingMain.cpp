// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <iostream>
#include <vector>
#include "./Thing.h"

// Main function.
int main(int argc, char** argv) {
  std::cout << std::endl;
  std::cout << "sizeof(Thing) = " << sizeof(Thing) << std::endl;
  std::cout << "sizeof(IntegerThing) = " << sizeof(IntegerThing) << std::endl;
  std::cout << "sizeof(StringThing) = " << sizeof(StringThing) << std::endl;

  std::vector<Thing*> things;

  Thing* thing1 = new Thing();
  Thing* thing2 = new IntegerThing(42);
  Thing* thing3 = new StringThing("doof");

  std::cout << std::endl;
  std::cout << thing1->toString() << std::endl;
  std::cout << thing2->toString() << std::endl;
  std::cout << thing3->toString() << std::endl;

  things.push_back(thing1);
  things.push_back(thing2);
  things.push_back(thing3);

  std::cout << std::endl;
  for (auto thing : things) {
    std::cout << thing->toString() << std::endl;
  }
  std::cout << std::endl;

  delete thing1;
  delete thing2;
  delete thing3;
}
