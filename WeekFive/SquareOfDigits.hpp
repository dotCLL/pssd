// PSSD
// Week 5 - Q2
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm> // min.
#include <cmath> // pow.


class SquareOfDigits {
public:
  // Inputs: matrix of data.
  // Outputs: number respresenting the area of the biggest square.
  // Given a matrix of numbers find the largest square of numbers with corners all equaling the same number.
  int getMax(vector<string> data);
};

int SquareOfDigits::getMax(vector<string> data) {
  // Set max to default.
  int max = 1;
  // Loop through the vector.
  for (int x = 0; x < data.size(); x++) {
    for (int y = 0; y < data[x].length(); y++) {
      // set the origin digit to search for.
      char orig = data[x][y];
      // cout << "****" << orig << endl;
      // Loop up to the end of the matrix.
      for (int i = 1; i < min(data[x].length()-y, data.size()-x); i++) {
        // Vars.
        char origRight = data[x][y+i];
        char origDiag = data[x+i][y+i];
        char origDown = data[x+i][y];
        // If they are all equal calculate the area.
        if (orig == origRight && origRight == origDiag && origDiag == origDown) {
          // area.
          int area = pow((((x+i) - x)+1), 2);
          // Change max.
          if (area > max) {
            max = area;
          };
        };
      };
    };
  };
  // Return the max.
  return max;
};
