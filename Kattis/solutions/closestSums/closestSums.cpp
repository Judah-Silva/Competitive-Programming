#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n, caseNum = 1;
  while (cin >> n) {
    int m;
    vector<int> input(n);
    for (int i = 0; i < n; i++) {
      cin >> input[i];
    }

    sort(input.begin(), input.end());

    cout << "Case " << caseNum++ << ":\n";

    cin >> m;
    for (int i = 0; i < m; i++) {
      int query, closestSum = -1e9;
      cin >> query;

      for (int j = 0; j < n - 1; j++) {
        for (int k = j + 1; k < n; k++) {
          if (abs(input[j] + input[k] - query) < abs(closestSum - query)) {
            closestSum = input[j] + input[k];
          }
        }
      }

      cout << "Closest sum to " << query << " is " << closestSum << ".\n";
    }
  }

  return 0;
}
