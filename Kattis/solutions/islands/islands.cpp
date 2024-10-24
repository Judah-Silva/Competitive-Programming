#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> visited;
vector<int> dir = {0, -1, 0, 1, 0};

void dfs(vector<vector<char>>& graph, int row, int col) {
  if (visited[row][col]) {
    return;
  }

  visited[row][col] = 1;

  for (int i = 0; i < 4; i++) {
    int newRow = row + dir[i];
    int newCol = col + dir[i + 1];

    if (newRow < 0 || newCol < 0 || newRow >= graph.size() || newCol >= graph[0].size()) {
      continue;
    }

    if (graph[newRow][newCol] == 'W') continue;

    dfs(graph, newRow, newCol);
  }
}

int main() {
  int row, col;
  cin >> row >> col;

  visited.assign(row, vector<int>(col, 0));
  vector<vector<char>> graph(row, vector<char>(col));
  for (int i = 0; i < row; i++) {
    for (auto& x : graph[i]) cin >> x;
  }

  int res = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (!visited[i][j] && graph[i][j] == 'L') {
        dfs(graph, i, j);
        res++;
      }
    }
  }

  cout << res << "\n";

  return 0;
}
