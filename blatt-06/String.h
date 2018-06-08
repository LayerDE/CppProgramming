// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef STRING_H_
#define STRING_H_

// A very simple string class, which you can and should use as starting point
// for Ü6.
class String {
 private:
  String(char* s, int length);

 public:
  // Default constructor.
  String();

  // Copy constructor.
  String(const String& s);

  // Destructor.
  ~String();

  // Keep track of the number of objects.
  static int _numObjects;

  // Set to given C-style string.
  void set(const char* s);


  int count(char);

  float toFloat();

  void split(char, int, String[]);
  // The contents of the string. We use a null-terminated C-style string, so
  // that we can pass on _contents to C-style functions like printf("%s", ...).
  char* _contents;

  // The length of the string. We keep track of this explicitly, so that we can
  // answer length queries in constant time.
  int _length;

  // Id (for demonstration purposes).
  int _id;
};

#endif  // STRING_H_
