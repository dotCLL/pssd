// PSSD
// Week 1 - Q4
#include <iostream>
using namespace std;

// class
class EggCartons {
public:
  // Prototypes.
  int minCartons(int n);
};

// Finds out the best combination of cartons needed for a particular number of eggs.
int EggCartons::minCartons(int n) {
  // Base cases - Less than 6 or odd.
  if ((n < 6) || (n%2 != 0)) {
    return -1;
  // End cases - Add to the count for 6 or 8.
  } else if ((n == 6) || (n == 8)) {
    return 1;
  // Counters - Recur minusing by 6 and by 8 essentially finding the combinations of where they are divisible.
  } else {
    int six = minCartons(n - 6);
    int eight = minCartons(n - 8);
    // All possible cases.
    if ((six == -1) && (eight == -1)) {
      return -1;
    } else if ((six != -1) && (eight == -1)) {
      return (six + 1);
    } else if ((six == -1) && (eight != -1)) {
      return (eight + 1);
    } else {
      if (six < eight) {
        return (six + 1);
      } else {
        return (eight + 1);
      };
    };
  };
};
