// PSSD
// Week 6 - Q2
#include <iostream>
using namespace std;

// Includes.
#include <algorithm>


class BlackAndWhiteSolitaire {
public:
  // Inputs: string representation of a set of cards
  // Outputs: number of swaps needed for perfect combination.
  // Given a set of cards flip the cards so that they are in alternating order and keep a count of the number of flips needed.
  int minimumTurns(string cardFront);
  // Inputs: two strings and an integer representing their length.
  // Outputs: void.
  // Will set two strings to be an alternating sequence starting with W for string a and starting with B for string b.
  void constString(string &a, string &b, int len);
};

int BlackAndWhiteSolitaire::minimumTurns(string cardFront) {
  // vars
  string a = "";
  string b = "";
  int aCount = 0;
  int bCount = 0;
  // Construct alternating strings.
  constString(a, b, cardFront.length());
  // Loop through the length of the string and count the number of different characters from the two alternating strings.
  for (int i = 0; i < cardFront.length(); i++) {
    if (a[i] != cardFront[i]) {
      aCount++;
    };
    if (b[i] != cardFront[i]) {
      bCount++;
    };
  };
  // return the minimum number of the counts which represents the minimum number of swaps needed.
  return min(aCount, bCount);
};


void BlackAndWhiteSolitaire::constString(string &a, string &b, int len) {
  // Loop through to length.
  for (int i = 1; i <= len; i++) {
    // Alternate and create the strings.
    if ((i % 2) == 0) {
      a += 'B';
      b += 'W';
    } else {
      a += 'W';
      b += 'B';
    }
  };
};
