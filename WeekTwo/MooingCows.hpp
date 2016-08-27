// PSSD
// Week 2 - Q3.
#include <iostream>
using namespace std;

// Includes
#include <vector>
#include <cmath>
#include <algorithm>

class MooingCows {
public:
  // Inputs: the lay of the farmland
  // Outputs: minimum total dissatisfaction
  // Calculates the dissatisfaction of surrounding cows to a mooing cow.
  int dissatisfaction(vector<string> farmland);
};

int MooingCows::dissatisfaction(vector<string> farmland) {
  // Vector to hold the dissatisfaction level.
  vector<int> disLevels;
  // Temp string holders.
  string primary;
  string secondary;
  // Sum holder.
  int sum = 0;
  // The grid. Columns for x, rows for y.
  for (int y = 0; y < farmland.size(); y++) {
    // Set the string that will represent the row that we will loop through next.
    primary = farmland[y];
    // Loop through the row.
    for (int x = 0; x < primary.length(); x++) {
      // If there is a cow then calculate the dissatisfaction and add it to the vector.
      if (primary[x] == 'C') {
        // cout << "Mooing cow: " << x << "|" << y << endl;
        // Find all other cows.
        // Loop through the grid again but this time calculate the dissatisfaction as a distance from the x and y coords of the mooing cow.
        for (int j = 0; j < farmland.size(); j++) {
          // Row.
          secondary = farmland[j];
          // Loop through the row.
          for (int i = 0; i < secondary.length(); i++) {
            // If its a cow that isn't the mooing cow then calculate its dissatisfaction.
            if (secondary[i] == 'C') {
              // Make sure its not the mooing cow.
              if ((x == i) && (y == j)) {
                // Do nothing
              } else {
                // Calculate it's dissatisfaction and add it to the vector.
                // cout << "x: " << (x+1) << " i: " << (i+1) << " y: " << (y+1) << " j: " << (j+1) << endl;
                sum += ((pow(((x+1)-(i+1)),2)) + (pow(((y+1)-(j+1)),2)));
              }
            };
          };
        };
        // Add the full sum to the vector of dissatisfaction.
        disLevels.push_back(sum);
        // reset.
        sum = 0;
      };
    };
  };
  // Sort the vector.
  sort(disLevels.begin(), disLevels.end());
  // Return the minimum.
  return disLevels[0];
};
