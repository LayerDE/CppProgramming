// Copyright 2018
// Author: LayerDE.

#ifndef WIKIDATA_H_
#define WIKIDATA_H_

#include <string>
#include <vector>
#include "./Entity.h"

class Wikidata {
 private:
 public:
  std::vector<Entity*> _entities;
  void readFile(std::string);
  std::vector<std::string> search(std::string substr) {
    std::vector<std::string> tmp;
    for (Entity* e : _entities)
      if (e->checkString(substr)) tmp.push_back(e->toString());
    return tmp;
  }
  ~Wikidata() {
    for (auto& e : _entities)
      delete e;
  }
};
#endif  // WIKIDATA_H_
