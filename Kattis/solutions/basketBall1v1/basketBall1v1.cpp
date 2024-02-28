#include <iostream>
using namespace std;

int main() {
  int alice = 0;
  int barb = 0;

  string record;
  cin >> record;

  bool tieGame = false;
  for (int i = 0; i < record.size() - 1; i += 2) {
    if (record[i] == 'A') alice += record[i + 1] - '0';
    else barb += record[i + 1] - '0';
    if (alice == barb && alice == 10) {
      tieGame = true;
      cout << "tied";
    }

    if (alice >= 11 && !tieGame) {
      cout << tieGame << "\n";
      cout << alice << ">" << barb << "\n";
      cout << "A\n";
      return 0;
    } else if (barb >= 11 && !tieGame) {
      cout << "2\n";
      cout << barb << ">" << alice << "\n";
      cout << "B\n";
      return 0;
    } else if (tieGame && alice >= barb + 2) {
      cout << "3\n";
      cout << alice << ">" << barb << "\n";
      cout << "A\n";
      return 0;
    } else if (tieGame && barb >= alice + 2) {
      cout << "4\n";
      cout << barb << ">" << alice << "\n";
      cout << "B\n";
      return 0;
    } 
  }

  alice > barb ? cout << "A\n" : cout << "B\n";

  return 0;
}
