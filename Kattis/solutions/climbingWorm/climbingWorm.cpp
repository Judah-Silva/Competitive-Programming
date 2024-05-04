#include <iostream>
using namespace std;

int main() {
  int a, b, h;
  cin >> a >> b >> h;

  int climbs = 0;
  int currHeight = 0;
  while (currHeight < h) {
    currHeight += a;
    climbs++;
    if (currHeight < h) currHeight -= b;
  }

  cout << climbs;
  return 0;
}
