// PSSD
// Week 2 - Q5.
#include <iostream>
using namespace std;

// Includes
#include <cmath>

class FibonacciDiv2 {
public:
  // Inputs: any integer N.
  // Outputs: the number of additions or subtractions to get to the closest fibonacci number.
  // Returns the smallest number of needed additions or subtractions of a given number to fit it into the fibonacci sequence.
  int find(int N);
};

int FibonacciDiv2::find(int N) {
  // Vars
  int first = 0;
  int second = 1;
  int holder;
  int diffL;
  int diffR;
  // Base cases.
  if ((N == first) || (N == second)) {
    return 0;
  };
  // Loop through until find the possible answers.
  while (second <= N) {
    holder  = second;
    second = first + second;
    first = holder;
  };
  // Calculate the differences on either side.
  diffL = N - first;
  diffR = second - N;
  // return the smallest distance.
  return min(diffL, diffR);
};
