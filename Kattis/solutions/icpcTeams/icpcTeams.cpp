#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  while (n--) {
    int k;
    cin >> k;
    vector<int> students(3 * k, -1);
    for (int i = 0; i < 3 * k; ++i) {
      cin >> students[i];
    }
    sort(students.begin(), students.end());
    int sum = 0;
    int j = 3 * k - 2;
    while (j >= k) {
      sum += students[j];
      j -= 2;
    }
    cout << sum << "\n";
  }
  return 0;
}
