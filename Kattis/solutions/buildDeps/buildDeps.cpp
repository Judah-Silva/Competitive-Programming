#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> visited;
vector<string> ts;

void dfs(unordered_map<string, vector<string>>& dependencyList, string curr) {
  if (visited[curr]) return;
  visited[curr] = 1;

  for (auto& file : dependencyList[curr]) {
    if (!visited.count(file)) {
      dfs(dependencyList, file);
    }
  }

  ts.push_back(curr);
}

vector<string> split(string line) {
  vector<string> res;
  stringstream ss(line);
  string token;
  while (getline(ss, token, ' ')) {
    res.push_back(token);
  }

  return res;
}

int main() {
  int n;
  cin >> n;
  cin.ignore();

  unordered_map<string, vector<string>> dependencyList;
  for (int i = 0; i < n; i++) {
    string line;
    getline(cin, line);
    vector<string> dependencies = split(line);

    for (int i = 1; i < dependencies.size(); i++) {
      dependencyList[dependencies[i]].push_back(dependencies[0].substr(0, dependencies[0].size() - 1));
    }
  }

  string start;
  cin >> start;
  dfs(dependencyList, start);


  reverse(ts.begin(), ts.end());

  for (auto& file : ts) {
    cout << file << "\n";
  }

  return 0;
}
