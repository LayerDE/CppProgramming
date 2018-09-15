// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include "./String.h"
#include "./MarketSimulator.h"
#include "./Trader.h"

// _____________________________________________________________________________
MarketSimulator::MarketSimulator() {
  _inputFileName = "";
  _seedMoney = 0;
  _verbose = false;
}

// _____________________________________________________________________________
void MarketSimulator::printUsageAndExit() const {
  fprintf(stderr, "Usage: ./MarketSimulatorMain [options] <inputfile>\n");
  fprintf(stderr, "Available options:\n");
  fprintf(stderr, "--seed-money <float> : Amount of cash to start with.\n");
  fprintf(stderr, " (default: 1000.00)\n");
  fprintf(stderr, "--verbose : print information after each step\n");
  fprintf(stderr, " (default: false)\n");
  exit(1);
}

// _____________________________________________________________________________
void MarketSimulator::parseCommandLineArguments(int argc, char** argv) {
  struct option options[] = {
    {"seed-money", 1, NULL, 's'},
    {"verbose", 0, NULL, 'v'},
    {NULL, 0, NULL, 0}
  };
  optind = 1;

  // Default values
  _seedMoney = 1000;
  _verbose = false;
  _inputFileName = "";

  while (true) {
    char c = getopt_long(argc, argv, "s:v", options, NULL);
    if (c == -1) { break; }
    switch (c) {
      case 's':
        _seedMoney = atof(optarg);
        break;
      case 'v':
        _verbose = true;
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
void MarketSimulator::simulate(Trader* trader) const {
  FILE* inputFile = NULL;

  // Set trader internal values.
  trader->_verbose = _verbose;
  trader->_seedMoney = _seedMoney;
  trader->_money = _seedMoney;

  // Open required input file.
  inputFile = fopen(_inputFileName, "r");
  if (inputFile == NULL) {
    fprintf(stderr, "Error: Could not open input file \"%s\"\n",
            _inputFileName);
    exit(1);
  }

  // Buffer for reading lines.
  const size_t MAX_LINE_LENGTH = 1000;
  char line[MAX_LINE_LENGTH + 1];
  String parts[3];
  String input;

  // Performe actions by calling trader.
  while (true) {
    fgets(line, MAX_LINE_LENGTH + 1, inputFile);
    if (feof(inputFile)) { break; }
    // Set string to the read line.
    input.set(line);
    // Split, parse and trade with the current value.
    input.split(',', 3, parts);
    trader->trade(parts[1].toFloat());
  }

  fclose(inputFile);
}
