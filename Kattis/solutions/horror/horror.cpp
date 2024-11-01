#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
  int n, h, l;
  cin >> n >> h >> l;

  vector<int> scores(n, 1e9);
  queue<int> queue;
  for (int i = 0; i < h; i++) {
    int id;
    cin >> id;
    queue.push(id);
    scores[id] = 0;
  }

  vector<vector<int>> adjList(n);
  for (int i = 0; i < l; i++) {
    int first, second;
    cin >> first >> second;
    adjList[first].push_back(second);
    adjList[second].push_back(first);
  }

  while(!queue.empty()) {
    int curr = queue.front();
    queue.pop();

    for (auto neighbor : adjList[curr]) {
      if (scores[neighbor] > scores[curr] + 1) {
        scores[neighbor] = scores[curr] + 1;
        queue.push(neighbor);
      }
    }
  }

  int maxIndex = 0;
  for (int i = 0; i < n; i++) {
    if (scores[i] > scores[maxIndex]) {
      maxIndex = i;
    }
  }

  cout << maxIndex << "\n";

  return 0;
}
