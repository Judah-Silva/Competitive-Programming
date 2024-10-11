#include <iostream>
#include <set>
using namespace std;

int main() {
  set<string> set;

  string word;
  while (cin >> word) {
    if (set.count(word)) {
      cout << "no";
      return 0;
    }
    set.insert(word);
  }

  cout << "yes";
  return 0;
}
