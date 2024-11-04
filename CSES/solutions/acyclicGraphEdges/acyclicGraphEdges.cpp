#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<int> color, parent;
vector<pair<int, int>> queryEdges;
unordered_map<string, int> flippedMap;


void dfs(vector<vector<int>>& graph, int curr) {
  color[curr] = 1;

  stringstream ss1, ss2;
  for (auto& neighbor : graph[curr]) {
    ss1 << curr << " " << neighbor;
    ss2 << neighbor << " " << curr;
    if (!color[neighbor]) { // Tree edge
      flippedMap[ss1.str()] = 0;
      flippedMap[ss2.str()] = 1;
      parent[neighbor] = curr;
      dfs(graph, neighbor);
    }
    
    if (color[neighbor] == 1 && parent[curr] != neighbor) { // Back edge
      flippedMap[ss2.str()] = 0;
      flippedMap[ss1.str()] = 1;
    }
    ss1.str(string());
    ss2.str(string());
  }

  color[curr] = 2;
}

int main() {
  int vertices, edges;
  cin >> vertices >> edges;

  color.assign(vertices + 1, 0);
  parent.assign(vertices + 1, -1);
  vector<vector<int>> graph(vertices + 1);
  stringstream ss1, ss2;
  for (int i = 0; i < edges; i++) {
    int first, second;
    cin >> first >> second;
    graph[first].push_back(second);
    graph[second].push_back(first);

    queryEdges.push_back({first, second});
    
    ss1 << first << " " << second;
    ss2 << second << " " << first;
    flippedMap[ss1.str()] = -1;
    flippedMap[ss2.str()] = -1;
    ss1.str(string());
    ss2.str(string());
  }

  for (int i = 1; i <= vertices; i++) {
    if (!color[i]) {
      dfs(graph, i);
    }
  }

  // for (auto& [str, flipped] : flippedMap) {
  //   cout << str << " " << flipped << "\n";
  // }

  stringstream ss;
  for (auto& edge : queryEdges) {
    ss << edge.first << " " << edge.second;
    // cout << ss.str() << ": ";
    flippedMap[ss.str()] ? cout << edge.second << " " << edge.first << "\n" : cout << edge.first << " " << edge.second << "\n";
    ss.str(string());
  }

  return 0;
}
