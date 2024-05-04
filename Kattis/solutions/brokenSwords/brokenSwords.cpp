#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int topBottom = 0;
  int leftRight = 0;
  
  while (n--) {
    string sword;
    cin >> sword;
    // cout << sword;
    for (int i = 3; i >= 0; --i) {
      if (i >= 2) {
        sword[i] == '0' ? leftRight += 1 : leftRight = leftRight;
      } else {
        sword[i] == '0' ? topBottom += 1 : topBottom = topBottom;
      }
      // cout << sword << "\n";
    }
  }

  // cout << topBottom << " " << leftRight << "\n";
  int totalSwords = min(topBottom / 2, leftRight / 2);

  cout << totalSwords << " " << topBottom - (totalSwords * 2) << " " << leftRight - (totalSwords * 2);
  return 0;
}
