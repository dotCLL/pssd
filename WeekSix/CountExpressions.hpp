// PSSD
// Week 6 - Q4
#include <iostream>
using namespace std;

class CountExpressions {
public:
  // Inputs: two integers and the value they have to equal.
  // Outputs: an integer representing the total number of combinations of a particular equation.
  // Returns the number of combinations that equal a sum by multiplying, adding, subtracting or dividing in any possible order.
  int calcExpressions(int x, int y, int val);
  // Inputs: two integers and the value they have to equal.
  // Outputs: a vector of vectors of integers for all of the combinations of x and y.
  // Return the combinations of x and y.
  vector<vector<int> > constXY(int x, int y);
};

vector<vector<int> > CountExpressions::constXY(int x, int y) {
  // Vars.
  vector<vector<int> > comb;
  // Push into vector.
  int a1[4] = {x, x, y, y};
  vector<int> v1(&a1[0], &a1[0]+4);
  comb.push_back(v1);
  int a2[4] = {y ,y ,x, x};
  vector<int> v2(&a2[0], &a2[0]+4);
  comb.push_back(v2);
  int a3[4] = {x, y, x, y};
  vector<int> v3(&a3[0], &a3[0]+4);
  comb.push_back(v3);
  int a4[4] = {y, x, y, x};
  vector<int> v4(&a4[0], &a4[0]+4);
  comb.push_back(v4);
  int a5[4] = {x, y, y, x};
  vector<int> v5(&a5[0], &a5[0]+4);
  comb.push_back(v5);
  int a6[4] = {y, x, x, y};
  vector<int> v6(&a6[0], &a6[0]+4);
  comb.push_back(v6);
  // Return vector.
  return comb;
}

int CountExpressions::calcExpressions(int x, int y, int val) {
  // vars.
  int a = 0;
  int b = 0;
  int c = 0;
  long r1;
  long r2;
  long r3;
  int res = 0;
  // Construct vector of possible combos of x and y.
  vector<vector<int> > combos = constXY(x, y);
  // calculate all of the equations possible.
  for (int i = 0; i < combos.size(); i++) {
    // reset a, b, c;
    a = 0;
    b = 0;
    c = 0;
    // Calculate the equations.
    while (true) {
      // Calculate the equation accordingly.
      switch(a) {
        case 0:
          r1 = combos[i][0] * combos[i][1];
          break;
        case 1:
          r1 = combos[i][0] + combos[i][1];
          break;
        case 2:
          r1 = combos[i][0] - combos[i][1];
          break;
      };
      switch(b) {
        case 0:
          r2 = r1 * combos[i][2];
          break;
        case 1:
          r2 = r1 + combos[i][2];
          break;
        case 2:
          r2 = r1 - combos[i][2];
          break;
      };
      switch(c) {
        case 0:
          r3 = r2 * combos[i][3];
          break;
        case 1:
          r3 = r2 + combos[i][3];
          break;
        case 2:
          r3 = r2 - combos[i][3];
          break;
      };
      // If its a correct result add to the count.
      if (r3 == val) {
        res++;
      };
      // reset temp results.
      r1 = 0;
      r2 = 0;
      r3 = 0;
      // Up the counts to create the correct equations.
      // Up c count.
      c++;
      if (c > 2) {
        // If c count is too big up b count and then reset c count.
        c = 0;
        b++;
        if (b > 2) {
          // if b count is too big up a count and reset b count.
          b = 0;
          a++;
          // break.
          if (a == 3) {
            break;
          };
        };
      };
    };
  };
  // Return the result.
  return res;
}
