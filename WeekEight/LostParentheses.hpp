// PSSD
// Week 7 - Q1
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <climits>
#include <utility>
#include <algorithm>

class LostParentheses {
public:
  // Inputs: string representation of a mathematical expression.
  // Outputs: the minimum possible outcome of the expression.
  // Creates a vector representation of an expression to calculate the minimum value possible.
  int minResult(string e);
private:
  // Inputs: string representation of a mathematical expression.
  // Outputs: void.
  // Separates integers from operators and adds them to passed vectors.
  void vectorRep(string e, vector<int> &nums, vector<string> &ops);
  // Inputs: first number, second number, the operator for the calculation.
  // Outputs: The result of the calculation.
  // Depending on the operator return either the addition or subtraction of two numbers.
  long calc(int a, int b, char op);
};

void LostParentheses::vectorRep(string e, vector<int> &nums, vector<string> &ops) {
  // Vars.
  string temp = "";
  // loop through string.
  for (int i = 0; i < e.length(); i++) {
    // operator?
    if (e[i] == '+' || e[i] == '-') {
      // Convert temp to integer.
      int tempInt = atoi(&temp[0]);
      // Add integer to expression.
      nums.push_back(tempInt);
      // Reset temp.
      temp = "";
      // Set to operator
      temp += e[i];
      // Add operator to expression.
      ops.push_back(temp);
      // Reset temp.
      temp = "";
    } else {
      temp += e[i];
    };
  };
  // Convert temp to integer.
  int tempInt = atoi(&temp[0]);
  // Add last integer to expression.
  nums.push_back(tempInt);
};

long LostParentheses::calc(int a, int b, char op) {
  // Add or Subtract?
  if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    cout << "How did it get here?" << endl;
    return 0;
  };
};

int LostParentheses::minResult(string e) {
  // Vars.
  vector<int> numbers;
  vector<string> operators;
  int n;
  // Construct vector representations from the string.
  vectorRep(e, numbers, operators);
  // Set number of numbers.
  n = numbers.size();
  // Create DP table full of zeros.
  vector<vector<int> > DPTable(n, vector<int>(n));
  // Fill the diagonals with the numbers.
  for (int i = 0; i < n; i++) {
    DPTable[i][i] = numbers[i];
  };
  // Loop through to fill the diagonals. Starts at 1 as the first diagonal is already filled with the original numbers
  for (int diag = 1; diag < n; diag++) {
    // Setup i and j indexes in the table. i will loop n times minus what iteration we are on in the diagonal as each
    // diagonal row gets shorter by 1.
    for (int i = 0; i < (n - diag); i++) {
      // j is then set to be the location of the current diagonal + the level of i that we're on.
      int j = diag + i;
      // Set the minimum to the climits integer max.
      long minimum = INT_MAX;
      // Do all possible calculations from table data.
      // Just calculates between the span of the gap between i and j.
      for (int index = i; index < j; index++) {
        // cout << "i: " << i << " j: " << j << " index: " << index << " op: " << operators[index] << " op+1: " << operators[index+1] << endl;
        // Get operator.
        char oper = operators[index][0];
        // Calculate the result.
        long res = calc(DPTable[i][index], DPTable[index+1][j], oper);
        // Set the minimum to be the minimum of either itself or this new calculation so that we always get the minimum result.
        // cout << min(res, minimum) << endl;
        minimum = min(res, minimum);
      };
      // Once the minimum is finished being calculated set that as the result for this entry to the table.
      DPTable[i][j] = minimum;
    };
  };
  // the minimum will be the last possible result IE the top right hand corner of the table.
  return DPTable[0][n-1];
};
