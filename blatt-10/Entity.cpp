// Copyright 2018
// Author: LayerDE.

#include <algorithm>
#include <string>
#include <vector>

#include "./Entity.h"



std::string Entity::toString() {
  return name;
}

Entity::Entity(std::string hName) {
  name = hName;
}
Entity::~Entity() {  // for future development
}


std::string* Entity::UpperName() {
  std::string* tmp = new std::string(name);
  std::transform(name.begin(), name.end(), tmp->begin(), ::toupper);
  return tmp;
}


bool Entity::checkString(std::string substr) {
  std::transform(substr.begin(), substr.end(), substr.begin(), ::toupper);
  std::string* tmp = UpperName();
  bool tmp2 = tmp->find(substr) != std::string::npos;
  delete tmp;
  return tmp2;
}
std::string Entity::getName() {
  return name;
}

Person::Person(std::string hName) : Entity(hName) {  // for future development
}

Person::~Person() {  // for future development
}

Film::Film(std::string hName) : Entity(hName) {  // for future development
}

Film::~Film() {  // for future development
}

void Entity::addTriple(std::vector<std::string> tmp) {
  return;
}

std::string Person::toString() {
  return name + ((placeOfBirth.length() > 0) ?
    (" place of birth: " + placeOfBirth) : "");
}

void Person::addTriple(std::vector<std::string> inval) {
  if (inval.size() != 3)
    return;
  if (!inval[1].compare("place of birth"))
    placeOfBirth = inval[2];
}

std::string Film::toString() {
  std::string tmp = name;
  if (actors.size() > 0) {
    tmp += " cast member: ";
    for (uint i = 0; i < actors.size()-1; i++)
      tmp += actors[i]+", ";
    tmp += actors[actors.size()-1];
  }
  return tmp;
}

void Film::addTriple(std::vector<std::string> inval) {
  if (inval.size() != 3)
    return;
  if (!inval[1].compare("cast member"))
    actors.push_back(inval[2]);
}
