// PSSD
// Week 4 - Q4
#include <iostream>
using namespace std;

// Includes
#include <cmath> // ceil.

class PaternityTest {
public:
  // Inputs: string representation of child DNA, string representation of mother DNA, set of string representations of possible father's DNA.
  // Outputs: a set of the possible fathers.
  // Analyses DNA to see if the child could have any possible fathers.
  vector<int> possibleFathers(string child, string mother, vector<string> men);
};

vector<int> PaternityTest::possibleFathers(string child, string mother, vector<string> men) {
  // vars.
  bool mumMatch;
  vector<int> dadMatchCount;
  vector<bool> bools;
  vector<int> resVec;
  // Fill vecs.
  for (int i = 0; i < men.size(); i++) {
    bools.push_back(true);
    dadMatchCount.push_back(0);
  };
  // Loop through the strings.
  for (int i = 0; i < mother.length(); i++) {
    // Does mum match?
    if (mother[i] == child[i]) {
      mumMatch = true;
    } else {
      mumMatch = false;
    };
    // Does dad match
    for (int x = 0; x < men.size(); x++) {
      // consider checking?
      if (bools[x] == true) {
        // break case?
        if ((men[x][i] != child[i]) && (!mumMatch)) {
          // Don't check again.
          bools[x] = false;
        } else {
          // Equal to child?
          if (men[x][i] == child[i]) {
            dadMatchCount[x]++;
          };
        };
      };
    };
  };
  // Enough counts?
  for (int i = 0; i < men.size(); i++) {
    // worth checking?
    if ((bools[i]) && (dadMatchCount[i] >= (ceil(mother.length() / 2)))) {
        // all good
    } else {
      bools[i] = false;
    };
  };
  // Create res vec.
  for (int i = 0; i < bools.size(); i++) {
    // true bool?
    if (bools[i]) {
      resVec.push_back(i);
    };
  };
  // Return.
  return resVec;
};
