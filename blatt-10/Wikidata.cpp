// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include "./Wikidata.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "./Entity.h"

// ____________________________________________________________________________
void Wikidata::readFile(std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }

  // Triples always consist of three parts, preallocate space in vector.
  std::string line;
  std::vector<std::string> triple;
  triple.resize(3);

  // Since we read a new file, clear previous data.
  for (auto& e : _entities) {
    delete e;
  }
  _entities.clear();

  Entity* entity = nullptr;
  while (true) {
    std::getline(file, line);
    if (file.eof()) { break; }

    // Parse triple.
    size_t pos1 = line.find("\t");
    size_t pos2 = line.find("\t", pos1 + 1);
    if (pos1 == std::string::npos || pos2 == std::string::npos) { continue; }
    triple[0] = line.substr(0, pos1);
    triple[1] = line.substr(pos1 + 1, pos2 - pos1 - 1);
    triple[2] = line.substr(pos2 + 1);

    // Generate new entity if subject changed or no current entity.
    if (entity == nullptr || entity->getName() != triple[0]) {
      // Store old entity if valid.
      if (entity != nullptr) {
        _entities.push_back(entity);
        entity = nullptr;
      }
      // Decide which kind of entity to generate.
      if (triple[2] == "human") {
        entity = new Person(triple[0]);
      } else if (triple[2] == "film") {
        entity = new Film(triple[0]);
      } else {
        entity = new Entity(triple[0]);
      }
    }
    // Store triple if entity is valid.
    if (entity == nullptr) {
      continue;
    }
    entity->addTriple(triple);
  }
  // Store last valid entity.
  if (entity != nullptr) { _entities.push_back(entity); }
}
