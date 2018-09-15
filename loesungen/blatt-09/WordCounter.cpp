// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Johanna Götz <johanna.goetz@uranus.uni-freiburg.de>.

#include <getopt.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include "./WordCounter.h"

// _____________________________________________________________________________
void WordCounter::printUsageAndExit() const {
  std::cerr << "Usage: ./WordCounterMain <filename>\n";
  std::cerr << "Available options:\n";
  std::cerr << "--length <int> : The minimum length a word has to have.\n";
  std::cerr << " (default: 10)\n";
  std::cerr << "--top-k <int> : \n";
  std::cerr << "The number of most common words to print.\n";
  std::cerr << " (default: 15)" << std::endl;
  exit(1);
}

// _____________________________________________________________________________
void WordCounter::parseCommandLineArguments(int argc, char** argv) {
  struct option options[] = {
    {"length", 1, NULL, 'l'},
    {"top-k", 1, NULL, 'k'},
    {NULL, 0, NULL, 0}
  };
  optind = 1;

  // Default values
  _inputFileName = "";
  _minLength = 10;
  _topK = 15;

  while (true) {
    char c = getopt_long(argc, argv, "l:k:", options, NULL);
    if (c == -1) { break; }
    switch (c) {
      case 'l':
        _minLength = atoi(optarg);
        break;
      case 'k':
        _topK = atoi(optarg);
        break;
      case '?':
      default:
        printUsageAndExit();
    }
  }

  // input file is required argument.
  if (optind + 1 != argc) {
    printUsageAndExit();
  }
  _inputFileName = argv[optind];
}

// _____________________________________________________________________________
void WordCounter::readFile(const std::string& filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(1);
  }

  _wordCounts.clear();
  std::string line;
  std::vector<std::string> words;
  std::string word;
  while (true) {
    std::getline(file, line);
    if (file.eof()) {
      break;
    }
    for (size_t i = 0; i < line.length(); i++) {
      char c = tolower(line[i]);
      if ('a' <= c && c <= 'z') {
        word.push_back(c);
      } else {
        if (word.length() > 0) {
          words.push_back(word);
        }
        word = "";
      }
    }
    if (word.length() > 0) {
      words.push_back(word);
    }
    word = "";
    updateWordCounts(words);
    words.clear();
  }
}

// _____________________________________________________________________________
size_t WordCounter::getNumWords() const {
  return _wordCounts.size();
}

// _____________________________________________________________________________
size_t WordCounter::getWordCount(const std::string& word) const {
  return _wordCounts.count(word) > 0 ? _wordCounts.at(word) : 0;
}

// _____________________________________________________________________________
void WordCounter::updateWordCounts(const std::vector<std::string>& words) {
  for (auto& word : words) {
    if (word.length() >= _minLength) {
      _wordCounts[word] = _wordCounts[word] + 1;
    }
  }
}

// _____________________________________________________________________________
std::vector<std::pair<std::string, size_t>>
WordCounter::computeFrequentWords() const {
  // Create a new vector that is exactly as large as k
  std::vector<std::pair<std::string, size_t>> result;
  result.resize(std::min(_topK, _wordCounts.size()));

  // Do a partial sort because only the top k is needed
  std::partial_sort_copy(_wordCounts.begin(), _wordCounts.end(),
                         result.begin(), result.end(), [](
        const std::pair<std::string, size_t> &left,
        const std::pair<std::string, size_t> &right) {
    return left.second > right.second;
  });
  return result;
}

// _____________________________________________________________________________
void WordCounter::process() {
  readFile(_inputFileName);
  size_t index = 0;
  for (auto& pair : computeFrequentWords()) {
    std::cout << ++index << " " << pair.first.c_str();
    std::cout << " (" << pair.second << ")" << std::endl;
  }
}
