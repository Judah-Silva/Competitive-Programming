#include <bits/stdc++.h>
using namespace std;

struct point
{
  point() { x = y = 0; }
  point(double _x, double _y) : x(_x), y(_y){};

  bool operator==(point other) const
  {
    return (fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS);
  }

  // Used for sorting
  bool operator<(point other) const
  {
    if (fabs(x - other.x) > EPS)
    {
      return x < other.x;
    }
    return y < other.y;
  }

  friend ostream &operator<<(ostream &os, const point &object)
  {
    os << object.x << ", " << object.y;
    return os;
  }

  double x, y;
  double static constexpr EPS = 1e-9;
};

double dist(point p1, point p2)
{
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec
{
  double x, y;
  vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b)
{
  return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s)
{
  return vec(v.x * s, v.y * s);
}

point translate(point p, vec v)
{
  return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

double distToLine(point p, point a, point b, point &c)
{
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  c = translate(a, scale(ab, u));
  return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c)
{
  vec ap = toVec(a, p), ab = toVec(a, b);
  double u = dot(ap, ab) / norm_sq(ab);
  if (u < 0.0)
  {
    c = point(a.x, a.y);
    return dist(p, a);
  }
  if (u > 1.0)
  {
    c = point(b.x, b.y);
    return dist(p, b);
  }

  return distToLine(p, a, b, c);
}

int main()
{
  int x, y, x1, y1, x2, y2;

  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  point goat(x, y), house1(x1, y1), house2(x1, y2), house3(x2, y2), house4(x2, y1);

  point c;
  double smallestDist = min(1e9, distToLineSegment(goat, house1, house2, c));
  smallestDist = min(smallestDist, distToLineSegment(goat, house2, house3, c));
  smallestDist = min(smallestDist, distToLineSegment(goat, house3, house4, c));
  smallestDist = min(smallestDist, distToLineSegment(goat, house1, house4, c));

  cout << fixed << setprecision(3) << smallestDist << "\n";

  return 0;
}