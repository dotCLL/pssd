// PSSD
// Week 3 - Q$.
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class Arrows {
public:
  int longestArrow(string s);
private:
  vector<int> maxs;
};

int Arrows::longestArrow(string s) {
  // Clear vec.
  maxs.clear();
  // Vars.
  int counter = 0;
  const char LT = '<';
  const char GT = '>';
  char currentChar;
  // Loop from front to back.
  for (int x = 0; x < s.length(); x++) {
    // Find < symbols.
    if (s[x] == LT) {
      // Up counter.
      counter++;
      // Loop through for length.
      for (int y = (x+1); y < s.length(); y++) {
        // If it's an arrowhead then do nothing.
        if ((s[y] == LT) || (s[y] == GT)) {
          // Not an arrow.
          break;
        } else {
          // Set initial.
          if (y == (x+1)) {
            currentChar = s[y];
            // Up count.
            counter++;
          } else {
            // Now check the rest.
            if (s[y] == currentChar) {
              // Up count.
              counter++;
            } else {
              // Arrow is finished.
              break;
            };
          };
        };
      };
      // Add the total to the vector.
      maxs.push_back(counter);
    };
    // reset counter.
    counter = 0;
  };

  // Loop from back to front.
  for (int x = s.length()-1; x >= 0; x--) {
    // Find > symbols.
    if (s[x] == GT) {
      // Up counter.
      counter++;
      // Loop through for length. NOTE
      for (int y = (x-1); y >= 0; y--) {
        // If it's an arrowhead then do nothing.
        if ((s[y] == LT) || (s[y] == GT)) {
          // Not an arrow.
          break;
        } else {
          // Set initial.
          if (y == (x-1)) {
            currentChar = s[y];
            // Up count.
            counter++;
          } else {
            // Now check the rest.
            if (s[y] == currentChar) {
              // up count.
              counter++;
            } else {
              // Arrow is finished.
              break;
            };
          };
        };
      };
      // Add the total to the vector.
      maxs.push_back(counter);
    };
    // reset counter.
    counter = 0;
  };
  // return the max element.
  if (maxs.size() > 0) {
    return *max_element(maxs.begin(), maxs.end());
  } else {
    return -1;
  };
};
