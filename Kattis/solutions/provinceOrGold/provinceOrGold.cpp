#include <iostream>
using namespace std;

int main(void) {
    int gold, silver, copper, worth;
    cin >> gold >> silver >> copper;
    worth = (gold * 3) + (silver * 2) + copper;
    if (worth >= 8) {
        cout << "Province or Gold\n";
    } else if (worth >= 6) {
        cout << "Duchy or Gold\n";
    } else if (worth == 5) {
        cout << "Duchy or Silver\n";
    } else if (worth >= 3) {
        cout << "Estate or Silver";
    } else if (worth == 2) {
        cout << "Estate or Copper";
    } else {
        cout << "Copper";
    }
    return 0;
}
