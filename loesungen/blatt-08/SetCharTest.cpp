// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include "./Set.h"

// _____________________________________________________________________________
TEST(SetCharTest, blackbox) {
  Set<char> set;
  // Empty set
  for (int c = 0; c < 256; ++c) {
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: " << static_cast<char>(c)
      << " dec: "<< c;
  }

  // Insert a
  set.insert('a');
  for (int c = 0; c < 256; ++c) {
    if (c == 'a') { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: " << static_cast<char>(c)
      << " dec: "<< c;
  }
  ASSERT_TRUE(set.lookup('a'));

  // Insert a again -> no change
  set.insert('a');
  for (int c = 0; c < 256; ++c) {
    if (c == 'a') { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: " << static_cast<char>(c)
      << " dec: "<< c;
  }
  ASSERT_TRUE(set.lookup('a'));

  // Insert b
  set.insert('b');
  for (int c = 0; c < 256; ++c) {
    if (c == 'a') { continue; }
    if (c == 'b') { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: " << static_cast<char>(c)
      << " dec: "<< c;
  }
  ASSERT_TRUE(set.lookup('a'));
  ASSERT_TRUE(set.lookup('b'));

  // Insert ue dec: 129
  set.insert('\x81');
  for (int c = 0; c < 256; ++c) {
    if (c == 'a') { continue; }
    if (c == 'b') { continue; }
    if (c == 129) { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: " << static_cast<char>(c)
      << " dec: "<< c;
  }
  ASSERT_TRUE(set.lookup('a'));
  ASSERT_TRUE(set.lookup('b'));
  ASSERT_TRUE(set.lookup('\x81'));

  // Erase a
  set.erase('a');
  for (int c = 0; c < 256; ++c) {
    if (c == 'b') { continue; }
    if (c == 129) { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: " << static_cast<char>(c)
      << " dec: "<< c;
  }
  ASSERT_TRUE(set.lookup('b'));
  ASSERT_TRUE(set.lookup('\x81'));

  // Erase a again -> no change
  set.erase('a');
  for (int c = 0; c < 256; ++c) {
    if (c == 'b') { continue; }
    if (c == 129) { continue; }
    ASSERT_FALSE(set.lookup(c)) << "Failed for char: " << static_cast<char>(c)
      << " dec: "<< c;
  }
  ASSERT_TRUE(set.lookup('b'));
  ASSERT_TRUE(set.lookup('\x81'));
}
