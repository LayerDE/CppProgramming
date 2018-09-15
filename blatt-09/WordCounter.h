// Copyright 2018, LayerDE
// Author: Victor Maier

#ifndef WORDCOUNTER_H_
#define WORDCOUNTER_H_
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

class WordCounter{
 private:
  std::unordered_map <std::string, int> wordCount;
 public:
  uint _minLength;
  uint _topK;
  uint getWordCount(std::string);
  uint getNumWords();
  WordCounter();
  ~WordCounter();
  void updateWordCounts(std::vector<std::string>);
  void readFile(std::string);
  std::vector<std::pair<std::string, size_t> > computeFrequentWords();
};
#endif  // WORDCOUNTER_H_
