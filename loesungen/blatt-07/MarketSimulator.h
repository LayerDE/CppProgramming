// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef MARKETSIMULATOR_H_
#define MARKETSIMULATOR_H_

#include <gtest/gtest.h>
#include "./Trader.h"

// Forward declaration of trader.
class Trader;

class MarketSimulator {
 public:
  MarketSimulator();
  FRIEND_TEST(MarketSimulatorTest, constructor);

  // Parse command line.
  void parseCommandLineArguments(int argc, char** argv);
  FRIEND_TEST(MarketSimulatorTest, parseCommandLineArguments);
  FRIEND_TEST(MarketSimulatorTest, parseCommandLineArgumentsSetFunds);

  // Performs the simulation.
  // Sets initial values of the trader and calls Trader.trade for each line in
  // the input file. Trader.printStatistics is also called at the end.
  void simulate(Trader* trader) const;
  FRIEND_TEST(MarketSimulatorTest, simulateCantOpenInputFile);
  FRIEND_TEST(MarketSimulatorTest, simulateSimpleTraderInteraction);

 private:
  void printUsageAndExit() const;
  FRIEND_TEST(MarketSimulatorTest, printUsageAndExit);

  // Name of the input file.
  const char* _inputFileName;

  // Initial cash amount.
  float _seedMoney;

  // If true print information after each step. Otherwise only summary at the
  // end.
  bool _verbose;
};

#endif  // MARKETSIMULATOR_H_

