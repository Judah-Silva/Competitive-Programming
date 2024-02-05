#include <iostream>
#include <vector>
#include <list>
using namespace std;

int dfs(vector<list<char>> &adj, vector<int> &memo, int curr)
{
  if (memo[curr] != -1)
    return memo[curr];

  int result = 1;
  for (auto &c : adj[curr])
  {
    result = max(result, dfs(adj, memo, c - 'A') + 1);
  }
  memo[curr] = result;
  return result;
}

int main()
{
  int n, k;
  cin >> n >> k;

  vector<list<char>> adj(k, list<char>());

  string s;
  cin >> s;
  for (int i = 0; i < k - 1; ++i)
  {
    for (int j = i + 1; j < k; ++j)
    {
      adj[s[i] - 'A'].push_back(s[j]);
    }
  }

  for (int i = 0; i < n - 1; ++i)
  {
    cin >> s;
    for (int j = 0; j < k - 1; ++j)
    {
      for (int l = j + 1; l < k; ++l)
      {
        adj[s[l] - 'A'].remove(s[j]);
      }
    }
  }

  vector<int> memo(k, -1);
  int maxLength = 0;
  for (int i = 0; i < k; ++i)
  {
    maxLength = max(maxLength, dfs(adj, memo, i));
  }

  cout << maxLength << endl;

  return 0;
}
