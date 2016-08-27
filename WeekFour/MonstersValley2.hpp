// PSSD
// Week 4 - Q1
#include <iostream>
using namespace std;

// Includes.
#include <vector>

class MonstersValley2 {
public:
  // Inputs: set of monsters dread levels, set of monsters bribe pricing
  // Outputs: minimum cost to bribe.
  // Returns the minimum amount possible to bribe a certain number of monsters and survive.
  int minimumPrice(vector<int> dread, vector<int> price);
private:
  // Inputs: set of monsters dread levels, set of monsters bribe pricing, current party scariness.
  // Outputs: minimum cost to bribe.
  // Returns the minimum amount possible to bribe a certain number of monsters and survive.
  int minPrice(vector<int> dread, vector<int> price, long scariness);
};

int MonstersValley2::minimumPrice(vector<int> dread, vector<int> price) {
  // Hack to pass a parameter for recursive calls.
  // Using this rather than a global because im using recursion and i cant reset the global for the next test case that will
  // come from the main in web sub style testing.
  return minPrice(dread, price, 0);
};

int MonstersValley2::minPrice(vector<int> dread, vector<int> price, long scariness) {
  // base case.
  if (dread.size() == 0) {
    return 0;
  } else {
    // Create sub vecs for bribing situations.
    vector<int> subDread(&dread[1], &dread[dread.size()]);
    vector<int> subPrice(&price[1], &price[price.size()]);
    // Have to bribe?
    if (scariness < dread[0]) {
      // return the rest of the steps plus the cost of bribing on this step.
      return minPrice(subDread, subPrice, (scariness + dread[0])) + price[0];
    } else {
      // To bribe or not to bribe?
      // Bribe
      int bribe = minPrice(subDread, subPrice, (scariness + dread[0])) + price[0];
      // Don't bribe.
      int dontBribe = minPrice(subDread, subPrice, scariness);
      // Return the minimum.
      return min(bribe, dontBribe);
    };
  };
};
