// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>,
//         Axel Lehmann <lehmann@cs.uni-freiburg.de>,
//         Johanna Götz <johanna.goetz@uranus.uni-freiburg.de>.

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include "./WordCounter.h"

// _____________________________________________________________________________
int main(int argc, char** argv) {
  WordCounter wc;
  wc.parseCommandLineArguments(argc, argv);
  wc.process();
  // Alternatively, if exercise 5 (optional) was not worked on,
  // read the file name directly from argv:
  // WordCounter wc;
  // if (argc != 2) {
  //   wc.printUsageAndExit();
  // }
  // wc.readFile(argv[1]);
  // size_t index = 0;
  // for (auto& pair : wc.computeFrequentWords()) {
  //   std::cout << ++index << " " << pair.first.c_str();
  //   std::cout << " (" << pair.second << ")" << std::endl;
  // }
}

