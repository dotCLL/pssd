// PSSD
// Week 5 - Q5
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm> // sort

class TomekPhone {
public:
  // Inputs: frequencies that a set of keys are hit, the set of sizes of the keys.
  // Outputs: total number of keystrokes.
  // Returns the number of keystrokes for a text made on an imaginary phone.
  int minKeystrokes(vector<int> frequencies, vector<int> keySizes);
};

int TomekPhone::minKeystrokes(vector<int> frequencies, vector<int> keySizes) {
  // Vars.
  int total = 0;
  int count = 0;
  int multiplier = 1;
  int totalKeys = 0;
  // break case.
  for (int i = 0; i < keySizes.size(); i++) {
    totalKeys += keySizes[i];
  };
  if (totalKeys < frequencies.size()) { return -1; };
  // Sort frequencies.
  sort(frequencies.rbegin(), frequencies.rend());
  // Loop through total keypresses and multiply accordingly.
  while (totalKeys > 0) {
    // Loop through all of the possibles each time.
    for (int i = 0; i < keySizes.size(); i++) {
      // If the key is ok to be pressed then press it.
      if (keySizes[i] > 0) {
        // Add it to the total.
        total += multiplier * frequencies[count];
        // Count up until out of keys to press then return.
        count++;
        if (count == frequencies.size()) {
          return total;
        };
        // If its not time to break then minus off a press from the number of spots and also the totalkeys to be pressed.
        keySizes[i]--;
        totalKeys--;
      };
    };
    // Used up the keys for this level so up the multiplication amount.
    multiplier++;
  }
  // Return the total.
  return total;
};
