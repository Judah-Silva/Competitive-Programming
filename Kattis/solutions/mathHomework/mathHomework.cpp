#include <iostream>
using namespace std;

int main() {
  int bird, dog, cat, legs;
  cin >> bird >> dog >> cat >> legs;

  bool sol = false;
  for (int i = 0; i <= 250; i++) {
    for (int j = 0; j <= 250; j++) {
      for (int k = 0; k <= 250; k++) {
        if (((i * bird) + (j * dog) + (k * cat)) == legs) {
          cout << i << " " << j << " " << k << "\n";
          sol = true;
        }
      }
    }
  }

  if (!sol) {
    cout << "impossible\n";
  }

  return 0;
}
