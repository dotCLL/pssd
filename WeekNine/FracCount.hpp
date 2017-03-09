// PSSD
// Week 9 - Q4
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>
#include <utility>

class FracCount {
public:
  // Inputs: numerator and denominator of a fraction.
  // Outputs: the index in a series that the fraction aligns with.
  // Find where in the series of fractions between 0 and 1 that the reduced fraction sits at.
  int position(int numerator, int denominator);
  // Constructor to create all possible combos of fractions between 0 and 1.
  FracCount();
private:
  // Vector representation of all possible fractions between 0 and 1.
  vector<pair<int, double> > combs;
};

// Sorting structs
struct sortSecond {
    bool operator()(const pair<double,double> &left, const pair<double,double> &right) {
        return left.second < right.second;
    }
};
struct sortFirst {
    bool operator()(const pair<double,double> &left, const pair<double,double> &right) {
        return left.first < right.first;
    }
};

FracCount::FracCount() {
  // Vars.
  vector<pair<int, double> > first;
  vector<pair<int, double> > doubles;
  // Loop through all possible combinations.
  for (double d = 2; d <= 1000; d++) {
    for (double n = 1; n < d; n++) {
      first.push_back(make_pair(first.size()+1, n/d));
    };
  };
  // Sort the vector by value first.
  sort(first.begin(), first.end(), sortSecond());
  // Add first element.
  doubles.push_back(first[0]);
  // Loop through all possible combinations.
  for (int i = 1; i < first.size(); i++) {
    // If it's not equal to the previous element then add the element with the smallest index of all the previous doubles to combs.
    if (first[i].second != first[i-1].second) {
      // sort doubles by index.
      sort(doubles.begin(), doubles.end(), sortFirst());
      // Add first of index to combs.
      combs.push_back(doubles[0]);
      // Reset doubles.
      doubles.clear();
      // Add current element.
      doubles.push_back(first[i]);
    } else {
      // Add to doubles to be checked.
      doubles.push_back(first[i]);
    }
  };
  // sort any left over doubles by index.
  sort(doubles.begin(), doubles.end(), sortFirst());
  // Add first of index to combs.
  combs.push_back(doubles[0]);
  // Lastly sort the combinations by index.
  sort(combs.begin(), combs.end(), sortFirst());
};

int FracCount::position(int numerator, int denominator) {
  // decimal representation of the fraction.
  double n = numerator;
  double d = denominator;
  double dec = (n/d);
  // Loop through combs until the decimal is found.
  for (int i = 0; i < combs.size(); i++) {
    if (dec == combs[i].second) {
      return (i+1);
    };
  };
};
