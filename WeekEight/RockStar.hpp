// PSSD
// Week 8 - Q4
#include <iostream>
using namespace std;

// Includes.
#include <vector>
#include <sstream>
#include <algorithm>

class RockStar {
public:
  // Inputs: fast fast, fast slow, slow fast, slow slow.
  // Outputs: max number of songs for the album
  // Starts a recursive call to find the number of songs that can fit onto an album.
  int getNumSongs(int ff, int fs, int sf, int ss);
private:
  // Inputs: fast fast, fast slow, slow fast, slow slow, whether fast or slow is a priority.
  // Outputs: max number of songs for the album.
  // Given the number of each type of song written find the max that could fit on an album.
  int getNumSong(int ff, int fs, int sf, int ss, int priority);
};


int RockStar::getNumSongs(int ff, int fs, int sf, int ss) {
  // Do we have any fast songs to start off with?
  if ((ff > 0) || (fs > 0)) {
    return getNumSong(ff, fs, sf, ss, 0);
  } else {
    return getNumSong(ff, fs, sf, ss, 1);
  };
};

int RockStar::getNumSong(int ff, int fs, int sf, int ss, int priority) {
  // Are we prioritising fast songs or slow songs.
  if (priority == 0) {
    // eliminate all of the fast fast songs first. Then move onto the fast slow songs and if the priority comes back
    // to fast with no fast songs left then finish.
    if (ff > 0) {
      return getNumSong(ff-1, fs, sf, ss, 0) + 1;
    } else if (fs > 0) {
      return getNumSong(ff, fs-1, sf, ss, 1) + 1;
    } else {
        return 0;
    };
  } else {
    // eliminate all of the slow slow songs first. Then move onto the slow fast songs and if the priority comes back
    // to slow with no slow songs left then finish.
    if (ss > 0) {
      return getNumSong(ff, fs, sf, ss-1, 1) + 1;
    } else if (sf > 0) {
      return getNumSong(ff, fs, sf-1, ss, 0) + 1;
    } else {
        return 0;
    };
  };
};
