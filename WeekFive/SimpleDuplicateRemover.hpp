// PSSD
// Week 5 - Q3
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <stack>


class SimpleDuplicateRemover {
public:
  // Inputs: sequence of digits.
  // Outputs: vector of duplicates the new sequence.
  // Given a sequence of numbers remove the duplicates leaving the order the same.
  vector<int> process(vector<int> v1);
};

vector<int> SimpleDuplicateRemover::process(vector<int> v1) {
  // Vars.
  stack<int> st;
  vector<int> res;
  // Create digit count array.
  int digCount[1001] = {0};
  // Loop through v1 from the left.
  for (int i = v1.size()-1; i >= 0; i--) {
    // If dig count is < 1 add to the stack.
    if (digCount[v1[i]] < 1) {
      st.push(v1[i]);
    };
    // Up count.
    digCount[v1[i]]++;
  };
  // Set size.
  int size = st.size();
    // Fill result.
  for (int i = 0; i < size; i++) {
    res.push_back(st.top());
    st.pop();
  };
  // Return the vector.
  return res;
};
