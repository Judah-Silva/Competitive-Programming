#include <bits/stdc++.h>
using namespace std;

struct point {
  point() {x = y = 0;}
  point(double _x, double _y): x(_x), y(_y) {};

  bool operator == (point other) const {
    return (fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS);
  }

  // Used for sorting
  bool operator < (point other) const {
    if (fabs(x - other.x) > EPS) {
      return x < other.x;
    }
    return y < other.y;
  }

  friend ostream &operator << (ostream& os, const point& object) {
    os << object.x << ", " << object.y;
    return os;
  }

  double x, y;
  double static constexpr EPS = 1e-9;
};

double area(const vector<point>& fig) {
  double res = 0;
  for (unsigned i = 0; i < fig.size(); i++) {
    point p = i ? fig[i - 1] : fig.back();
    point q = fig[i];
    res += (p.x - q.x) * (p.y + q.y);
  }
  return fabs(res) / 2;
}

double lerp(double a, double b, double t) {
  return a + t * (b - a);
}

double almostEqual(double a, double b, double maxDiff = DBL_EPSILON) {
  double diff = fabs(a - b);
  a = fabs(a); b = fabs(b);

  double largest = (b < a) ? a : b;
  if (diff <= largest * maxDiff) return true;
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<point> vertices;
  for (int i = 0; i < n; ++i) {
    double x, y;
    cin >> x >> y;
    vertices.push_back(point(x, y));
  }

  double totalArea = area(vertices);
  double targetArea = totalArea / 2;

  vector<point> temp;
  pair<point, point> edge;
  double prevArea = 0;
  double ratio = 0;
  for (int j = 0; j < 3; ++j) temp.push_back(vertices[j]);
  for (int i = 3; i < vertices.size(); ++i) {
    double currArea = area(temp) + prevArea;
    if (currArea < targetArea) {
      temp[1] = temp[2];
      temp[2] = vertices[i];
      prevArea = currArea;
      continue;
    }
    if (almostEqual(currArea, targetArea)) {
      cout << vertices[i - 1].x << " " << vertices[i - 1].y << "\n";
      return 0;
    }
    ratio = (targetArea - prevArea) / (currArea - prevArea);
    edge = {vertices[i - 1], vertices[i - 2]};
    break;
  }

  if (n <= 3) {
    edge = {vertices[n - 1], vertices[n - 2]};
    ratio = targetArea / area(temp);
  }

  printf("%.6f %.6f\n", lerp(edge.first.x, edge.second.x, 1 - ratio), lerp(edge.first.y, edge.second.y, 1 - ratio));

  return 0;
}
