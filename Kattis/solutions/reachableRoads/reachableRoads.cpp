#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;

void dfs(vector<vector<int>>& graph, int curr) {
  if (visited[curr]) {
    return;
  }

  visited[curr] = 1;

  for (auto& neighbor : graph[curr]) dfs(graph, neighbor);
}

int main() {
  int n;
  cin >> n;

  while (n) {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> graph(v);
    for (int i = 0; i < e; i++) {
      int from, to;
      cin >> from >> to;

      graph[from].push_back(to);
      graph[to].push_back(from);
    }

    int cc = 0;
    visited.assign(v, 0);
    for (int i = 0; i < v; i++) {
      if (!visited[i]) {
        cc++;
        dfs(graph, i);
      }
    }

    cout << cc - 1 << "\n";
    n--;
  }

  return 0;
}
