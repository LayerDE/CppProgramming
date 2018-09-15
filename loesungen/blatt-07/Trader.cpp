// Copyright 2018, University of Freiburg,
// Chair of Algorithms and Data Structures.
// Author: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

#include <stdio.h>
#include "./Trader.h"

// _____________________________________________________________________________
Trader::Trader() {
  _money = 0;
  _seedMoney = 0;
  _assets = 0;
  _verbose = false;
  _lastPrices[0] = 0.0;
  _lastPrices[1] = 0.0;
  _lastPrices[2] = 0.0;
}

// _____________________________________________________________________________
void Trader::printStatistic() const {
  float wealth = _money + _assets * _lastPrices[2];
  printf("Final wealth: %0.2f$ + %d * %0.2f$ = %0.2f$\n",
          _money, _assets, _lastPrices[2], wealth);
  printf("After subtracting investment (%0.2f$) the profit"
          " is: %0.2f$\n", _seedMoney, wealth - _seedMoney);
}

// _____________________________________________________________________________
void Trader::trade(const float price) {
  if (_lastPrices[0] < _lastPrices[1] && _lastPrices[1] < _lastPrices[2]
      && _lastPrices[2] < price && price <= _money) {
    // Value increased
    _money -= price;
    _assets++;
    if (_verbose) {
      printf("Buy 1 BC for %f. %0.2f$ + %d * %0.2f$ = %0.2f$\n", price,
             _money, _assets, price, _money + _assets * price);
    }
  } else if (_lastPrices[0] > _lastPrices[1] && _lastPrices[1] > _lastPrices[2]
             && _lastPrices[2] > price && _assets > 0) {
    // Value decreased
    _money += price;
    _assets--;
    if (_verbose) {
      printf("Sell 1 BC for %f. %0.2f$ + %d * %0.2f$ = %0.2f$\n", price,
             _money, _assets, price, _money + _assets * price);
    }
  }
  // Update price history
  _lastPrices[0] = _lastPrices[1];
  _lastPrices[1] = _lastPrices[2];
  _lastPrices[2] = price;
}
