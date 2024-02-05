#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<string> words(n);
  for (auto &s : words)
    cin >> s;

  unordered_set<char> used;
  for (auto &s : words)
  {
    for (auto &c : s)
    {
      used.insert(c);
    }
  }

  if (used.size() > 18)
  {
    cout << "0\n";
    return 0;
  }

  unordered_map<char, int> map;
  int index = 0;
  for (auto &c : used)
    map[c] = index++;

  string alph = "abcdefghijklmnopqrstuvwxyz";
  int alphi = 0;
  while (index < 18)
  {
    if (!used.count(alph[alphi]))
      map[alph[alphi]] = index++;
    alphi++;
  }

  unordered_map<int, char> revMap;
  for (auto &[c, x] : map)
    revMap[x] = c;

  vector<vector<int>> adj(18, vector<int>(18, 1));
  for (int i = 0; i < 18; ++i)
  {
    adj[i][i] = 0;
  }

  for (auto &s : words)
  {
    if (s[0] == s[1] || s[0] == s[2] || s[1] == s[2])
    {
      cout << "0\n";
      return 0;
    }

    adj[map[s[0]]][map[s[1]]] = 0;
    adj[map[s[1]]][map[s[0]]] = 0;
    adj[map[s[0]]][map[s[2]]] = 0;
    adj[map[s[2]]][map[s[0]]] = 0;
    adj[map[s[1]]][map[s[2]]] = 0;
    adj[map[s[2]]][map[s[1]]] = 0;
  }

  unordered_map<string, bool> memo;
  auto isValid = [&](string die)
  {
    if (memo.count(die))
      return memo[die];
    for (int i = 0; i < die.size() - 1; ++i)
    {
      for (int j = i + 1; j < die.size(); ++j)
      {
        if (adj[map[die[i]]][map[die[j]]])
          continue;
        return memo[die] = false;
      }
    }
    return memo[die] = true;
  };

  string dice1, dice2, dice3;
  function<bool(int)> solve = [&](int i)
  {
    if (i == 18)
    {
      return isValid(dice1) && isValid(dice2) && isValid(dice3);
    }
    if (dice1.length() < 6)
    {
      dice1 += revMap[i];
      if (solve(i + 1))
        return true;
      dice1.pop_back();
    }
    if (dice2.length() < 6)
    {
      dice2 += revMap[i];
      if (solve(i + 1))
        return true;
      dice2.pop_back();
    }
    if (dice3.length() < 6)
    {
      dice3 += revMap[i];
      if (solve(i + 1))
        return true;
      dice3.pop_back();
    }
    return false;
  };

  if (solve(0))
  {
    cout << dice1 << " " << dice2 << " " << dice3 << "\n";
  }
  else
  {
    cout << "0\n";
  }

  return 0;
}
