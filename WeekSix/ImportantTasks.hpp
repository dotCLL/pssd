// PSSD
// Week 6 - Q3
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class ImportantTasks {
public:
  // Inputs: vector representation of a set of tasks given complexities and then a vector representation of a set of computers processing power.
  // Outputs: integer representing the total number of tasks completed.
  // Find the maximum number of tasks the computers can complete.
  int maximalCost(vector<int> complexity, vector<int> computers);
};

int ImportantTasks::maximalCost(vector<int> complexity, vector<int> computers) {
  // Vars.
  int completedTasks = 0;
  int counter = 0;
  // Sort the vectors in descending order.
  sort(complexity.rbegin(), complexity.rend());
  sort(computers.rbegin(), computers.rend());
  // Loop through the tasks.
  for (int i = 0; i < complexity.size(); i++) {
    // Counter in range?
    if (counter >= computers.size()) { break; };
    // Can the computer complete the task?
    if (computers[counter] >= complexity[i]) {
      completedTasks++;
      counter++;
    };
  };
  // Return the number of tasks.
  return completedTasks;
};
