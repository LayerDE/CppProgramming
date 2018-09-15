// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <gtest/gtest.h>
#include <string>
#include "./Wikidata.h"
#include "./Entity.h"

// ____________________________________________________________________________
TEST(WikidataTest, readInvalidFile) {
  Wikidata wd;
  ::testing::FLAGS_gtest_death_test_style = "threadsafe";
  ASSERT_DEATH(wd.readFile(std::string("InvalidFile")),
               "Error opening file: .*");
}

// ____________________________________________________________________________
TEST(WikidataTest, readFileAndSearch) {
  Wikidata wd;
  ASSERT_EQ(0, wd._entities.size());
  wd.readFile(std::string("WikidataTest.testfile"));
  ASSERT_EQ(9, wd._entities.size());
  wd.readFile(std::string("WikidataTest.testfile"));
  ASSERT_EQ(9, wd._entities.size());

  {
    auto result = wd.search("isNotContainedInFile");
    ASSERT_EQ(0, result.size());
  }
  {
    auto result = wd.search("broken line here");
    ASSERT_EQ(0, result.size());
  }
  {
    auto result = wd.search("E");
    ASSERT_EQ(5, result.size());
    ASSERT_STREQ("Christopher Lee place of birth: Belgravia",
                 result[0].c_str());
    ASSERT_STREQ("Metallica",
                 result[1].c_str());
    ASSERT_STREQ("Iron Maiden",
                 result[2].c_str());
    ASSERT_STREQ("Rhapsody of Fire",
                 result[3].c_str());
    ASSERT_STREQ("Iron Maiden: Flight 666 cast member: Iron Maiden",
                 result[4].c_str());
  }
  {
    auto result = wd.search("eE");
    ASSERT_EQ(1, result.size());
    ASSERT_STREQ("Christopher Lee place of birth: Belgravia",
                 result[0].c_str());
  }
  {
    auto result = wd.search("T");
    ASSERT_EQ(5, result.size());
    ASSERT_STREQ("Christopher Lee place of birth: Belgravia",
                 result[0].c_str());
    ASSERT_STREQ("Metallica",
                 result[1].c_str());
    ASSERT_STREQ("Nightwish",
                 result[2].c_str());
    ASSERT_STREQ("Black Sabbath",
                 result[3].c_str());
    ASSERT_STREQ("Iron Maiden: Flight 666 cast member: Iron Maiden",
                 result[4].c_str());
  }
  {
    auto result = wd.search("ck");
    ASSERT_EQ(2, result.size());
    ASSERT_STREQ("Black Sabbath",
                 result[0].c_str());
    ASSERT_STREQ("Jack Black place of birth: Hermosa Beach",
                 result[1].c_str());
  }
}
