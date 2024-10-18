#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t) {
    int n;
    cin >> n;

    map<string, int> frequency;
    for (int i = 0; i < n; i++) {
      string toy;
      int num;
      cin >> toy >> num;

      frequency[toy] += num;
    }

    map<int, set<string>> res;
    for (auto& pair : frequency) {
      res[pair.second].insert(pair.first);
    }

    cout << frequency.size() << "\n";
    for (auto it = res.rbegin(); it != res.rend(); it++) {
      auto& keyValue = *it;
      for (auto& s : keyValue.second) {
        cout << s << " " << keyValue.first << "\n";
      }
    }

    t--;
  }

  return 0;
}
