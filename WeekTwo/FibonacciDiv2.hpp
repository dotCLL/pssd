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
private:
  // helper function to see if a number is a fibonacci number.
  bool IsFib(int target) {
      double root5 = sqrt(5);
      double phi = (1 + root5) / 2;

      int index = (int) floor( log(target*root5) / log(phi) + 0.5 );
      int u = (int) floor( pow(phi, index)/root5 + 0.5);

      return (u == target);
  };
};

int FibonacciDiv2::find(int N) {
  // // Base cases.
  // if ((N == 0) || (N == 1)) {
  //   return 0;
  // };
  // // Vars.
  // int numOfPossibleSteps = 0;
  // int first = 0;
  // int sec = 1;
  // int curr;
  // int diffL;
  // int diffR;
  // // Loop until the combination is found. MAX GIVEN FROM SPEC.
  // for (int i = 2; i < 1000000; i++) {
  //   // Up counter.
  //   numOfPossibleSteps++;
  //   // Fill vars.
  //   curr = first + second;
  //   diffL = curr - first;
  //   diffR = curr - second;
  //   // found it?
  //   if ((curr - diffL) <= )
  // };


  // // Base cases.
  // // If its a fibonacci number just return N.
  // if (IsFib(N)) {
  //   return 0;
  // };
  // cout << "N: " << N << endl;
  // // Left and right counters.
  // int left = find(N-1);
  // int right = find(N+1);
  // // cout << "Left: " << left << " Right: " << right << endl;
  // // Which one was quicker?
  // if (left < right) {
  //   return left;
  // } else {
  //   return right;
  // };

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
