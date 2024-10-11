#include <iostream>
#include <map>
using namespace std;

int main() {
  map<string, string> translationKey = {
    {"A#", "Bb"},
    {"Bb", "A#"},
    {"C#", "Db"},
    {"Db", "C#"},
    {"D#", "Eb"},
    {"Eb", "D#"},
    {"F#", "Gb"},
    {"Gb", "F#"},
    {"G#", "Ab"},
    {"Ab", "G#"}
  };

  int n = 1;

  string key;
  while (cin >> key) {
    string tonality;
    cin >> tonality;
    cout << "Case " << n << ": ";
    if (translationKey.count(key)) {
      cout << translationKey[key] << " " << tonality << "\n";
    } else {
      cout << "UNIQUE\n";
    }
    n++;
  }

  return 0;
}
