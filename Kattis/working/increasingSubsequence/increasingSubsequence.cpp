#include <iostream>
#include <vector>
using namespace std;

int memo[201];

int LIS(vector<int>& input, int i) {
  if (i == 0) return 1;
  int& ans = memo[i];
  if (ans != -1) return ans;
  ans = 1;
  for (int j = 0; j < i; j++) {
    if (input[i] < input[j]) {
      ans = max(ans, LIS(input, j) + 1);
    }
  }

  return ans;
}

int main() {

  
  return 0;
}
