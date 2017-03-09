// PSSD
// Week 9 - Q5
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>
#include <utility>

class CellRemoval {
public:
  // Inputs: vector representation of the develoment process of an organism, the cell removed from the cell structure.
  // Outputs: the number of cells in the cell structure.
  // Returns the number of cells left in a cell structure after a cell is removed.
  int cellsLeft(vector<int> parent, int deletedCell);
};

int CellRemoval::cellsLeft(vector<int> parent, int deletedCell) {
  // breakcase.
  if (parent.size() == 0) {
    return 0;
  };
  // Vars.
  vector<pair<int, int> > lookFor;
  int leaves = 0;
  // Add root expectation
  lookFor.push_back(make_pair(-1, -1));
  // Loop through all of the nodes.
  for (int x = 0; x < parent.size(); x++) {
    // finished?
    if (lookFor.size() == x) {
      break;
    };
    // Find children.
    for (int y = 0; y < parent.size(); y++) {
      // Found
      if (lookFor[x].first == parent[y]) {
        // Add index as being the next children as long as its not the index we aren't looking to keep.
        if (parent[y] != deletedCell) {
          lookFor.push_back(make_pair(y, lookFor[x].first));
        };
      };
    };
  };
  // Count the number of leaves including the root.
  for (int i = 0; i < lookFor.size(); i+=2) {
    if (lookFor[i].second == lookFor[i+1].second) {
      leaves++;
    };
  };
  // Return the total number of leaves minus one.
  return (leaves-1);
};
