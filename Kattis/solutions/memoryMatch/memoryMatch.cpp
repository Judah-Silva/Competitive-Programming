#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, turns;
  cin >> n >> turns;

  unordered_map<string, set<int>> availableCards;
  set<string> foundCards;
  for (int i = 0; i < turns; ++i)
  {
    int a, b;
    string s, t;
    cin >> a >> b >> s >> t;
    if (s == t)
    {
      availableCards.erase(s);
      foundCards.insert(s);
    }

    if (!foundCards.count(s))
      availableCards[s].insert(a);
    if (!foundCards.count(t))
      availableCards[t].insert(b);
  }

  int res = 0;
  int faceDown = n - (foundCards.size() * 2);
  vector<string> toBeErased;
  for (auto &[card, set] : availableCards)
  {
    faceDown -= set.size();
    if (set.size() == 2)
    {
      toBeErased.push_back(card);
      res++;
    }
  }

  for (auto &card : toBeErased)
    availableCards.erase(card);

  if (availableCards.size() == faceDown)
  {
    res += availableCards.size();
    faceDown = 0;
  }

  if (availableCards.empty() && faceDown == 2)
    res++;

  cout << res << "\n";

  return 0;
}
