#include <iostream>
#include <set>
using namespace std;

int main() {
  set<int> set;
  int n;
  cin >> n;
  int days1, days2;
  for (int i = 0; i < n; i++) {
    cin >> days1 >> days2;
    for (int i = days1; i <= days2; i++) {
      set.insert(i);
    }
  }

  cout << set.size() << "\n";
  return 0;
}
