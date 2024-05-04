#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<vector<char>> grid;

void rotate(vector<vector<char>>& input) {
  vector<int> dir = {1, 0, -1, 0, 1};
  vector<int> diag = {1, 1, -1, -1, 1};
  int m = input.size(), n = input[0].size();
  string walls = "\\/\\/";
  int m2 = m + n, n2 = m2;
  grid.assign(m2, vector<char>(n2, '.'));
  for (int j = 0; j < n; ++j) {
    int i2 = j, j2 = j + m - 1;
    for (int i = 0; i < m; ++i, ++i2, --j2) {
      if (input[i][j] != '.') {
        grid[i2][j2] = '#';
        for (int d = 0; d < 4; ++d) {
          if (input[i][j] != walls[d]) continue;
          int r = i + diag[d];
          int c = j + diag[d + 1];
          if (r < 0 || c < 0 || r >= m || c >= n) continue;
          if (input[i][j] != input[r][c]) continue;
          r = dir[d];c = dir[d + 1];
          grid[i2 + r][j2 + c] = '#';
        }
      }
    } 
  }
}

int main() {
  int m, n;
  cin >> m >> n;

  vector<vector<char>> input(m, vector<char>(n, '.'));
  for (auto& vec : input) {
    for (auto& square : vec) cin >> square;
  }

  rotate(input);

  m = grid.size(), n = grid[0].size();
  vector<vector<char>> newGrid(m + 1, vector<char>(n + 1, '.'));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      newGrid[i + 1][j + 1] = grid[i][j];
    }
  }

  m = newGrid.size(), n = newGrid[0].size();
  vector<int> dir = {1, 0, -1, 0, 1};
  function<bool(int, int, int)> bfs = [&] (int x, int y, int mark) {
    if (newGrid[x][y] != '.') return false;
    queue<pair<int, int>> q;
    q.push({x, y});

    bool res = false;
    while (!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      if (newGrid[x][y] != '.') continue;
      newGrid[x][y] = '#';


      for (int i = 0; i < 4; ++i) {
        if (x + dir[i] < 0 || y + dir[i + 1] < 0 || x + dir[i] >= m || y + dir[i + 1] >= n) {
          continue;
        }
        q.push({x + dir[i], y + dir[i + 1]});
      }
    }
    return true;
  };


  int res = -1;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (bfs(i, j, res)) {
        res++;
      }
    }
  }

  cout << res << "\n";

  return 0;
}
