// PSSD
// Week 4 - Q2
#include <iostream>
using namespace std;

class RugSizes {
public:
  // Inputs: target area.
  // Outputs: number of possible rugs.
  // Calculate the number of possible rug combinations to get to a target area given certain restraints.
  int rugCount(int area);
};

int RugSizes::rugCount(int area) {
  // Vars.
  int counter = 0;
  // Loop through creating x and y.
  for (int x = 0; x <= area; x++) {
    for (int y = 0; y <= area; y++) {
      // If x and y equal the area then check the constraints.
      if ((x * y) == area) {
        // If they are equal then up counter.
        if (x == y) {
          counter++;
        // If either of them is odd...
      } else if (((x % 2) != 0) || ((y % 2) != 0)) {
          // only get the combinations with the first less than the second to skip double ups.
          if (x < y) {
            counter++;
          };
        };
      };
    };
  };
  // Return the count.
  return counter;
};
