#include <iostream>
#include <vector>
using namespace std;

vector<int> colors;
int color = 1;

void dfs(vector<vector<int>>& graph, int curr) {
  colors[curr] = color;
  for (auto& friend_ : graph[curr]) {
    if (!colors[friend_]) {
      // cout << "friend: " << friend_ << "\n";
      dfs(graph, friend_);
    }
  }
}

int main() {
  int people, friendships;
  cin >> people >> friendships;

  colors.assign(people, 0);
  vector<int> owed(people, 0);
  for (int i = 0; i < people; i++) {
    cin >> owed[i];
  }

  vector<vector<int>> graph(people);
  for (int i = 0; i < friendships; i++) {
    int first, second;
    cin >> first >> second;

    graph[first].push_back(second);
    graph[second].push_back(first);
  }

  for (int i = 0; i < people; i++) {
    if (!colors[i]) {
      color++;
      dfs(graph, i);
    }
  }

  // for (auto& color : colors) {
  //   cout << color << " ";
  // }
  // cout << "\n";

  vector<int> sums(color + 1, 0);
  for (int i = 0; i < colors.size(); ++i) {
    sums[colors[i]] += owed[i]; // Add the amount this person owes to the sum of the color at colors[i]
  }

  // for (auto& sum : sums) {
  //   cout << sum << " ";
  // }
  // cout << "\n";

  for (auto& sum : sums) {
    if (sum) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }

  cout << "POSSIBLE\n";
  return 0;
}

// the values actually matter
// see if all connected components have sums of 0
