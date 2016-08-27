// PSSD
// Week 3 - Q1
#include <iostream>
using namespace std;

class Truckloads {
public:
  // Inputs: number of crates at a warehouse, max # of crates that will fit in a truck.
  // Outputs: number of trucks.
  // Returns the number of trucks needed to move a particular number of crates.
  int numTrucks(int numCrates, int loadSize);
};

int Truckloads::numTrucks(int numCrates, int loadSize) {
  // Base case.
  if (numCrates <= loadSize) {
    return 1;
  };
  // vars.
  int numOfTrucks = 0;
  // calculate divide.
  if ((numCrates % 2) == 0) {
    int divisor = numCrates / 2;
    // Add to sum.
    numOfTrucks += (numTrucks(divisor, loadSize) + numTrucks(divisor, loadSize));
  } else {
    // calculate divisors
    int left = (numCrates/2) + 1;
    int right = (numCrates/2);
    // Add to sum.
    numOfTrucks += (numTrucks(left, loadSize) + numTrucks(right, loadSize));
  };
  // return sum.
  return numOfTrucks;
};
