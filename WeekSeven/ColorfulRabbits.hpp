// PSSD
// Week 7 - Q5
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class ColorfulRabbits {
public:
  // Inputs: vector of data each rabbit saw.
  // Outputs: the total number of rabbits in a town.
  // After asking certain rabbits how many others of each color in the town are then same you find the total number of rabbits in the town.
  int getMinimum(vector<int> replies);
};

int ColorfulRabbits::getMinimum(vector<int> replies) {
  // Vars.
  int rabbits = 0;
  int disregard = 0;
  int previous = 0;
  // Sort replies.
  sort(replies.begin(), replies.end());
  // Add first reply.
  rabbits += (replies[0] + 1);
  // Set number of rabbits to disregard.
  disregard = replies[0];
  // Set previous.
  previous = replies[0];
  // Loop through the rest of the replies.
  for (int i = 1; i < replies.size(); i++) {
    // If it is the same as the previous and the disregard counter isn't zero then disregard this element and update the counter.
    if (replies[i] == previous && disregard != 0) {
      disregard--;
    } else {
      // Otherwise add the next reply.
      rabbits += (replies[i] + 1);
      // Set number of rabbits to disregard.
      disregard = replies[i];
      // Set previous.
      previous = replies[i];
    };
  };
  // Return the total number of rabbits.
  return rabbits;
};
