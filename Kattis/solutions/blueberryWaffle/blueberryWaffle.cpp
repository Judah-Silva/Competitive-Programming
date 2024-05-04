#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int r, f;
  cin >> r >> f;

  double rotations = (1.0 * f) / (1.0 * r);
  // cout << rotations << "\n";
  
  int floorVal = (int)floor(rotations);
  int ceilVal = (int)ceil(rotations);
  // cout << floorVal << ", " << ceilVal << "\n";

  if (abs(rotations - floorVal) < abs(rotations - ceilVal)) {
    floorVal % 2 ? cout << "down\n" : cout << "up\n";
  } else {
    ceilVal % 2 ? cout << "down\n" : cout << "up\n";
  }


  return 0;
}
