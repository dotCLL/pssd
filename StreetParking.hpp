// PSSD
// StreetParking practice question 03
#include <iostream>
using namespace std;

// Includes
#include <string>


class StreetParking {
public:
  static int freeParks(string street);
};

int StreetParking::freeParks(string street) {
  // Vars
  int numOfFreeParks = 0;
  bool count = true;
  // Loop through string
  for (int i = 0; i < street.length(); i++) {
    // Check for 10 metres before a bus stop, or 5 metres before a bus stop / side-street, or 5 metres after a side-street.
    if (i < (street.length() - 2)) {
      // Is bus stop?
      if ((street[(i+1)] == 'B') || (street[(i+2)] == 'B')) {
        count = false;
      };
    };
    if (i < (street.length() - 1)) {
      // Is side-street or bus stop?
      if ((street[(i+1)] == 'S') || (street[(i+1)] == 'B')) {
        count = false;
      };
    };
    if (i > 0) {
      // Is side-street?
      if ((street[(i-1)]) == 'S') {
        count = false;
      };
    };
    // Directly infront of a driveway / bus stop / side-street?
    if ((street[i] == 'D') || (street[i] == 'B') || (street[i] == 'S')) {
      count = false;
    };
    // If none of the conditions cancel the count the it is a free parking space.
    if (count) {
      // cout << "freepark at index: " << i << " *** " << "|" << street[i-1] << "|*" << street[i] << "|" << street[i+1] << "|" << street[i+2] << endl;
      numOfFreeParks++;
    };
    // Reset count;
    count = true;
  };
  // Return the count.
  return numOfFreeParks;
};
