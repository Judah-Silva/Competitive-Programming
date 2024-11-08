#include <iostream>
#include <vector>
using namespace std;

int visited = 0;

void dfs(vector<vector<int>>& graph, int curr) {
  visited |= (1 << curr);
  for (auto& friend_ : graph[curr]) {
    if ((visited & (1 << friend_)) == 0) {
      cout << "friend: " << friend_ << "\n";
      dfs(graph, friend_);
    }
  }
}

int main() {
  int people, friendships;
  cin >> people >> friendships;

  vector<int> owed(people, 0);
  int firstNonZero = -1;
  for (int i = 0; i < people; i++) {
    cin >> owed[i];
    if (owed[i] && firstNonZero == -1) firstNonZero = i;
  }

  vector<vector<int>> graph(people);
  for (int i = 0; i < friendships; i++) {
    int first, second;
    cin >> first >> second;

    graph[first].push_back(second);
    graph[second].push_back(first);
  }

  int complete = (1 << people) - 1;
  dfs(graph, firstNonZero);

  for (int i = 0; i < people; i++) {
    if (!owed[i]) {
      visited |= (1 << i);
    }
  }

  cout << "visited: " << visited << "\ncomplete: " << complete << "\n";

  visited == complete ? cout << "POSSIBLE\n" : cout << "IMPOSSIBLE\n";

  return 0;
}

// the values actually matter
