// PSSD
// Week 2 - Q3.
#include <iostream>
using namespace std;

// Includes.
#include <cstdlib> // ABS.
#include <vector>
#include <algorithm> // Sort

class ChangingString {
public:
  // Inputs: first string, second string, number of characters allowed to be swapped.
  // Outputs: minimum distance between the two strings after swaps.
  // Returns the minimum distance after swapping so many characters in a string compared to another string.
  int distance(string A, string B, int K);
};

int ChangingString::distance(string A, string B, int K) {
  // Vars.
  vector<int> distVec;
  int totalDist = 0;
  int tempDist;
  // Loop through the string and get the distance.
  for (int i = 0; i < A.length(); i++) {
    // Add to the distance.
    tempDist = abs(B[i] - A[i]);
    // Add it.
    distVec.push_back(tempDist);
  };
  // Sort the vector. - Descending now.
  sort(distVec.rbegin(), distVec.rend());

  // Sum the total.
  for (int i = 0; i < distVec.size(); i++) {
    // Error handle within K must swap values.
    if (i < K) {
      if (distVec[i] == 0) {
        distVec[i] = 1;
      } else {
        distVec[i] = 0;
      };
    };
    // Add to totalDist.
    totalDist += distVec[i];
  };
  // return.
  return totalDist;
};
