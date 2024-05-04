#include <iostream>
using namespace std;

int main() {
  int n, s, largestTime = 0;
  cin >> n >> s;
  
  for (int i = 0; i < n; ++i) {
    int time;
    cin >> time;
    largestTime = max(largestTime, time);
  }

  cout << ((largestTime * s) / 1000) + ((largestTime * s) % 1000 == 0) << "\n";
  return 0;
}
