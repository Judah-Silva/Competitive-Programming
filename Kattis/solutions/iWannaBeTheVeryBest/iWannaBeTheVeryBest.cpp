#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

using pii = pair<unsigned int, int>;

int main(void)
{
  int n;
  int k;
  cin >> n >> k;

  vector<pii> attack;
  vector<pii> defense;
  vector<pii> health;

  for (int i = 0; i < n; ++i)
  {
    unsigned int a, d, h;
    cin >> a >> d >> h;
    attack.push_back({a, i});
    defense.push_back({d, i});
    health.push_back({h, i});
  }

  sort(attack.begin(), attack.end(), greater<pii>());
  sort(defense.begin(), defense.end(), greater<pii>());
  sort(health.begin(), health.end(), greater<pii>());

  set<int> ans;
  for (int i = 0; i < k; ++i)
  {
    ans.insert(attack[i].second);
    ans.insert(defense[i].second);
    ans.insert(health[i].second);
  }

  cout << ans.size();

  return 0;
}
