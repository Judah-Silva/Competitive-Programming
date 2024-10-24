#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<string, int> visited;

bool dfs(unordered_map<string, vector<string>>& flights, string curr) {
  visited[curr] = 1;

  bool cycle = false;
  for (auto& neighbor : flights[curr]) {
    if (!visited.count(neighbor)) { // Tree edge
      cycle = cycle || dfs(flights, neighbor);
    }

    if (visited[neighbor] == 1) { // Back edge (cycle)
      return true;
    }
  }

  visited[curr] = 2;
  return cycle;
}

int main() {
  int n;
  cin >> n;

  unordered_map<string, vector<string>> flights;
  for (int i = 0; i < n; i++) {
    string from, to;
    cin >> from >> to;
    flights[from].push_back(to);
  }

  string city;
  while (cin >> city) {
    cout << city << " ";
    dfs(flights, city) ? cout << "safe\n" : cout << "trapped\n";
    visited.clear();
  }

  return 0;
}
