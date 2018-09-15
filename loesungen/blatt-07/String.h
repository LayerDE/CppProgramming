// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef STRING_H_
#define STRING_H_

#include <gtest/gtest.h>

class String {
 public:
  // Default constructor setting basic values.
  String();
  FRIEND_TEST(StringTest, constructor);

  // Copy constructor.
  String(const String& s);
  FRIEND_TEST(StringTest, copyConstructor);

  // Destructor freeing allocated memory.
  ~String();

  // Sets the internal values. Allocates memory to store the character sequence.
  void set(const char* s);
  FRIEND_TEST(StringTest, set);

  // Returns how often a given character is found in the stored sequence.
  int count(const char needle) const;
  FRIEND_TEST(StringTest, count);

  // Converts the internal value into a floating point number.
  float toFloat() const;
  FRIEND_TEST(StringTest, toFloat);

  // Splits the stored sequence on the given delimiter in maximal maxParts new
  // strings which are stored in the given string array.
  void split(const char delimiter, const int maxParts, String result[]) const;
  FRIEND_TEST(StringTest, split);
  FRIEND_TEST(StringTest, splitTooManyDelimiters);
  FRIEND_TEST(StringTest, splitTooFewDelimiters);
  FRIEND_TEST(StringTest, splitNoDelimiter);

 private:
  // Character sequence of the string without trailing 0-byte.
  char* _contents;
  // Length of the character sequence.
  int _length;
};

#endif  // STRING_H_
