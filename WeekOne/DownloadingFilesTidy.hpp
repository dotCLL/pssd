// PSSD
// Week 1 - Q2
#include <iostream>
using namespace std;

// Includes.
#include <vector> // Vector
#include <utility> // Pair
#include <sstream> // StringStream
#include <algorithm> // Sort

class DownloadingFiles {
public:
  // Inputs: a vector holding strings representing files to be downloaded.
  // Outputs: total download time.
  // Computes the total download time of a set of files.
  double actualTime(vector<string> v);
private:
  // Vars
  vector<pair<double, double> > pairs;
  // Prototypes
  void fillPairs(vector<string> v);
  // Needs to be static to get rid of the implied this standard input parameter
  // Otherwise the sort function doesn't know what to do with the passed object parameter.
  static bool compare(const pair<double,double> &a,const pair<double,double> &b);
};

// Fills the pairs vector with the given data.
void DownloadingFiles::fillPairs(vector<string> v) {
  // Vars
  double _speed;
  double _time;
  // Loop through the length of the vector.
  for (int i = 0; i < v.size(); i++) {
    // Set up the stringstream
    stringstream ss(v[i]);
    // Split first data node to the speed string
    ss >> _speed;
    // Split second data node to the time string
    ss >> _time;
    // Push back the pair to the Pairs vector
    pairs.push_back(make_pair(_speed, _time));
  };
};

// Compare two elements in a pair.
bool DownloadingFiles::compare(const pair<double,double> &a,const pair<double,double> &b) {
  // Return whether a is less than b.
  return ( a.second < b.second );
};

// Computes the total download time of a set of files.
double DownloadingFiles::actualTime(vector<string> v) {
  // Vars
  double totalSeconds;
  // Fill the pairs vector.
  fillPairs(v);
  // Sort the pairs vector according to the second element in the pair.
  sort(pairs.begin(), pairs.end(), compare);
  // Loop through the vector.
  for (int i = 0; i < pairs.size(); i++) {
    // Add time remaining to totalSeconds.
    totalSeconds += pairs[i].second;
    // If there is another element then change update its attributes.
    if (i != (pairs.size() - 1)) {
      // Minus the current time off of the rest of the vector.
      for (int x = (i+1); x < pairs.size(); x++) {
        // Old_Remaining_Time = current time - previous elements time.
        pairs[(x)].second -= pairs[i].second;
        // Error handle for negative numbers.
        if ( (pairs[(x)].second) < 0 ) {
            // If its less than zero just set it to zero.
            pairs[(x)].second = 0;
        };
      };
      // New time remaining is Old_Remaining_Time * Old_Speed / New_Speed.
      pairs[(i+1)].second = ( (pairs[(i+1)].second) * (pairs[(i+1)].first) ) / ( (pairs[(i+1)].first) + (pairs[i].first) );
      // New bandwidth is new element bandwidth plus current element bandwidth.
      pairs[(i+1)].first += pairs[i].first;
    };
  };
  // Return the time remaining.
  return totalSeconds;
};
