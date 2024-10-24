#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> visited;
vector<int> dir = {0, 1, 0, -1, 0};
bool valid = true;

int dfs(vector<vector<int>>& graph, int row, int col) {
  if (visited[row][col]) {
    return 0;
  }
  visited[row][col] = 1;

  int count = 0;
  for (int i = 0; i < 4; i++) {
    int newRow = row + dir[i];
    int newCol = col + dir[i + 1];

    if (newRow < 0 || newCol < 0 || newRow >= graph.size() || newCol >= graph[0].size()) {
      continue;
    }
    if (graph[newRow][newCol] < graph[row][col]) {
      valid = false;
      continue;
    }
    if (graph[newRow][newCol] > graph[row][col]) {
      continue;
    }

    count += dfs(graph, newRow, newCol);
  }

  return count + 1;
}

int main() {
  int rows, cols;
  cin >> cols >> rows;

  visited.assign(rows, vector<int>(cols, 0));
  vector<vector<int>> graph(rows, vector<int>(cols, 0));
  for (int i = 0; i < graph.size(); i++) {
    for (auto& x : graph[i]) cin >> x;
  }

  int res = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int count = dfs(graph, i, j);
      if (valid && count) {
        // cout << count << " " << i << ", " << j << "\n";
        res += count;
      }
      valid = true;
    }
  }

  cout << res << "\n";

  return 0;
}
