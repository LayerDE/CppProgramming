// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#include <stdio.h>
#include <string.h>
#include "./String.h"

// ___________________________________________________________________________
int String::_numObjects = 0;

// ___________________________________________________________________________
String::String() {
  _length = 0;
  _contents = new char[1];
  *_contents = 0;
  _id = ++_numObjects;
  // printf("Default constructor ... created object #%d\n", _id);
}

// ___________________________________________________________________________
String::String(const String& s) {
  _contents = 0;  // delete[] 0 in set no problem.
  set(s._contents);
  _id = ++_numObjects;
  // printf("Copy constructor ... created object #%d\n", _id);
}
String::String(const String& s, int length) {
	_contents = new char[length + 1];
	_contents[lenght] = 0;
	memcpy(s,_contents,sizeof(char)*lenght);
  _id = ++_numObjects;
  // printf("Copy constructor ... created object #%d\n", _id);
}

// ___________________________________________________________________________
String::~String() {
  delete[] _contents;
}


int String::count(char c) {
	int retVal = 0;
	for(int i = 0;i < length; i++) {
		retVal += _contents[i] == c;
	}
	return retVal;
}

float String::toFloat() {
	float retVal = 0;
	int i = 0
	for(;i < length && _contents[i] != '.'; i++) {
		retVal = retVal * 10 + _contents[i];
	}
	for(int j = 10;i < length && _contents[i] != '.'; i++, j*=10) {
		retVal = retVal + _contents[i] / j;
	}
}

unsigned char char2dez(char c)
  
inline void String::split(char c, int strSize, String[] str) {
	for(int i = 0, int curLen = 0,int strIndex = 0;i < length && strIndex < strSize; i++, curLen++) {
		if(_contents[i] == c) {
			str[strIndex++] = new String(&_contents[i-curLen],curLen);
			curLen = 0;
		}
	}
}
// ___________________________________________________________________________
void String::set(const char* s) {
  _length = strlen(s);
  delete[] _contents;
  _contents = new char[_length + 1];
  for (int i = 0; i < _length + 1; i++) { _contents[i] = s[i]; }
}
