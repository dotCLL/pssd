// PSSD
// Week 10 - Q1
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <algorithm>

class BridgeSort {
public:
  // Inputs: String representation of a hand of cards.
  // Outputs: String representation of a sorted hand of cards.
  // Sorts a hand of cards in order of Clubs, Diamonds, Hearts then Spades.
  string sortedHand(string hand);
};

string BridgeSort::sortedHand(string hand) {
  // Vars.
  vector<string> pairs;
  string result = "";
  // Loop through string and add pairs to vector.
  for (int i = 0; i < hand.length(); i+=2) {
    // change suit?
    if (hand[i+1] == 'T') {
      hand[i+1] = 'A';
    } else if (hand[i+1] == 'J') {
      hand[i+1] = 'B';
    } else if (hand[i+1] == 'Q') {
      hand[i+1] = 'C';
    } else if (hand[i+1] == 'K') {
      hand[i+1] = 'D';
    } else if (hand[i+1] == 'A') {
      hand[i+1] = 'E';
    };
    // temp.
    string temp = "";
    temp += hand[i];
    temp += hand[i+1];
    // add to pairs.
    pairs.push_back(temp);
  };
  // Sort the vector.
  sort(pairs.begin(), pairs.end());
  // Add to the resulting string.
  for (int i = 0; i < pairs.size(); i++) {
    // change suit?
    if (pairs[i][1] == 'A') {
      pairs[i][1] = 'T';
    } else if (pairs[i][1] == 'B') {
      pairs[i][1] = 'J';
    } else if (pairs[i][1] == 'C') {
      pairs[i][1] = 'Q';
    } else if (pairs[i][1] == 'D') {
      pairs[i][1] = 'K';
    } else if (pairs[i][1] == 'E') {
      pairs[i][1] = 'A';
    };
    // Add to resulting string.
    result += pairs[i];
  };
  // Return the result.
  return result;
};
