#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

int main() {
  string kittenBranch;
  cin >> kittenBranch;

  string parent;
  unordered_map<string, string> graph;
  while (cin >> parent) {
    if (parent == "-1") {
      break;
    }

    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<string> children;
    while (getline(ss, line, ' ')) {
      children.push_back(line);
    }

    for (auto& child : children) {
      graph[child] = parent;
    }
  }

  string currBranch = kittenBranch;
  while(graph.count(currBranch)) {
    cout << currBranch << " ";
    currBranch = graph[currBranch];
  }

  cout << currBranch << "\n";

  return 0;
}
