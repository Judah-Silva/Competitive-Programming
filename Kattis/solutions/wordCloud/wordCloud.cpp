#include <bits/stdc++.h>
using namespace std;

pair<int, int> processWord(string word, int count, int maxCount);

int main() {
  int i = 0;
  while(true) {
    i++;
    int maxWidth, n;
    cin >> maxWidth >> n;
    if (maxWidth == 0 && n == 0) break;

    vector<pair<string, int>> vec;
    int maxCount = 0;
    for (int i = 0; i < n; ++i) {
      string word;
      int count;
      cin >> word >> count;
      vec.push_back({word, count});
      maxCount = max(maxCount, count);
    }

    int runningSum = 0;
    vector<vector<int>> cloud(n, vector<int>());
    int j = 0;
    for (auto& [word, count] : vec) {
      // cout << word << ": " << count << "\n";
      auto info = processWord(word, count, maxCount);
      if (runningSum + info.second > maxWidth) {
        cloud[++j].push_back(info.first);
        runningSum = info.second + 10;
      } else {
        cloud[j].push_back(info.first);
        runningSum += info.second + 10;
      }
    }

    int maxHeight = 0;
    int sumHeight = 0;
    for (auto& v : cloud) {
      for (auto& size : v) {
        maxHeight = max(size, maxHeight);
      }
      sumHeight += maxHeight;
      maxHeight = 0;
    }

    cout << "CLOUD " << i << ": " << sumHeight << "\n";

  }
  return 0;
}

pair<int, int> processWord(string word, int count, int maxCount) {
  int points = 8 + ceil((40.0 * (count - 4)) / (maxCount - 4));
  int width = ceil((9.0 / 16) * word.size() * points);
  // cout << width << "\n";
  return {points, width};
}
