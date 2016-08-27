// PSSD
// Week 4 - Q3
#include <iostream>
using namespace std;

// includes.
#include <vector>

class UnsealTheSafe {
public:
  // Inputs: maximum combination length.
  // Outputs: total number of combinations.
  // Creates the total number of passwords needed for an N digit combination on a keypad.
  long countPasswords(int N);
private:
  vector<vector<long> > dp;
  vector<long> temp;
  // Inputs: maximum combination length.
  // Outputs: void.
  // Create N * 10 vector matrix and fill the first columns with 1's as applicable for this problem.
  void initVec(int size);
};

long UnsealTheSafe::countPasswords(int N) {
  // Init vec.
  initVec(N);
  // Vars.
  long res = 0;
  // fill the table.
  // first column is filled so start from the second column.
  for (int i = 1; i < N; i++) {
    // Set the latest known combination for the current key press.
    // 0 can only come from 7
    dp[i][0] = dp[i-1][7];
    // 1 can come from 2 and 4.
    dp[i][1] = dp[i-1][2] + dp[i-1][4];
    // 2 can come from 1, 3 and 5.
    dp[i][2] = dp[i-1][1] + dp[i-1][3] + dp[i-1][5];
    // 3 can come from 2 and 6.
    dp[i][3] = dp[i-1][2] + dp[i-1][6];
    // 4 can come from 1, 5 and 7.
    dp[i][4] = dp[i-1][1] + dp[i-1][5] + dp[i-1][7];
    // 5 can come from 2, 4, 6 and 8.
    dp[i][5] = dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8];
    // 6 can come from 3, 5 and 9.
    dp[i][6] = dp[i-1][3] + dp[i-1][5] + dp[i-1][9];
    // 7 can come from 4, 8 and 0.
    dp[i][7] = dp[i-1][4] + dp[i-1][8] + dp[i-1][0];
    // 8 can come from 5, 7 and 9.
    dp[i][8] = dp[i-1][5] + dp[i-1][7] + dp[i-1][9];
    // 9 can come from 6 and 8.
    dp[i][9] = dp[i-1][6] + dp[i-1][8];
  };
  // N-1 will now be the total.
  for (int i = 0; i < 10; i++) {
    res += dp[N-1][i];
  };
  // return result.
  return res;
};

void UnsealTheSafe::initVec(int size) {
  // Clear.
  dp.clear();
  temp.clear();
  // Loop
  for (int x = 0; x < size; x++) {
    for (int y = 0; y < 10; y++) {
      if (x == 0) {
        temp.push_back(1);
      } else {
        temp.push_back(-1);
      };
    };
    // Add to vec.
    dp.push_back(temp);
    // Clear temp.
    temp.clear();
  };
};
