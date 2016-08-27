// PSSD
// Week 4 - Q5
#include <iostream>
using namespace std;

// Includes
#include <vector>

class TimeTravellingCellar {
public:
  // Inputs: vector representing the profit per cellar, vector representing the decay per cellar
  // Outputs: max profit.
  // Determine the max profit possible if you were to switch some cellars of wine.
  int determineProfit(vector<int> profit, vector<int> decay);
};

int TimeTravellingCellar::determineProfit(vector<int> profit, vector<int> decay) {
  // vars.
  int maxProf = 0;
  // Loop through the profit.
  for (int x = 0; x < profit.size(); x++) {
    for (int y = 0; y < profit.size(); y++) {
      // can't be same cellar and has to be greater than the current max.
      if ((x != y) && ((profit[x] - decay[y]) > maxProf)) {
        // set max.
        maxProf = profit[x] - decay[y];
      };
    };
  };
  // Return.
  return maxProf;
};
