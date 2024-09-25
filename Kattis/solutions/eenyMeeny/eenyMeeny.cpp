#include <iostream>
#include <queue>
#include <vector>
#include <sstream>

using namespace std;

int main() {
  string line;
  getline(cin, line);
  stringstream ss(line);
  vector<string> rhymes;
  string word;
  while (ss >> word) {
    rhymes.push_back(word);
  }

  int numKids;
  cin >> numKids;
  cin.ignore();

  queue<string> kidsQueue;
  for (int i = 0; i < numKids; i++) {
    string kid;
    cin >> kid;
    kidsQueue.push(kid);
  }

  vector<string> team1;
  vector<string> team2;
  bool team = true;

  while (!kidsQueue.empty()) {
    for (int i = 0; i < rhymes.size() - 1; i++) {
      string kid = kidsQueue.front();
      kidsQueue.pop();
      kidsQueue.push(kid);
    }
    if (team) {
      team1.push_back(kidsQueue.front());
    } else {
      team2.push_back(kidsQueue.front());
    }
    kidsQueue.pop();
    team = !team;
  }

  cout << team1.size() << "\n";
  for (auto& kid : team1) {
    cout << kid << "\n";
  }

  cout << team2.size() << "\n";
  for (auto& kid : team2) {
    cout << kid << "\n";
  }

  return 0;
}
