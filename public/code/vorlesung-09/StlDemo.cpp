// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>

#include "./StlDemo.h"
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


// _____________________________________________________________________________
void StlDemo::readMoviesFromFile(std::string filename) {
  std::ifstream file(filename.c_str());
  if (!file.is_open()) {
    std::cerr << "Error opening file " << filename << std::endl;
    return;
  }

  std::vector<Movie> movies;
  std::string line;
  while (true) {
    std::getline(file, line);
    if (file.eof()) { break; }

    size_t pos1 = line.find('\t');
    if (pos1 == std::string::npos) { continue; }
    size_t pos2 = line.find('\t', pos1 + 1);
    if (pos2 == std::string::npos) { continue; }

    Movie movie;
    movie.title = line.substr(0, pos1);
    movie.year = atoi(line.substr(pos1 + 1, pos2 - pos1 - 1).c_str());
    movie.popularity = atoi(line.substr(pos2 + 1).c_str());
    _moviesByYear[movie.year].push_back(movie);
  }
}


// _____________________________________________________________________________
void StlDemo::sortMoviesByPopularity() {
  for (auto& pair : _moviesByYear) {
    std::vector<Movie>& v = pair.second;
    std::sort(v.begin(), v.end(), [](const Movie& m1, const Movie& m2) {
      return m1.popularity > m2.popularity;
    });
  }
}
