// PSSD
// Week 7 - Q2
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <cmath>
#include <bitset>

class LotteryTicket {
public:
  // Inputs: target denomination, bank notes
  // Outputs: string representation of whether its possible or not.
  // Finds if the given bank notes can equal a given denomination without change.
  string buy(int price, int b1, int b2, int b3, int b4);
  // Inputs: length of binary combinations
  // Outputs: vector representation of all possible combinations
  // Fills a vector with all possible binary combinations of length N.
  vector<string> fillBins(int n);
};

string LotteryTicket::buy(int price, int b1, int b2, int b3, int b4) {
  // Vars.
  bool combFound = false;
  // first check.
  if (b1 == price || b2 == price || b3 == price || b4 == price) {
    return "POSSIBLE";
  };
  // Create vector of possible combinations.
  vector<string> combs = fillBins(4);
  // Loop through the combinations to see if there is a possible combination.
  for (int i = 0; i < combs.size(); i++) {
    // Temporary sum.
    int sum = 0;
    // Add the banknote?
    if (combs[i][0] == 49) {
      sum += b1;
    };
    if (combs[i][1] == 49) {
      sum += b2;
    };
    if (combs[i][2] == 49) {
      sum += b3;
    };
    if (combs[i][3] == 49) {
      sum += b4;
    };
    // Is sum a possible combination?
    if (sum == price) {
      combFound = true;
      break;
    };
  };
  // If there is a combination then return its possible otherwise return impossible.
  if (combFound) {
    return "POSSIBLE";
  } else {
    return "IMPOSSIBLE";
  };
};

// Fills a vector with all possible binary combinations of length N.
vector<string> LotteryTicket::fillBins(int n) {
  vector<string> bins;
  for (int i = 0; i < (pow(2,n)); i++) {
    string bin10 = bitset<10>(i).to_string();
    bins.push_back(bin10.substr((bin10.length()-n), bin10.length()));
  };
  return bins;
};
