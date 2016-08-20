// PSSD
// Inchworm practice question 01
#include <iostream>
using namespace std;

// inchworm simulator class.
class Inchworm {
public:
  int lunchtime(int branch, int rest, int leaf);
};

// Moves an inchworm along a branch and eats a leaf if there happens to be one when it comes to a rest.
int Inchworm::lunchtime(int branch, int rest, int leaf) {
  // Vars
  int eatLeafCount = 1;
  // Error handle a never resting or no leaf situation
  if ((rest == 0) || (leaf == 0)) {
    return 1;
  };
  // Loop until the end of the branch.
  for (int i = 1; i < (branch+1); i++) {
    // If the worm rests at the same time where there is a leaf then eat that leaf and up the eaten leaf count.
    if (((i % rest) == 0) && ((i % leaf) == 0)) {
      eatLeafCount++;
    };
  };
  // Return the number of eaten leafs.
  return eatLeafCount;
};
