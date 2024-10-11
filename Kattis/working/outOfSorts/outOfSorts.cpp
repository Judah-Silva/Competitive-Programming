#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n, m, a, c, x0;
  cin >> n >> m >> a >> c >> x0;

  vector<int> sequence;
  sequence.push_back(((a * x0) + c) % m);
  for (int i = 1; i < n; i++) {
    sequence.push_back(((a * sequence[i - 1]) + c) % m);
  }

  sort(sequence.begin(), sequence.end());

  // binary search without searching

  return 0;
}


