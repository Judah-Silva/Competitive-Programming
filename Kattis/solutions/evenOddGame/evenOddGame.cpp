#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
  int t;
  cin >> t;

  while (t > 0) {
    int n;
    cin >> n;

    priority_queue<int> input;
    for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      input.push(num);
    }
    
    bool aliceTurn = true;
    long long int alice = 0;
    long long int bob = 0;

    while (!input.empty()) {
      if (aliceTurn) {
        if (input.top() % 2 == 0) alice += input.top();
        input.pop();
      } else {
        if (input.top() % 2 != 0) bob += input.top();
        input.pop();
      }
      aliceTurn = !aliceTurn;
    }

    // Print out Alice, Bob, or Tie depending on the outcome of the game
    alice > bob ? cout << "Alice\n" : (alice == bob ? cout << "Tie\n" : cout << "Bob\n");
    t--;
  }
  return 0;
}
