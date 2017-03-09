// PSSD
// Week 6 - Q5
#include <iostream>
using namespace std;

class RunLengthEncoding {
public:
  // Inputs: encoded text.
  // Outputs: decoded text.
  // Takes an encoded string and decodes it if its below 50 characters.
  string decode(string text);
};

string RunLengthEncoding::decode(string text) {
  // Vars.
  string currStr = "";
  string resStr = "";
  long counter = 0;
  // Loop through the string.
  for (int i = 0; i < text.length(); i++) {
    // If its a digit add it to the current string.
    if (text[i] > 47 && text[i] < 58) {
      currStr += text[i];
    } else {
      if (currStr.length() > 0) {
        // If not add the currStr to the counter.
        counter += atol(&currStr[0]);
        // If the counter breaks the limit of 50 then return.
        if (counter > 50) {
          return "TOO LONG";
        };
        // Otherwise add that number of the current letters to the resulting string.
        for (int x = 0; x < atoi(&currStr[0]); x++) {
          resStr += text[i];
        };
        // Reset the current string so its ready for the next digits.
        currStr = "";
      } else {
        // Just add the letter and then up the count.
        resStr += text[i];
        counter++;
        // If the counter breaks the limit of 50 then return.
        if (counter > 50) {
          return "TOO LONG";
        };
      };
    };
  };
  // Return the result.
  return resStr;
};
