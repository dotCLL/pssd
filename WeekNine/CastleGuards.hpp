// PSSD
// Week 9 - Q2
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class CastleGuards {
public:
  // Inputs: String representation of the way a castle is designed.
  // Outputs: the number of additional guards needed to properly secure the castle.
  // Finds the number of guards to make a castle secure.
  int missing(vector<string> castle);
};

int CastleGuards::missing(vector<string> castle) {
  // Vars.
  int emptyRows = 0;
  int emptyCols = 0;
  // Loop through the rows.
  for (int x = 0; x < castle.size(); x++) {
    // Current guard count.
    int gc = 0;
    // Loop through the row.
    for (int y = 0; y < castle[x].length(); y++) {
      // Found guard?
      if (castle[x][y] == 'X') {
        gc++;
        break;
      };
    };
    // If no guards are found up the empty row counter.
    if (gc == 0) {
      emptyRows++;
    };
  };
  // Loop through the columns.
  for (int x = 0; x < castle[0].length(); x++) {
    // Current guard count.
    int gc = 0;
    // Loop through the column.
    for (int y = 0; y < castle.size(); y++) {
      // Found guard?
      if (castle[y][x] == 'X') {
        gc++;
        break;
      };
    };
    // If no guards are found up the empty column counter.
    if (gc == 0) {
      emptyCols++;
    };
  };
  // Return the max guards needed for coverage.
  return max(emptyRows, emptyCols);
};
