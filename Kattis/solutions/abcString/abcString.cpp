#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
  string input;
  cin >> input;

  vector<int> counts(8, 0); // Used to store count of each type of subsequence we have
  int res = 0;
  for (int i = 0; i < input.size(); i++) {
    int c = 1 << (input[i] - 'A'); // Create mask of characters we have
    int neededToFill = c ^ 7; // Create mask of characters we need
    if (counts[neededToFill]) {
      counts[neededToFill]--; // If we have a subsequence that only needs the character we have, then remove it
      counts[7]++;
    } else {
      if (counts[7]) {
        counts[7]--;
        counts[c]++;
      } else if (counts[4] && ((4 & c) == 0)) {
        counts[4]--;
        counts[4 | c]++;
      } else if (counts[2] && ((2 & c) == 0)) {
        counts[2]--;
        counts[2 | c]++;
      } else if (counts[1] && ((1 & c) == 0)) {
        counts[1]--;
        counts[1 | c]++;
      } else {
        counts[c]++;
        res++;
      }
    }
  }


  cout << res << "\n";

  return 0;
}
