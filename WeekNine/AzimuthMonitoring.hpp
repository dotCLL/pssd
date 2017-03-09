// PSSD
// Week 9 - Q3
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class AzimuthMonitoring {
public:
  // Inputs: vector of strings of instructions.
  // Outputs: an integer representing the degrees that the robot is facing.
  // Finds out which direction in degrees a robot is facing.
  int getAzimuth(vector<string> instructions);
private:
  // Inputs: string representation of an instruction.
  // Outputs: the number of degrees to move.
  // Parses an instruction for the robot.
  int parse(string inst);
};

int AzimuthMonitoring::getAzimuth(vector<string> instructions) {
  // Vars.
  int azi = 0;
  // Loop through the instructions.
  for (int i = 0; i < instructions.size(); i++) {
    // Parse instruction
    int deg = parse(instructions[i]);
    // Time to exit?
    if (deg == 181) {
      return azi;
    };
    // Add degrees.
    azi += deg;
    // Out of ranges?
    if (azi > 359) {
      azi -= 360;
    };
    if (azi < 0) {
      azi += 360;
    };
  };
  // Return result.
  return azi;
};

int AzimuthMonitoring::parse(string inst) {
  // Vars.
  string temp = "";
  bool negative;
  int degrees = -1;
  // Loop through the string.
  for (int i = 0; i < inst.length(); i++) {
    // whitespace?
    if (inst[i] == ' ') {
      // turn?
      if (temp == "TURN") {
        return 180;
      } else if (temp == "LEFT") {
        negative = true;
        temp = "";
      } else {
        negative = false;
        temp = "";
      };
    } else {
      temp += inst[i];
    };
  };
  // time to stop?
  if (temp == "HALT") {
    return 181;
  };
  // Left or right?
  if (temp == "LEFT") {
    return -90;
  };
  if (temp == "RIGHT") {
    return 90;
  };
  // Otherwise set degrees.
  degrees = atoi(&temp[0]);
  // Negative?
  if (negative) {
    degrees -= (2 * degrees);
  };
  // Return result.
  return degrees;
};
