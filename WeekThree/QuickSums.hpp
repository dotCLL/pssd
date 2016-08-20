// PSSD
// Week 3 - Q2.
#include <iostream>
using namespace std;

// Includes.
#include <cstdlib>
#include <string>
#include <bitset>
#include <vector>
#include <cmath>
#include <algorithm>

class QuickSums {
public:
  int minSums(string numbers, int sum);
private:
  int calculateInt(string str, int sums);
  void fillBins(int n);
  vector<string> bins;
  vector<int> plussesVec;
};

// Calculates the minimum number of + symbols needed to achieve a particular sum.
int QuickSums::minSums(string numbers, int sum) {
  // Clear vecs.
  bins.clear();
  plussesVec.clear();
  // fill bins.
  fillBins(numbers.length()-1);
  // Sum string.
  string sumStr = "";
  // Loop through the combinations.
  for (int x = 0; x < bins.size(); x++) {
    for (int y = 0; y < bins[x].length(); y++) {
      // Add first digit.
      sumStr += numbers[y];
      // add a plus symbol if needed.
      if (bins[x][y] == '1') {
        sumStr += '+';
      };
    };
    // Finish off the string.
    sumStr += numbers[numbers.length()-1];
    // Current combination.
    int currentCombination = calculateInt(sumStr, sum);
    // If this combination is equal to the sum then add its number of plusses to the plusses vector.
    if (currentCombination != -1) {
      plussesVec.push_back(currentCombination);
    };
    // Reset sumStr.
    sumStr = "";
  };
  // If there are any possible combinations then return the minimum of the number of plusses otherwise return -1.
  if (plussesVec.size() > 0) {
    return *min_element(plussesVec.begin(), plussesVec.end());
  } else {
    return -1;
  };
};

// All possible binary combinations of plusses
void QuickSums::fillBins(int n) {
  for (int i = 0; i < (pow(2,n)); i++) {
    string bin10 = bitset<10>(i).to_string();
    bins.push_back(bin10.substr((bin10.length()-n), bin10.length()));
  };
};

// Calculates the sum of the given string and also the number of plusses in the string.
int QuickSums::calculateInt(string str, int sums) {
  // holder.
  string sum = "";
  int total = 0;
  int plusses = 0;
  vector<int> combo;
  // Loops
  for (int i = 0; i < str.length(); i++) {
    if (str[i] != '+') {
      sum += str[i];
    } else {
      combo.push_back(atoi(&sum[0]));
      sum = "";
      plusses++;
    }
  };
  // add last sum.
  combo.push_back(atoi(&sum[0]));
  // Calculate total.
  for (int i = 0; i < combo.size(); i++) {
    total += combo[i];
  }
  // return.
  if (total == sums) {
    return plusses;
  } else {
    return -1;
  };
};
