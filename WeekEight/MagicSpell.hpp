// PSSD
// Week 8 - Q5
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class MagicSpell {
public:
  // Inputs: String representation of an encrypted spell.
  // Outputs: String representation of the actual spell.
  // Decrypts a spell for a wizard.
  string fixTheSpell(string spell);
};

string MagicSpell::fixTheSpell(string spell) {
  // Vars.
  string binary = "";
  string AZ = "";
  string others = "";
  string revAZ = "";
  string spellRes = "";
  int revCount = 0;
  int otherCount = 0;
  // Loop through the string.
  for (int i = 0; i < spell.length(); i++) {
    // A or Z?
    if ((spell[i] == 'A') || (spell[i] == 'Z')) {
      // 1 if its A or Z.
      binary += "1";
      // Add to AZ.
      AZ += spell[i];
    // Others
    } else {
      // 0 if its anything else.
      binary += "0";
      // Add to Others.
      others += spell[i];
    };
  };
  // Reverse AZ.
  for (int x = AZ.length()-1; x >= 0; x--) {
    revAZ += AZ[x];
  };
  // Recreate spell.
  for (int y = 0; y < binary.length(); y++) {
    // AZ or Others?
    if (binary[y] == '1') {
      // Add the reverse AZ to the result.
      spellRes += revAZ[revCount];
      // Up the count to make sure we take from the right position of AZ.
      revCount++;
    } else {
      // Add the others to the result.
      spellRes += others[otherCount];
      // Up the count to make sure we take from the right position of the others string.
      otherCount++;
    };
  };
  // Return the new spell.
  return spellRes;
};
