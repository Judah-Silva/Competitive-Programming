#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void upSolve(vector<int>& quad, double left, double right, double up, double down);
void downSolve(vector<int>& quad, double left, double right, double up, double down);
void leftSolve(vector<int>& quad, double left, double right, double up, double down);
void rightSolve(vector<int>& quad, double left, double right, double up, double down);

typedef pair<int, int> pdd;
// unordered_map<int, string> nameMap;
unordered_map<int, pdd> pointMap;
int counter = 0;

vector<vector<int>> split(vector<int>& quad, double left, double right, double up, double down) {
  double horizontalLine = ((up - down) / 2.0) + down;
  double verticalLine = ((right - left) / 2.0) + left;
  
  vector<vector<int>> quads(4, vector<int>());
  for (auto& index : quad) {
    auto point = pointMap[index];
    if (point.first < verticalLine) {
      point.second < horizontalLine ? quads[0].push_back(index) : quads[1].push_back(index);
    } else {
      point.second < horizontalLine ? quads[3].push_back(index) : quads[2].push_back(index);
    }
  }

  return quads;
}

void upSolve(vector<int>& quad, double left, double right, double up, double down) {
  if (quad.size() == 1) {
    cout << pointMap[quad[0]].first << " " << pointMap[quad[0]].second << "\n";
    // cout << nameMap[quad[0]] << "\n";
    return;
  }

  double newVertical = ((right - left) / 2.0) + left;
  double newHorizontal = ((up - down) / 2.0) + down;

  auto quads = split(quad, left, right, up, down);
  if (!quads[0].empty()) rightSolve(quads[0], left, newVertical, newHorizontal, down);
  if (!quads[1].empty()) upSolve(quads[1], left, newVertical, up, newHorizontal);
  if (!quads[2].empty()) upSolve(quads[2], newVertical, right, up, newHorizontal);
  if (!quads[3].empty()) leftSolve(quads[3], newVertical, right, newHorizontal, down);
}

void downSolve(vector<int>& quad, double left, double right, double up, double down) {
  if (quad.size() == 1) {
    cout << pointMap[quad[0]].first << " " << pointMap[quad[0]].second << "\n";
    // cout << nameMap[quad[0]] << "\n";
    return;
  }

  double newVertical = ((right - left) / 2.0) + left;
  double newHorizontal = ((up - down) / 2.0) + down;

  auto quads = split(quad, left, right, up, down);
  if (!quads[2].empty()) leftSolve(quads[2], newVertical, right, up, newHorizontal);
  if (!quads[3].empty()) downSolve(quads[3], newVertical, right, newHorizontal, down);
  if (!quads[0].empty()) downSolve(quads[0], left, newVertical, newHorizontal, down);
  if (!quads[1].empty()) rightSolve(quads[1], left, newVertical, up, newHorizontal);
}

void leftSolve(vector<int>& quad, double left, double right, double up, double down) {
  if (quad.size() == 1) {
    cout << pointMap[quad[0]].first << " " << pointMap[quad[0]].second << "\n";
    // cout << nameMap[quad[0]] << "\n";
    return;
  }

  double newVertical = ((right - left) / 2.0) + left;
  double newHorizontal = ((up - down) / 2.0) + down;

  auto quads = split(quad, left, right, up, down);
  if (!quads[2].empty()) downSolve(quads[2], newVertical, right, up, newHorizontal);
  if (!quads[1].empty()) leftSolve(quads[1], left, newVertical, up, newHorizontal);
  if (!quads[0].empty()) leftSolve(quads[0], left, newVertical, newHorizontal, down);
  if (!quads[3].empty()) upSolve(quads[3], newVertical, right, newHorizontal, down);
}

void rightSolve(vector<int>& quad, double left, double right, double up, double down) {
  if (quad.size() == 1) {
    cout << pointMap[quad[0]].first << " " << pointMap[quad[0]].second << "\n";
    // cout << nameMap[quad[0]] << "\n";
    return;
  }

  double newVertical = ((right - left) / 2.0) + left;
  double newHorizontal = ((up - down) / 2.0) + down;

  auto quads = split(quad, left, right, up, down);
  if (!quads[0].empty()) upSolve(quads[0], left, newVertical, newHorizontal, down);
  if (!quads[3].empty()) rightSolve(quads[3], newVertical, right, newHorizontal, down);
  if (!quads[2].empty()) rightSolve(quads[2], newVertical, right, up, newHorizontal);
  if (!quads[1].empty()) downSolve(quads[1], left, newVertical, up, newHorizontal);
}

int main() {
  int n, s;
  cin >> n >> s;

  vector<int> allPoints;
  for (int i = 0; i < n; ++i) {
    int x, y; // string name;
    cin >> x >> y;
    // nameMap[i] = name;
    pointMap[i] = {x, y};
    allPoints.push_back(i);
  }

  upSolve(allPoints, 0, s, s, 0);

  return 0;
}
