// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <vector>
#include <unordered_map>

class Entity {
 public:
  // Create an entity, stores name and searchable name.
  explicit Entity(std::string name);
  virtual ~Entity() {}

  // Adds a vector-triple to the internal storage. Data is used by toString
  void addTriple(const std::vector<std::string>& triple);

  // Get normal name.
  std::string getName() const;

  // Get searchable name.
  std::string getSearchName() const;

  // To string, specialized by subclasses.
  virtual std::string toString() const;

 protected:
  // Helper adding addition property values to the string.
  std::string toString(const std::vector<std::string>& properties) const;
  // Store normal name.
  std::string _name;
  // Store searchable name.
  std::string _searchName;
  // Store all triples.
  std::unordered_map<std::string, std::vector<std::string>> _data;
};

class Person : public Entity {
 public:
  // Stores a person, calls parent constructor.
  explicit Person(std::string name) : Entity(name) {}
  virtual ~Person() {}
  std::string toString() const;
};

class Film : public Entity {
 public:
  // Stores a film, calls parent constructor.
  explicit Film(std::string name) : Entity(name) {}
  virtual ~Film() {}
  std::string toString() const;
};

#endif  // ENTITY_H_
