// PSSD
// Week 5 - Q4
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>


class RGBStreet {
public:
  // Inputs: string representation of a street of houses and the costs to paint them certain colours.
  // Outputs: the lowest cost.
  // Returns the minimum cost to paint a street of houses.
  int estimateCost(vector<string> houses);
private:
  // Inputs: string representation of a street of houses and the costs to paint them certain colours, a string representation of the possible combination.
  // Outputs: the lowest cost.
  // Returns the minimum cost to paint a street of houses.
  int estCost(vector<string> houses, string comb);
  // Inputs: string representation of painting one house out of three possible colours.
  // Outputs: vector of integers of costs.
  // Converts a string of costs to an integer vector of the costs.
  vector<int> getCosts(string cost);
  // Inputs: width of the table.
  // Outputs: void.
  // Creates a table to be used for dynamic programming.
  void table(int num);
  // Vector respresenting the table.
  vector<vector<int> > dp;
};

void RGBStreet::table(int num) {
  // temp.
  vector<int> temp;
  // Fill temp.
  temp.push_back(-1);
  temp.push_back(-1);
  temp.push_back(-1);
  // Add to dp num times.
  for (int i = 0; i < num; i++) {
    dp.push_back(temp);
  };
};

int RGBStreet::estimateCost(vector<string> houses) {
  // Clear dp.
  dp.clear();
  // Create dp table.
  table(houses.size());
  // Pass through start case. IE can choose R, G or B.
  return estCost(houses, "111");
};


int RGBStreet::estCost(vector<string> houses, string comb) {
  // Base case.
  if (houses.size() < 1) {
    return 0;
  };
  // Create costs vec.
  vector<int> costs = getCosts(houses[0]);
  // create subvec.
  vector<string> rest(&houses[1], &houses[0]+houses.size());
  // Is Red, Green or Blue allowed?
  int redMin = costs[0];
  int greenMin = costs[1];
  int blueMin = costs[2];
  // This house is red so neighbour can only be blue or green.
  if (comb[0] == '1') {
    // Get the min if we choose to paint this house red.
    // If its there just use it.
    if (dp[rest.size()][0] != -1) {
      redMin = dp[rest.size()][0];
    } else {
      // If not calculate.
      redMin += estCost(rest, "011");
      // Add to the table.
      dp[rest.size()][0] = redMin;
    };
  };
  // This house is green so neighbour can only be blue or red.
  if (comb[1] == '1') {
    // Get the min if we choose to paint this house blue.
    // If its there just use it.
    if (dp[rest.size()][1] != -1) {
      greenMin = dp[rest.size()][1];
    } else {
      // If not calculate.
      greenMin += estCost(rest, "101");
      // Add to the table.
      dp[rest.size()][1] = greenMin;
    };
  };
  // This house is blue so neighbour can only be green or red.
  if (comb[2] == '1') {
    // Get the min if we choose to paint this house blue.
    // If its there just use it.
    if (dp[rest.size()][2] != -1) {
      blueMin = dp[rest.size()][2];
    } else {
      // If not calculate.
      blueMin += estCost(rest, "110");
      // Add to the table.
      dp[rest.size()][2] = blueMin;
    };
  };
  // Return the choice that costs the minimum amount.
  if ((comb[0] == '1') && (comb[1] == '1') && (comb[2] == '1')) {
    return min(redMin, min(greenMin, blueMin));
  } else if ((comb[0] == '1') && (comb[1] == '1')) {
    return min(redMin, greenMin);
  } else if ((comb[0] == '1') && (comb[2] == '1')) {
    return min(redMin, blueMin);
  } else if ((comb[1] == '1') && (comb[2] == '1')) {
    return min(greenMin, blueMin);
  } else {
    cout << "debug me" << endl;
  }
};

vector<int> RGBStreet::getCosts(string cost) {
  // vars.
  vector<int> resVec;
  string temp = "";
  // Loop through string and add to temp until full digit.
  for (int i = 0; i < cost.length(); i++) {
    // If not whitespace add to the temp.
    if (cost[i] != ' ') {
      temp += cost[i];
    } else {
      // if hit white space add the integer representation of temp to the vector and reset.
      resVec.push_back(atoi(&temp[0]));
      temp = "";
    };
  };
  // Add the last integer.
  resVec.push_back(atoi(&temp[0]));
  // return the result.
  return resVec;
};
