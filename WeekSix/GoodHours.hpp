// PSSD
// Week 6 - Q1
#include <iostream>
using namespace std;

// Includes.



class GoodHours {
public:
  // Inputs: string representation of the start time, string representation of the end time.
  // Outputs: number corresponding to the correct combination.
  // Returns an integer representing the number of time a combination is found in a set of changing times.
  int howMany(string beforeTime, string afterTime);
};

int GoodHours::howMany(string beforeTime, string afterTime) {
  // Combination ok counter.
  int counter = 0;
  // Set array.
  int currTime[] = {(beforeTime[0]-48), (beforeTime[1]-48), (beforeTime[3]-48), (beforeTime[4]-48)};
  int finishTime[] = {(afterTime[0]-48), (afterTime[1]-48), (afterTime[3]-48), (afterTime[4]-48)};
  // Loop until end time.
  while (true) {
    // Combinations.
    if (currTime[0] == (currTime[1] * currTime[2] * currTime[3])) {
      counter++;
    } else if ((currTime[0] * currTime[1]) == (currTime[2] * currTime[3])) {
      counter++;
    } else if ((currTime[0] * currTime[1] * currTime[2]) == (currTime[3])) {
      counter++;
    };
    // break case.
    if ((currTime[0] == finishTime[0]) && (currTime[1] == finishTime[1]) && (currTime[2] == finishTime[2]) && (currTime[3] == finishTime[3])) {
      break;
    };
    // Up the timer.
    currTime[3]++;
    if (currTime[3] == 10) {
      currTime[3] = 0;
      currTime[2]++;
      if (currTime[2] == 6) {
        currTime[2] = 0;
        currTime[1]++;
        if ((currTime[1] == 10) && ((currTime[0] == 1) || (currTime[0] == 0))) {
          currTime[1] = 0;
          currTime[0]++;
        } else if ((currTime[1] == 4) && (currTime[0] == 2)) {
          currTime[1] = 0;
          currTime[0] = 0;
        };
      };
    };
    // cout << currTime[0] << currTime[1] << ":" << currTime[2] << currTime[3] << endl;
  };
  // Return.
  return counter;
};
