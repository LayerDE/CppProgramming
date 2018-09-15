// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Johanna Götz <johanna.goetz@uranus.uni-freiburg.de>.

#ifndef WORDCOUNTER_H_
#define WORDCOUNTER_H_

#include <gtest/gtest.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

class WordCounter {
 public:
  // Print usage info
  void printUsageAndExit() const;

  // Parse the command line arguments
  void parseCommandLineArguments(int argc, char** argv);

  // Read file with given name.
  void readFile(const std::string& fileName);
  FRIEND_TEST(WordCounter, readFile);
  FRIEND_TEST(WordCounter, readInvalidFile);

  // Update counts per word (wordCounts below) for given string of words.
  void updateWordCounts(const std::vector<std::string>& words);
  FRIEND_TEST(WordCounter, updateWordCounts);

  // Get the number of words
  size_t getNumWords() const;

  // Get the number of occurences for a given word
  size_t getWordCount(const std::string& word) const;
  FRIEND_TEST(WordCounter, getSizeAndGetWordCount);

  // Sort words by counts, and return the k words with the largest counts.
  std::vector<std::pair<std::string, size_t>> computeFrequentWords() const;
  FRIEND_TEST(WordCounter, computeFrequentWords);

  // Process
  void process();

 private:
  // Word counts.
  std::unordered_map<std::string, size_t> _wordCounts;
  // The name of the input file
  std::string _inputFileName;
  // The minimum word length
  size_t _minLength = 10;
  // The number of top results
  size_t _topK = 15;
};

#endif  // WORDCOUNTER_H_
