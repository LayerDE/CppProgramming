// Copyright 2018, Victor Maier

#ifndef STRING_H_
#define STRING_H_
#include <gtest/gtest.h>
// A very simple string class, which you can and should use as starting point
// for Ü6.
class String {
 private:
  static unsigned char char2dez(char c);
  String(char* s, int length);
  // Keep track of the number of objects.
  static int _numObjects;
  // The contents of the string. We use a null-terminated C-style string, so
  // that we can pass on _contents to C-style functions like printf("%s", ...).
  char* _contents;
  // The length of the string. We keep track of this explicitly, so that we can
  // answer length queries in constant time.
  int _length;
  // Id (for demonstration purposes).
  int _id;

 public:
  FRIEND_TEST(StringTest, constructor);
  FRIEND_TEST(StringTest, copyConstructor);
  FRIEND_TEST(StringTest, set);
  FRIEND_TEST(StringTest, count);
  FRIEND_TEST(StringTest, toFloat);
  FRIEND_TEST(StringTest, split);
  FRIEND_TEST(StringTest, splitTooManyDelimiters);
  FRIEND_TEST(StringTest, splitTooFewDelimiters);
  FRIEND_TEST(StringTest, splitNoDelimiter);

  // Default constructor.
  String();

  // Copy constructor.
  String(const String& s);

  // Destructor.
  ~String();


  // Set to given C-style string.
  void set(const char* s);


  int count(char);

  float toFloat();

  void split(char, int, String[]);
};

#endif  // STRING_H_
