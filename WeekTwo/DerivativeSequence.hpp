// PSSD
// Week 2 - Q4.
#include <iostream>
using namespace std;

class DerivativeSequence {
public:
  // Inputs: sequence of number, order.
  // Outputs: new sequence n of a.
  // Returns a vector of a completed mathematical sequence.
  vector<int> derSeq(vector<int> a, int n);
};

vector<int> DerivativeSequence::derSeq(vector<int> a, int n) {
  // Create resVec.
  vector<int> resVec = a;
  // create a new vector n times.
  for (int x = 0; x < n; x++) {
    // Loop through and create new vector.
    for (int i = 0; i < resVec.size(); i++) {
      // Calculate.
      resVec[i] = (resVec[(i+1)]) - (resVec[i]);
    };
    // Remove last element.
    resVec.pop_back();
  };
  // Return.
  return resVec;
};
