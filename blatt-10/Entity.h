// Copyright 2018
// Author: LayerDE.

#ifndef ENTITY_H_
#define ENTITY_H_
#include <string>
#include <vector>

class Entity {
 private:
  std::string* UpperName();
 protected:
  std::string name;
 public:
  std::string getName();
  explicit Entity(std::string);
  ~Entity();
  virtual std::string toString();
  virtual void addTriple(std::vector<std::string>);
  bool checkString(std::string);
};

class Person : public Entity {
 private:
 protected:
  std::string placeOfBirth;
 public:
  explicit Person(std::string);
  ~Person();
  std::string toString();
  void addTriple(std::vector<std::string>);
};

class Film : public Entity {
 private:
 protected:
  std::vector<std::string> actors;
 public:
  explicit Film(std::string);
  ~Film();
  std::string toString();
  void addTriple(std::vector<std::string>);
};
#endif  // ENTITY_H_
