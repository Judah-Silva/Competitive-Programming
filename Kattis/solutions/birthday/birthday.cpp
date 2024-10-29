#include <iostream>
#include <vector>
using namespace std;

vector<int> timeIn, low, parent;
int timeCounter = 0, root, children;
bool bridge = false;

void dfs(vector<vector<int>>& graph, int curr) {
  timeIn[curr] = timeCounter++;
  low[curr] = timeIn[curr];

  for (auto& neighbor : graph[curr]) {
    if (timeIn[neighbor] == -1) {
      parent[neighbor] = curr;
      if (curr == root) children++;

      dfs(graph, neighbor);

      if (low[neighbor] > timeIn[curr]) {
        bridge = true;
        return;
      }
      low[curr] = min(low[curr], low[neighbor]);
    } else if (neighbor != parent[curr]) {
      low[curr] = min(low[curr], timeIn[neighbor]);
    }
  }
}

int main() {
  int vertices, edges;

  while (cin >> vertices >> edges) {
    if (!vertices && !edges) {
      return 0;
    }

    timeIn.assign(vertices, -1);
    low.assign(vertices, 0);
    parent.assign(vertices, -1);
    vector<vector<int>> graph(vertices);
    for (int i = 0; i < edges; i++) {
      int first, second;
      cin >> first >> second;
      graph[first].push_back(second);
      graph[second].push_back(first);
    }

    for (int i = 0; i < vertices; i++) {
      if (timeIn[i] == -1) {
        root = i, children = 0;
        dfs(graph, i);
        if (bridge) {
          cout << "Yes\n";
          break;
        }
      }
    }

    if (!bridge) {
      cout << "No\n";
    }
    bridge = false;
  }

  return 0;
}
