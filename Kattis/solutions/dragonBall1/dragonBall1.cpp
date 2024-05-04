#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, pair<int, int>> p3i;
typedef pair<int, int> pii;

bitset<8> mask;
long long findMinPaths(vector<vector<long long>>& distances, int count, int a) {
  if (mask.all()) return 0;
  long long currMin = 1e18;
  for (int i = 1; i < count; ++i) {
    if (!mask[i] && distances[a][i] < 1e18) {
      mask.set(i);
      currMin = min(currMin, distances[a][i] + findMinPaths(distances, count, i));
      mask.reset(i);
    }
  }

  return currMin;
}

void dijkstra(vector<vector<pii>>& adj, int source, vector<long long>& distances) {
  distances.assign(adj.size(), 1e18);
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, source});
  distances[source] = 0;

  while (!pq.empty()) {
    auto [cost, curr] = pq.top(); pq.pop();
    if (cost != distances[curr]) continue;

    for (auto [city, dist] : adj[curr]) {
      if (distances[city] <= distances[curr] + dist) continue;
      distances[city] = distances[curr] + dist;
      pq.push({distances[city], city});
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<pii>> adj(n, vector<pair<int, int>>());

  for (int i = 0; i < m; ++i) {
    int from, to, distance;
    cin >> from >> to >> distance;
    if (from == to) continue;
    --from, --to;
    adj[from].push_back({to, distance});
    adj[to].push_back({from, distance});
  }

  vector<int> balls;
  for (int i = 0; i < 7; ++i) {
    int ball;
    cin >> ball;
    balls.push_back(--ball);
  }

  balls.push_back(0);
  sort(balls.begin(), balls.end());
  balls.erase(unique(balls.begin(), balls.end()), balls.end());
  // cout << balls.size() << "\n";
  vector<vector<long long>> distances(balls.size(), vector<long long>(balls.size(), 1e18));

  for (auto i = 0; i < balls.size(); ++i) {
    int source = balls[i];
    vector<long long> d;
    dijkstra(adj, source, d);
    for (int j = i + 1; j < balls.size(); ++j) {
      distances[i][j] = d[balls[j]];
      distances[j][i] = d[balls[j]];
    }
  }

  mask = (0b11111111) << balls.size();
  mask.set(0);
  long long ans = findMinPaths(distances, balls.size(), 0);

  cout << (ans < 1e18 ? ans : -1) << "\n";

  return 0;
}

