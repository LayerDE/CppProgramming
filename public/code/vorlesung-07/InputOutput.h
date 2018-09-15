// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Hannah Bast <bast@cs.uni-freiburg.de>

#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_

// Class for demonstration input-output code.
class InputOutput {
 public:
  // Parse the command line arguments.
  void parseCommandLineArguments(int argc, char** argv);

  // Process a given input file.
  void process();

 private:
  // Name of the input file.
  const char* _filename;

  // Show only this many lines.
  int _headCount = 10;

  // Show line numbers or not.
  bool _showLineNumbers = false;
};

#endif  // INPUTOUTPUT_H_
