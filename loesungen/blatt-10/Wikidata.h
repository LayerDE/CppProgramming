// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef WIKIDATA_H_
#define WIKIDATA_H_

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "./Entity.h"

class Wikidata {
 public:
  ~Wikidata();
  // Read a given file.
  void readFile(std::string filename);
  FRIEND_TEST(WikidataTest, readFileAndSearch);

  // Search in stored entities.
  std::vector<std::string> search(std::string needle);

 protected:
  // Storage for all entitie classes.
  std::vector<Entity*> _entities;
};

#endif  // WIKIDATA_H_
