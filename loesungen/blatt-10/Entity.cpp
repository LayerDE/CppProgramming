// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include "./Entity.h"
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

// ____________________________________________________________________________
Entity::Entity(std::string name) {
  _name = name;
  _searchName = name;
  std::transform(name.begin(), name.end(), _searchName.begin(), ::tolower);
}

// ____________________________________________________________________________
void Entity::addTriple(const std::vector<std::string> &data) {
  _data[data[1]].push_back(data[2]);
}

// ____________________________________________________________________________
std::string Entity::getName() const { return _name; }

// ____________________________________________________________________________
std::string Entity::getSearchName() const { return _searchName; }

// ____________________________________________________________________________
std::string Entity::toString() const { return getName(); }

// ____________________________________________________________________________
std::string Entity::toString(const std::vector<std::string>& properties) const {
  std::ostringstream oss;
  oss << Entity::getName();
  for (auto& prop : properties) {
    if (_data.count(prop) > 0) {
      oss << " " << prop << ":";
      for (size_t i = 0; i < _data.at(prop).size(); ++i) {
        oss << (i > 0 ? ", " : " ") << _data.at(prop)[i];
      }
    }
  }
  return oss.str();
}

// ____________________________________________________________________________
std::string Person::toString() const {
  std::vector<std::string> properties;
  properties.push_back("place of birth");
  return Entity::toString(properties);
}

// ____________________________________________________________________________
std::string Film::toString() const {
  std::vector<std::string> properties;
  properties.push_back("cast member");
  return Entity::toString(properties);
}
