// PSSD
// Week 10 - Q5
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class Thimbles {
public:
  // Inputs:
  // Outputs:
  //
  int thimbleWithBall(vector<string> swaps);
};

int Thimbles::thimbleWithBall(vector<string> swaps) {
  // current cup.
  char cc = '1';
  // Loop through the vector.
  for (int i = 0; i < swaps.size(); i++) {
    // Change cup?
    if (swaps[i][0] == cc) {
      cc = swaps[i][2];
    } else if (swaps[i][2] == cc) {
      cc = swaps[i][0];
    };
  };
  // Return the integer representation.
  return atoi(&cc);
};
