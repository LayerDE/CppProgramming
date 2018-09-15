// Copyright 2018, LayerDE
// Author: Victor Maier

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <utility>
#include "./WordCounter.h"

WordCounter::WordCounter() {
  _minLength = 10;
  _topK = 15;
}

WordCounter::~WordCounter() {
}

void WordCounter::updateWordCounts(std::vector<std::string> words) {
  for (std::string word : words)
    if (word.length() >= _minLength) {
      if (wordCount.count(word))
        wordCount[word]++;
      else
        wordCount[word] = 1;
    }
}

std::vector<std::pair<std::string, std::size_t> >
 WordCounter::computeFrequentWords() {
  return std::vector<std::pair<std::string, std::size_t> >();
}
// for (auto& x: mymap) {
//  std::cout << x.first << ": " << x.second << std::endl;
//}


uint WordCounter::getNumWords() {
  return wordCount.size();
}

uint WordCounter::getWordCount(std::string word) {
  if (wordCount.count(word))
    return wordCount[word];
  else
    return 0;
}
void WordCounter::readFile(std::string path) {
  std::ifstream input(path);
  std::string line;
  std::vector<std::string> words;
  words.push_back(std::string());
  if (!input) {
    std::cerr << "Error opening file: ." << path;
    exit(-1);
  }
  while (getline(input, line)) {
    for (int x = 0, y = 0; x < line.length(); x++) {
      if ('a' <= line[x] && line[x] <= 'z') {
        words[y] += line[x];
      }  else if ('A' <= line[x] && line[x] <= 'Z') {
        words[y] += (line[x] + 32);
      } else if (words[y].length() != 0) {
          y++;
          words.push_back(std::string());
      }
    }
    updateWordCounts(words);
    words.clear();
  }
}
