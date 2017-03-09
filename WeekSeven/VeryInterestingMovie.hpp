// PSSD
// Week 7 - Q4
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <cmath>

class VeryInterestingMovie {
public:
  // Inputs: string representation of a movie theater
  // Outputs: maximum number of students.
  // Finds the maximum number of students to fill a movie theater with no students sitting next to each other.
  int maximumPupils (vector<string> seats);
};

int VeryInterestingMovie::maximumPupils (vector<string> seats) {
  // total counter.
  int total = 0;
  // Loop through the theater.
  for (int x = 0; x < seats.size(); x++) {
    // Temp counter.
    float temp = 0;
    // Loop through this row.
    for (int y = 0; y < seats[x].length(); y++) {
      // If its a free seat then up the temp counter.
      if (seats[x][y] == 'Y') {
        temp++;
      } else {
        // If not add the ceiling of temp / 2 to the total and reset the temp.
        total += ceil(temp / 2);
        temp = 0;
      };
    };
    // Any left over?
    if (temp != 0) {
      total += ceil(temp / 2);
    };
  };
  // Return result.
  return total;
};
