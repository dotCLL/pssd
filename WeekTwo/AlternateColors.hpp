// PSSD
// Week 2 - Q2.
#include <iostream>
using namespace std;

// Includes
#include <algorithm>
#include <utility>

class AlternateColors {
public:
  string getColor(long r, long g, long b, long k);
};

string AlternateColors::getColor(long r, long g, long b, long k) {
  // cout << "0" << endl;
  // vars.
  long smallest;
  long nMin;
  bool red0 = false;
  bool green0 = false;
  bool blue0 = false;
  // Set bools.
  if (r == 0) { red0 = true; };
  if (g == 0) { green0 = true; };
  if (b == 0) { blue0 = true; };
  // Set smallest and nMin.
  if (!red0 && !green0 && !blue0) {
    smallest = min(r, min(g, b));
    nMin = (3 * smallest);
  } else if (red0 && !green0 && !blue0) {
    smallest = min(g, b);
    nMin = (2 * smallest);
  } else if (!red0 && !green0 && blue0) {
    smallest = min(g, r);
    nMin = (2 * smallest);
  } else if (!red0 && green0 && !blue0) {
    smallest = min(r, b);
    nMin = (2 * smallest);
  } else if (red0 && green0 && !blue0) {
    return "BLUE";
  } else if (red0 && !green0 && blue0) {
    return "GREEN";
  } else if (!red0 && green0 && blue0) {
    return "RED";
  } else {
    return "ALL ZERO";
  };
  // cout << "1" << "small: " << smallest << " nMin: " << nMin << endl;
  // Handle K.
  if ((k - nMin) <= 0) {
    // cout << "2" << endl;
    // Simulate counting each down using mod depending on the number of colours remaining.
    if (!red0 && !green0 && !blue0) {
      // mod 3 then return the right colour.
      if (k % 3 == 0) { return "BLUE"; }
      else if (k % 3 == 1) { return "RED"; }
      else if (k % 3 == 2) { return "GREEN"; }
      else { return "LINE 45"; };
    } else if (red0 && !green0 && !blue0) {
      // mod 2 then return the right colour.
      if (k % 2 == 0) { return "BLUE"; }
      else if (k % 2 == 1) { return "GREEN"; }
      else { return "LINE 50"; };
    } else if (!red0 && !green0 && blue0) {
      // mod 2 then return the right colour.
      if (k % 2 == 0) { return "GREEN"; }
      else if (k % 2 == 1) { return "RED"; }
      else { return "LINE 55"; };
    } else if (!red0 && green0 && !blue0) {
      // mod 2 then return the right colour.
      if (k % 2 == 0) { return "BLUE"; }
      else if (k % 2 == 1) { return "RED"; }
      else { return "LINE 50"; };
    } else if (red0 && green0 && !blue0) {
      // only 1 left.
      return "BLUE";
    } else if (red0 && !green0 && blue0) {
      // only 1 left.
      return "GREEN";
    } else if (!red0 && green0 && blue0) {
      // only 1 left.
      return "RED";
    } else {
      return "ALL ZERO";
    };
  } else {
    // cout << "3" << endl;
    // cout << r << "***" << g << "***" << b << "***" << k << endl;
    // Handles negative balls.
    if ((r-smallest) < 0) {
      // cout << "r-smallest" << endl;
      if (g == b) {
        if (g % 2 == 0) {
          return "BLUE";
        } else {
          return "GREEN";
        }
      } else if (g < b) {
        return "BLUE";
      } else {
        return "GREEN";
      };
    } else if ((g-smallest) < 0) {
      // cout << "g-smallest" << endl;
      if (r == b) {
        if (r % 2 == 0) {
          return "BLUE";
        } else {
          return "RED";
        }
      } else if (r < b) {
        return "BLUE";
      } else {
        return "RED";
      };
    } else if ((b-smallest) < 0) {
      // cout << "b-smallest" << endl;
      if (g == r) {
        if (g % 2 == 0) {
          return "GREEN";
        } else {
          return "RED";
        }
      } else if (g < r) {
        return "RED";
      } else {
        return "GREEN";
      };
    } else {
      // Recur
      return getColor(r-smallest, g-smallest, b-smallest, k-nMin);
    };
  };
};
