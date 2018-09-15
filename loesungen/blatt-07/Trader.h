// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#ifndef TRADER_H_
#define TRADER_H_

#include <gtest/gtest.h>
#include "./MarketSimulator.h"

class Trader {
  // Allows MarketSimulator to modify private values without writing public
  // setters.
  friend class MarketSimulator;
 public:
  Trader();
  FRIEND_TEST(TraderTest, constructor);

  // Determines if new assets should be bought or not. Also decides if old
  // assets should be sold. The decisions are based on the last 3 observed
  // prices.
  void trade(const float price);
  FRIEND_TEST(TraderTest, trade);
  FRIEND_TEST(MarketSimulatorTest, simulateSimpleTraderInteraction);

  // Prints a final statistic. It shows how much profit was theoretically made
  // if all assets would be sould at the last price observed by the trade
  // method.
  void printStatistic() const;
  FRIEND_TEST(TraderTest, printStatistic);

 private:
  // Currently available money.
  float _money;

  // Number of current Assets.
  int _assets;

  // Tracks how much money was added externally.
  float _seedMoney;

  // Are we verbose?
  bool _verbose;

  // Store last 3 prices.
  float _lastPrices[3];
};

#endif  // TRADER_H_
