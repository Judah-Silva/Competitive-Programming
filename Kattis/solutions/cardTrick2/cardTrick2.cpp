#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<list<int>> res;
  for (int i = 1; i <= 13; i++) { // Generate all answers
    list<int> list;
    for (int j = i; j > 0; j--) {
      list.push_front(j);
      for (int k = 0; k < j; k++) {
        int temp = list.back();
        list.pop_back();
        list.push_front(temp);
      }
    }
    res.push_back(list);
  }

  for (int i = 0; i < n; i++) {
    int query;
    cin >> query;

    for (auto& num : res[query - 1]) {
      cout << num << " ";
    }
    cout << "\n";
  }

  return 0;
}
