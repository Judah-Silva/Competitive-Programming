#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<int> color, parent;
vector<pair<int, int>> queryEdges;
map<pair<int, int>, int> flippedMap;

void dfs(vector<vector<int>>& graph, int curr) {
  color[curr] = 1;

  for (auto& neighbor : graph[curr]) {
    if (!color[neighbor]) { // Tree edge
      flippedMap[{curr, neighbor}] = 0;
      flippedMap[{neighbor, curr}] = 1;
      parent[neighbor] = curr;
      dfs(graph, neighbor);
    }
    
    if (color[neighbor] == 1 && parent[curr] != neighbor) { // Back edge
      flippedMap[{neighbor, curr}] = 0;
      flippedMap[{curr, neighbor}] = 1;
    }
  }

  color[curr] = 2;
}

int main() {
  int vertices, edges;
  cin >> vertices >> edges;

  color.assign(vertices + 1, 0);
  parent.assign(vertices + 1, -1);
  vector<vector<int>> graph(vertices + 1);
  for (int i = 0; i < edges; i++) {
    int first, second;
    cin >> first >> second;
    graph[first].push_back(second);
    graph[second].push_back(first);

    queryEdges.push_back({first, second});

    flippedMap[{first, second}] = -1;
    flippedMap[{second, first}] = -1;
  }

  for (int i = 1; i <= vertices; i++) {
    if (!color[i]) {
      dfs(graph, i);
    }
  }

  for (auto& edge : queryEdges) {
    flippedMap[edge] ? cout << edge.second << " " << edge.first << "\n" : cout << edge.first << " " << edge.second << "\n";
  }

  return 0;
}
