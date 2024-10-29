#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> timeIn, low, parent;
vector<pair<int, int>> bridges;
int timeCounter = 0, root, children;

void dfs(vector<unordered_set<int>>& graph, int curr) {
  timeIn[curr] = timeCounter++;
  low[curr] = timeIn[curr];

  for (auto& neighbor : graph[curr]) {
    if (timeIn[neighbor] == -1) {
      parent[neighbor] = curr;
      if (curr == root) children++;

      dfs(graph, neighbor);

      if (low[neighbor] > timeIn[curr]) {
        bridges.push_back({curr, neighbor});
      }
      low[curr] = min(low[curr], low[neighbor]);
    } else if (neighbor != parent[curr]) {
      low[curr] = min(low[curr], timeIn[neighbor]);
    }
  }
}

int counterDFS(vector<unordered_set<int>>& graph, int curr) {
  timeIn[curr] = timeCounter++;

  int count = 0;
  for (auto& neighbor : graph[curr]) {
    if (timeIn[neighbor] == -1) {
      count += counterDFS(graph, neighbor);
    }
  }

  return 1 + count;
}

int main() {
  int junctions, tunnels;
  cin >> junctions >> tunnels;

  timeIn.assign(junctions, -1);
  low.assign(junctions, 0);
  parent.assign(junctions, -1);
  vector<unordered_set<int>> graph(junctions);
  for (int i = 0; i < tunnels; i++) {
    int first, second;
    cin >> first >> second;
    graph[first].insert(second);
    graph[second].insert(first);
  }

  for (int i = 0; i < junctions; i++) {
    if (timeIn[i] == -1) {
      root = i, children = 0;
      dfs(graph, i);
    }
  }

  for (auto& bridge : bridges) {
    graph[bridge.first].erase(bridge.second);
    graph[bridge.second].erase(bridge.first);
  }

  timeIn.assign(junctions, -1);
  cout << counterDFS(graph, 0) << "\n";

  return 0;
}
