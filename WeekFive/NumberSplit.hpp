// PSSD
// Week 5 - Q1
#include <iostream>
using namespace std;

// Includes.
#include <sstream>
#include <bitset>
#include <cmath> // pow
#include <vector>
#include <algorithm> // Max element

class NumberSplit {
public:
  // Inputs: starting number
  // Outputs: number respresenting the length of the biggest sequence
  // Given an integer it calculates the longest sequence of sub-integers using dynamic programming.
  int longestSequence(int start);
private:
  // Inputs: string representation of the number, max possible number of multiplication symbols
  // Outputs: a vector of equation totals.
  // Returns a vector of all possible combination totals of a set of equations.
  vector<int> possCombs(string num, int k);
  // Inputs: starting number
  // Outputs: number respresenting the length of the biggest sequence
  // Given an integer it calculates the longest sequence of sub-integers.
  int longSeq(int start);
  // Vector for dynamic programming.
  vector<int> dp;
};

int NumberSplit::longestSequence(int start) {
  // clear vec.
  dp.clear();
  // Fill with -1's
  for (int i = 0; i < 100000; i++) {
    dp.push_back(-1);
  };
  // Recur.
  return longSeq(start);
}

int NumberSplit::longSeq(int start) {
  // vars.
  vector<int> combTotals;
  vector<int> resVec;
  // Get length of integer.
  ostringstream ss;
  ss << start;
  string startStr = ss.str();
  int startLen = startStr.length();
  // One digit?
  if (startLen == 1) {
    return 1;
  };
  // Find possible combinations.
  combTotals = possCombs(startStr, startLen-1);
  // loop through possible combinations.
  for (int i = 0; i < combTotals.size(); i++) {
    // if already calculated then just use the value.
    if (dp[combTotals[i]] != -1) {
      resVec.push_back(dp[combTotals[i]]);
    } else {
      // Calculate.
      int holder = longSeq(combTotals[i]) + 1;
      // Add to resVec the rest of the tree + 1.
      resVec.push_back(holder);
      // Add to the dp vec just in case its needed later.
      dp[combTotals[i]] = holder;
    };
  };
  // Get max element of resVec.
  return *max_element(&resVec[0], &(resVec[resVec.size()]));
};

vector<int> NumberSplit::possCombs(string num, int k) {
  // vars
  vector<string> bins;
  vector<string> eqns;
  vector<int> res;
  int currentTotal = 1;
  string totalStr = "";
  // Create combinations except for the original.
  for (int i = 1; i < (pow(2,k)); i++) {
    // Create binary rep.
    string bin10 = bitset<10>(i).to_string();
    // Resize it.
    bins.push_back(bin10.substr((bin10.length()-k), bin10.length()));
  };
  // loop through the number and create the equations.
  for (int x = 0; x < bins.size(); x++) {
    for (int y = 0; y < bins[x].length(); y++) {
      // Add first digit.
      totalStr += num[y];
      // If time to multiply then multiply current number by the current total.
      if (bins[x][y] == '1') {
        currentTotal = currentTotal * atoi(&totalStr[0]);
        // Reset.
        totalStr = "";
      };
      // cout << currentTotal << "***" << endl;
    };
    // finish off string.
    totalStr += num[num.length()-1];
    // finish total.
    currentTotal = currentTotal * atoi(&totalStr[0]);
    // cout << currentTotal << endl;
    // add to vec.
    res.push_back(currentTotal);
    // reset.
    currentTotal = 1;
    totalStr = "";
  };
  // Return vec.
  return res;
};
