#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> visited;
// vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};
vector<int> dir = {0, -1, 0, 1, 0};
int diceDots = 0;


void dfs(vector<vector<char>>& grid, int row, int col) {
  diceDots += grid[row][col] == 'X';
  visited[row][col] = 1;

  bool neighborDot = false;
  for (int i = 0; i < dir.size() - 1; i++) {
    int newRow = row + dir[i];
    int newCol = col + dir[i + 1];

    if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size()) {
      continue;
    }

    if (grid[newRow][newCol] == '.' || visited[newRow][newCol]) continue;

    if (grid[row][col] == 'X' && grid[newRow][newCol] == 'X') {
      diceDots--;
      dfs(grid, newRow, newCol);
    } else if (grid[row][col] == 'X' && i == dir.size() - 2) {
      dfs(grid, newRow, newCol);
    } else if (grid[row][col] == '*') {
      dfs(grid, newRow, newCol);
    }
  }

}

int main() {
  int rows, cols, n = 1;
  while (cin >> cols >> rows) {
    if (!rows && !cols) {
      return 0;
    }


    visited.assign(rows, vector<int>(cols, 0));
    vector<vector<char>> grid(rows, vector<char>(cols));
    for (auto& row : grid) {
      for (auto& col : row) cin >> col;
    }


    cout << "Throw " << n++ << "\n";
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (!visited[i][j] && grid[i][j] != '.') {
          dfs(grid, i, j);
          cout << diceDots << " ";
          // cout << i << ", " << j << "\n";
        }
        diceDots = 0;
      }
    }


    cout << "\n\n";
  }

  return 0;
}

/**
30 15
..............................
..............................
...............*..............
...*****......****............
...*X***.....**X***...........
...*****....***X**............
...***X*.....****.............
...*****.......*..............
..............................
........***........******.....
.......**X****.....*X**X*.....
......*******......******.....
.....****X**.......*X**X*.....
........***........******.....
..............................
5 5
*****
*X*X*
**X**
*X*X*
*****
0 0
 */
