// PSSD
// Week 8 - Q1
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class TaliluluCoffee {
public:
  // Inputs: Vector representation of a line of customers and their current tip value.
  // Outputs: An integer representing the maximum value in tips that could be taken.
  // Emulates a strange coffee shop and the max amount of money the shop will make from tips.
  int maxTip(vector<int> tips);
};

int TaliluluCoffee::maxTip(vector<int> tips) {
  // vars.
  int maxResult = 0;
  // Sort vector in descending order.
  sort(tips.rbegin(), tips.rend());
  // Loop through the vector and add the tips minus the current index of customer to the array unless it is zero or negative.
  for (int i = 0; i < tips.size(); i++) {
    // Set current tip value.
    int currTip = tips[i] - i;
    // Check for negatives.
    if (currTip <= 0) {
      break;
    };
    // Otherwise add to the counter.
    maxResult += currTip;
  };
  // Return the result.
  return maxResult;
};
