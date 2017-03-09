// PSSD
// Week 10 - Q4
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>
#include <string>

class Multiples {
public:
  // Inputs:
  // Outputs:
  //
  int number(int min, int max, int factor);
};

int Multiples::number(int min, int max, int factor) {
  // Vars.
  int counter = 0;
  // Loop through from min max.
  for (int i = min; i <= max; i++) {
    // evenly divisible?
    if (i % factor == 0) {
      counter++;
    };
  };
  // Return result.
  return counter;
};
