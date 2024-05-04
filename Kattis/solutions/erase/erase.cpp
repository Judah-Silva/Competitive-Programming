#include <iostream>
using namespace std;

int main() {
  int overwrites;
  cin >> overwrites;

  string binary, binaryChanged;
  cin >> binary >> binaryChanged;

  bool flipped = overwrites % 2;
  for (int i = 0; i < binary.length(); ++i) {
    if (flipped && binary[i] == binaryChanged[i]) {
      cout << "Deletion failed\n";
      return 0;
    } else if (!flipped && binary[i] != binaryChanged[i]) {
      cout << "Deletion failed\n";
      return 0;
    }
  }

  cout << "Deletion succeeded\n";

  return 0;
}
