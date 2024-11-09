#include <iostream>
#include <vector>
using namespace std;

vector<int> connected;

void dfs(vector<vector<int>>& graph, int curr) {
  if (connected[curr]) {
    return;
  }

  connected[curr] = 1;

  for (auto& neighbor : graph[curr]) {
    dfs(graph, neighbor);
  }
}

int main() {
  int houses, edges;
  cin >> houses >> edges;

  connected.assign(houses + 1, 0);

  vector<vector<int>> graph(houses + 1);
  for (int i = 0; i < edges; i++) {
    int from, to;
    cin >> from >> to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  dfs(graph, 1);

  bool isConnected = true;
  for (int i = 1; i < connected.size(); i++) {
    if (!connected[i]) {
      cout << i << "\n";
      isConnected = false;
    }
  }

  if (isConnected) {
    cout << "Connected\n";
  }

  return 0;
}
