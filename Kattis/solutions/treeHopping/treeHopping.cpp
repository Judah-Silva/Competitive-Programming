#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

void assignInfo(vector<vector<int>> &adj, vector<node> &nodes, vector<int> &visited, int curr, int parent)
{
  if (visited[curr])
    return;
  visited[curr] = 1;
  nodes[curr] = {nodes[parent].first + 1, {curr, parent}};
  for (auto &v : adj[curr])
  {
    assignInfo(adj, nodes, visited, v, curr);
  }
}

bool valid(vector<node> &nodes, node a, node b)
{
  for (int i = 0; i < 3 && a != b; ++i)
  {
    if (a.first > b.first)
    {
      a = nodes[a.second.second];
    }
    else
    {
      b = nodes[b.second.second];
    }
  }
  return a.second.first == b.second.first;
}

int main()
{
  int n;
  cin >> n;

  while (n--)
  {
    int m;
    cin >> m;

    vector<vector<int>> adj(m + 1, vector<int>());
    for (int i = 0; i < m - 1; ++i)
    {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<node> nodes(m + 1, {-1, {-1, -1}});
    vector<int> visited(m + 1, 0);
    assignInfo(adj, nodes, visited, 1, 0);

    vector<int> permutation;
    for (int i = 0; i < m; ++i)
    {
      int num;
      cin >> num;
      permutation.push_back(num);
    }

    bool isValid = true;
    for (int i = 1; i < m; ++i)
    {
      if (!valid(nodes, nodes[permutation[i - 1]], nodes[permutation[i]]))
      {
        isValid = false;
        break;
      }
    }

    cout << isValid << "\n";
  }

  return 0;
}
