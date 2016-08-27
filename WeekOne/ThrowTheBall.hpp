// PSSD
// Week 1 - Q5
#include <iostream>
using namespace std;

// Includes
#include <vector>

class ThrowTheBall {
public:
  // Inputs:	number of friends, received ball cutoff, pass length. 
  // Outputs:	number of passes.
  // Simulates some friends throwing a ball around. 
  int timesThrown(int N, int M, int L);
};

int ThrowTheBall::timesThrown(int N, int M, int L) {
  // Vars.
  int passes = 0;
  int currentPlayer = 0;
  int currMax = 0;
  vector<int> playersPossession(N, 0);

  // While the current max is less than the max amount of possessions allowed keep passing.
  while (currMax < M) {
    // Up the amount of possessions for the current player.
    playersPossession[currentPlayer]++;
    // Set the current max. If it's over the specified maximum allowed then finish looping.
    if (currMax < playersPossession[currentPlayer]) {
      currMax = playersPossession[currentPlayer];
      if (currMax >= M) {
        break;
      };
    };
    // Decide who to pass to next.
    if ((playersPossession[currentPlayer] % 2) != 0) {
      currentPlayer -= L;
      // Negative?
      if (currentPlayer < 0) {
        currentPlayer = (N + currentPlayer);
      };
    } else {
      currentPlayer += L;
      // Too far?
      if (currentPlayer > (N-1)) {
        currentPlayer = (currentPlayer - N);
      };
    };
    // Pass the ball to the next player.
    passes++;
  };
  // Return the number of passes made once the game has finished.
  return passes;
};
