#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool inRange(vector<vector<int>>& grid, int row, int col) {
  return !(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size());
}

int main() {
  int rows, cols;
  cin >> rows >> cols;

  vector<vector<int>> grid;
  
  for (int i = 0; i < rows; i++) {
    vector<int> row;
    for (int j = 0; j < cols; j++) {
      char temp;
      cin >> temp;
      row.push_back(temp - '0');
    }
    grid.push_back(row);
  }

  vector<vector<int>> dist(rows, vector<int>(cols, 1e9));
  queue<vector<int>> queue;

  queue.push({0, 0});
  dist[0][0] = 0;

  while(!queue.empty()) {
    int row = queue.front()[0];
    int col = queue.front()[1];
    queue.pop();

    int val = grid[row][col];
    if (inRange(grid, row - val, col)) {
      if (dist[row][col] + 1 < dist[row - val][col]) {
        dist[row - val][col] = dist[row][col] + 1;
        queue.push({row - val, col});
      }
    }
    if (inRange(grid, row + val, col)) {
      if (dist[row][col] + 1 < dist[row + val][col]) {
        dist[row + val][col] = dist[row][col] + 1;
        queue.push({row + val, col});
      }
    }
    if (inRange(grid, row, col - val)) {
      if (dist[row][col] + 1 < dist[row][col - val]) {
        dist[row][col - val] = dist[row][col] + 1;
        queue.push({row, col - val});
      }
    }
    if (inRange(grid, row, col + val)) {
      if (dist[row][col] + 1 < dist[row][col + val]) {
        dist[row][col + val] = dist[row][col] + 1;
        queue.push({row, col + val});
      }
    }
  }

  int res = dist[rows - 1][cols - 1];

  if (res == 1e9) {
    cout << -1 << "\n";
    return 0;
  }
  
  cout << res << "\n";

  return 0;
}
