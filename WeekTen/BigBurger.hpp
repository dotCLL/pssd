// PSSD
// Week 10 - Q2
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class BigBurger {
public:
  // Inputs: vector representation of arrival times of certain customers, vector representation of the time it took for a customer to receive service.
  // Outputs: the maximum time that any customer had to wait.
  // Finds the maximum wait time of a set of customers waiting in line at a burger store.
  int maxWait(vector<int> arrival, vector<int> service);
};

int BigBurger::maxWait(vector<int> arrival, vector<int> service) {
  // Vars.
  int maxWait = 0;
  int wait = 0;
  int leaveTime = arrival[0] + service[0];
  // Loop through the vectors.
  for (int i = 1; i < arrival.size(); i++) {
    // Set wait
    if (arrival[i] < leaveTime) {
      wait = abs(arrival[i] - leaveTime);
    } else {
      wait = 0;
    };
    // Bigger than max?
    if (wait > maxWait) {
      maxWait = wait;
    };
    // Reset leave time for next iteration.
    leaveTime = arrival[i] + service[i] + wait;
  };
  // return max wait time.
  return maxWait;
};
