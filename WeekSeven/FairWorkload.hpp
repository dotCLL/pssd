// PSSD
// Week 7 - Q3
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>

class FairWorkload {
public:
  // Inputs: vector representation of a filing system, number of workers.
  // Outputs: maximum numbers each worker has to look at.
  // Finds the maximum number of files an employee would have to inspect in a filing system.
  int getMostWork(vector<int> folders, int workers);
  // Inputs: length of binary combinations, max number of partitions.
  // Outputs: vector representation of all possible combinations.
  // Fills a vector with all possible binary combinations of length N as long as they only consist of X 1's.
  vector<string> fillBins(int n, int x);
};

int FairWorkload::getMostWork(vector<int> folders, int workers) {
  // Create the possible partition positions.
  vector<string> position = fillBins(folders.size()-1, workers);
  // create a vector to hold the maximums.
  vector<int> maxs;
  // Loop through possible combinations
  for (int x = 0; x < position.size(); x++) {
    // Vars
    int sum = 0;
    int theMax = 0;
    // Add to sum.
    sum += folders[0];
    // Check if larger
    if (sum > theMax) {
      theMax = sum;
    };
    // Loop through the string.
    for (int y = 1; y <= position[x].length(); y++) {
      // Time to reset?
      if (position[x][y-1] == '1') {
        sum = 0;
      };
      // Add to sum.
      sum += folders[y];
      // Check if larger
      if (sum > theMax) {
        theMax = sum;
      };
    };
    // Add the maximum partition value to the maxs vector.
    maxs.push_back(theMax);
  };
  // Return the minimum of the maximums.
  return *min_element(maxs.begin(), maxs.end());
};


// Fills a vector with all possible binary combinations of length N as long as they only consist of X 1's.
vector<string> FairWorkload::fillBins(int n, int x) {
  // Vector to return.
  vector<string> bins;
  // Create all binary combinations up to n.
  for (int i = 0; i < (pow(2,n)); i++) {
    // Vars.
    string bin10 = bitset<16>(i).to_string();
    int oneCount = 0;
    // Loop through string to see if there are too many 1's.
    for (int x = 0; x < bin10.length(); x++) {
      if (bin10[x] == '1') {
        oneCount++;
      };
    };
    // If there isnt then add it to the vector.
    if (oneCount == (x-1)) {
      bins.push_back(bin10.substr((bin10.length()-n), bin10.length()));
    };
  };
  // Return the vector.
  return bins;
};
