// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>

#include <algorithm>
#include <iostream>
#include "./StlDemo.h"

int main(int argc, char** argv) {
  StlDemo demo;
  demo.readMoviesFromFile(argv[1]);
  demo.sortMoviesByPopularity();

  for (auto& pair : demo._moviesByYear) {
    std::cout << pair.first << ":";
    for (size_t i = 0; i < std::min(size_t(3), pair.second.size()); ++i) {
      std::cout << " " << pair.second[i].title
        << " (" << pair.second[i].popularity << ")";
    }
    std::cout << std::endl;
  }
}
