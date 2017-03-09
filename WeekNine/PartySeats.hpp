// PSSD
// Week 9 - Q1
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>


class PartySeats {
public:
  // Inputs: a vector representation of some assignments and there pleasantness.
  // Outputs: an integer representing the number of problems that were solved.
  // Finds the minimum number of problems to solve to keep a teacher happy.
  vector<string> seating(vector<string> attendees);
};

vector<string> PartySeats::seating(vector<string> attendees) {
  // break cases.
  if (attendees.size() % 2 != 0) {
    return vector<string>();
  } else if ((attendees.size()/2) % 2 != 0) {
    return vector<string>();
  };
  // vars.
  vector<string> boys;
  vector<string> girls;
  vector<string> result;
  int boysIndex = 0;
  int girlsIndex = 0;
  bool addGirlNext = true;
  // Loop through attendees and parse into the vectors.
  for (int i = 0; i < attendees.size(); i++) {
    string name = "";
    // Get name.
    for (int x = 0; x < attendees[i].length(); x++) {
      if (attendees[i][x] == ' ') {
        break;
      } else {
        name += attendees[i][x];
      };
    };
    // boy or girl?
    if (attendees[i][attendees[i].length()-1] == 'y') {
      boys.push_back(name);
    } else {
      girls.push_back(name);
    };
  };
  // Match up?
  if (boys.size() != girls.size()) {
    return vector<string>();
  }
  // Sort boys and girls vectors.
  sort(boys.begin(), boys.end());
  sort(girls.begin(), girls.end());
  // Loop through the boys and girls.
  for (int i = 0; i < (boys.size()*2); i++) {
    // start
    if (i == 0) {
      result.push_back("HOST");
      result.push_back(girls[girlsIndex]);
      addGirlNext = false;
      girlsIndex++;
    } else if (i == boys.size()) {
      // Hostess in the middle.
      result.push_back("HOSTESS");
      result.push_back(boys[boysIndex]);
      addGirlNext = true;
      boysIndex++;
    } else {
      // Alternate at the correct indexes otherwise.
      if (addGirlNext) {
        result.push_back(girls[girlsIndex]);
        addGirlNext = false;
        girlsIndex++;
      } else {
        result.push_back(boys[boysIndex]);
        addGirlNext = true;
        boysIndex++;
      };
    };
  };
  // Return the resulting vector.
  return result;
};
