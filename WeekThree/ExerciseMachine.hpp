// PSSD
// Week 3 - Q5
#include <iostream>
using namespace std;

// Includes.
#include <sstream>
#include <iomanip>

class ExerciseMachine {
public:
  // Inputs: string representation of a particular time.
  // Outputs: number of times a percentage will be displayed.
  // Calculates how many times a perfectly whole percentage of the time can be shown on a screen for a given time.
  int getPercentages(string time);
private:
  // Inputs: string representation of a particular time.
  // Outputs: an integer relating to the number of seconds of that time.
  // Returns the total number of seconds for a given hour:minutes:seconds string representation.
  int convertToSecs(string time);
};

int ExerciseMachine::getPercentages(string time) {
  // vars.
  double totalSecs = convertToSecs(time);
  int shownPercents = 0;
  double calcPercent;
  string percStr;
  // Loop through and check percentage each second.
  for (double i = 0; i < totalSecs; i++) {
    // check the percentage.
    calcPercent = (i / totalSecs) * 100;
    // Convert to string.
    ostringstream cs;
    cs << setprecision(10) << calcPercent;
    percStr = cs.str();
    // If its a whole number and not equal to 0 or 100 then up the count as it would be shown.
    if (((calcPercent < 10) && (percStr.length() == 1)) || ((calcPercent >= 10) && (percStr.length() == 2))) {
      if ((calcPercent != 0) && (calcPercent != 100)) {
        shownPercents++;
      };
    };
  };
  // Return
  return shownPercents;
};

// Converts the given time to an integer representing the total number of seconds.
int ExerciseMachine::convertToSecs(string time) {
  // vars.
  string hrs = "";
  hrs += time[0];
  hrs += time[1];
  string mins = "";
  mins += time[3];
  mins += time[4];
  string secs = "";
  secs += time[6];
  secs += time[7];
  // Return hours plus mins plus seconds.
  return ((3600 * atoi(&(hrs[0]))) + (60 * atoi(&(mins[0]))) + (atoi(&(secs[0]))));
}
