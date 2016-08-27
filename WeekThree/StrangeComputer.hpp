// PSSD
// Week 3 - Q3
#include <iostream>
using namespace std;

class StrangeComputer {
public:
  // Inputs: goal memory representation.
  // Outputs: minimum number of operations.
  // Calculates how many operations are needed to recreate the goal representation.
  int setMemory(string mem);
};

int StrangeComputer::setMemory(string mem) {
  // vars.
  string startString = "";
  const char ZERO = '0';
  const char ONE = '1';
  int counter = 0;
  // Create startString.
  for (int i = 0; i < mem.length(); i++) {
    startString += "0";
  };
  // Loop through the startString and compare with mem.
  for (int x = 0; x < mem.length(); x++) {
    // If the number needs to be changed then change it.
    if (startString[x] != mem[x]) {
      // ZERO
      if (mem[x] == ZERO) {
        // loop through and change the rest to zero's.
        for (int i = x; i < mem.length(); i++) {
          startString[i] = ZERO;
        };
        // Up the counter of changes.
        counter++;
      } else {
        // loop through and change the rest to zero's.
        for (int i = x; i < mem.length(); i++) {
          startString[i] = ONE;
        };
        // Up the counter of changes.
        counter++;
      }
    };
  };
  // Return the number of changes.
  return counter;
};
