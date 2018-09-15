// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>

#ifndef STLDEMO_H_
#define STLDEMO_H_

#include <string>
#include <unordered_map>
#include <vector>

// Forward declaration of movie
class Movie;

class StlDemo {
 public:
  // Reads a given file and stores its contents as ...
  void readMoviesFromFile(std::string filename);

  // Sorts the vectors stored in the map.
  void sortMoviesByPopularity();

  // Public, should be private in a real programm.
  std::unordered_map<size_t, std::vector<Movie>> _moviesByYear;
};

class Movie {
 public:
  std::string title;

  size_t year;

  size_t popularity;
};

#endif  // STLDEMO_H_
