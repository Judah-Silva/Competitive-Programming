#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

vector<string> splitLine(string line) {
  stringstream ss(line);

  string token = "";
  vector<string> result;

  while (getline(ss, token, ' ')) {
    result.push_back(token);
  }

  return result;
}

int main() {
  int ordersToday;
  cin >> ordersToday;
  cin.ignore();
  while (ordersToday != 0) {
    map<string, set<string>> map;
    for (int i = 0; i < ordersToday; i++) {
      string line;
      getline(cin, line);
      vector<string> words = splitLine(line);
      for (int j = 1; j < words.size(); j++) {
        map[words[j]].insert(words[0]);
      }
    }

    for (auto [food, names] : map) {
      cout << food;
      for (auto name : names) {
        cout << " " << name;
      }
      cout << "\n";
    }
    cout << "\n";
    cin >> ordersToday;
    cin.ignore();
  }

  return 0;
}
