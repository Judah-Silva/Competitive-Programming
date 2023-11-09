#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(queue<int> &queue, vector<vector<int>> &adj, vector<int> &mark, vector<int> &values, int curr);

int main()
{
  int n, h, l;
  cin >> n >> h >> l;

  vector<int> values;
  for (int i = 0; i < n; ++i)
  {
    values.push_back(1000000);
  }

  queue<int> queue;
  for (int i = 0; i < h; ++i)
  {
    int horrorId;
    cin >> horrorId;
    values[horrorId] = 0;
    queue.push(horrorId);
  }

  vector<vector<int>> adj(n, vector<int>());
  for (int i = 0; i < l; ++i)
  {
    int id1, id2;
    cin >> id1 >> id2;
    adj[id1].push_back(id2);
    adj[id2].push_back(id1);
  }

  vector<int> mark(n, 0);
  while (!queue.empty())
  {
    bfs(queue, adj, mark, values, queue.front());
  }

  int largestIndex = 0;
  for (int i = 0; i < n; ++i)
  {
    if (values[i] > values[largestIndex])
      largestIndex = i;
  }

  cout << largestIndex;
  return 0;
}

void bfs(queue<int> &queue, vector<vector<int>> &adj, vector<int> &mark, vector<int> &values, int curr)
{
  queue.pop();
  mark[curr] = 1;
  for (int i = 0; i < adj[curr].size(); ++i)
  {
    if (mark[adj[curr][i]])
    {
      continue;
    }
    queue.push(adj[curr][i]);
    if (values[adj[curr][i]] > values[curr])
    {
      values[adj[curr][i]] = values[curr] + 1;
    }
  }
}
