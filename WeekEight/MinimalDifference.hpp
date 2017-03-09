// PSSD
// Week 8 - Q2
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <sstream>
#include <algorithm>

class MinimalDifference {
public:
  // Inputs: Start index, Finish index, Sum target.
  // Outputs: An integer representing the maximum value in tips that could be taken.
  // Emulates a strange coffee shop and the max amount of money the shop will make from tips.
  int findNumber(int A, int B, int C);
private:
  // Inputs: Integer to be split.
  // Outputs: An integer representing the sum of each digit.
  // Sums together each digit in a given number.
  int eval(int num);
};

int MinimalDifference::eval(int num) {
  // Vars.
  string nums;
  int total = 0;
  // Convert to string.
  ostringstream os;
  os << num;
  nums = os.str();
  // find total.
  for (int i = 0; i < nums.length(); i++) {
    char temp = nums[i];
    total += atoi(&temp);
  };
  // return the total.
  return total;
};

int MinimalDifference::findNumber(int A, int B, int C) {
  // Vars.
  int origin = A;
  int goal = eval(C);
  vector<int> diffs;
  // Loop through and evaluate each difference.
  while (A <= B) {
    // Calculate difference
    int diff = abs(goal - eval(A));
    // Exact match?
    if (diff == 0) {
      return A;
    };
    // Otherwise add to the vector.
    diffs.push_back(diff);
    // Up counter.
    A++;
  };
  // return the closest distance.
  return (origin + distance(diffs.begin(), min_element(diffs.begin(), diffs.end())));
};
