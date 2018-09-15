// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "./Wikidata.h"

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: ./WikidataMain <filename>" << std::endl;
    exit(1);
  }

  // Data storages
  Wikidata wd;
  std::string needle;

  // Read file
  std::cout << "Reading file ... " << std::flush;
  wd.readFile(argv[1]);
  std::cout << "done." << std::endl;

  while (true) {
    std::cout << "Type query or \033[1mquit\033[0m to exit." << std::endl;
    std::cout << "\033[1m> \033[0m";

    // Parse query
    std::getline(std::cin, needle);
    if (needle == "quit") { break; }

    // Show result
    std::vector<std::string> result = wd.search(needle);
    if (result.size() == 0) {
      std::cout << "Sorry, no results for \033[1m" << needle
        << "\033[0m" << std::endl;
    } else {
      for (size_t i = 0; i < std::min(size_t(10), result.size()); ++i) {
        std::cout << std::setw(2) << (i + 1) << ". " << result[i] << std::endl;
      }
    }
    std::cout << std::endl;
  }
}
