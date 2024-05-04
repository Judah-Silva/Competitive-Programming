#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;


int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
  }

  for (auto& vec : adj) sort(vec.begin(), vec.end());

  vector<int> queries(m, 0);
  for (auto& query : queries) cin >> query;

  vector<int> visited(n + 1, 0);
  int index = 0;
  function<int(int)> dfs = [&] (int currNode) {
    if (visited[currNode]) {
      cout << currNode << "\n";
      return 0;
    }
    visited[currNode] = 1;
    for (auto& child : adj[currNode]) {
      dfs(child);
    }
    // cout << "currNode: " << currNode << "\n";
    while (index < m && visited[queries[index]]) {
      // cout << "checkNode: " << currNode << "\n";
      index++;
    }
    visited[currNode] = 0;
    return 0;
  };

  dfs(1);

  cout << index << "\n";

  return 0;
}
