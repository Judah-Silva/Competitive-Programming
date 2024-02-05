#include <bits/stdc++.h>
using namespace std;

double calculate(double start, double target, double step)
{
  return log2(start / target) * step;
}

int main()
{
  int start, target, bladeCount;
  cin >> start >> target >> bladeCount;

  vector<pair<int, int>> blades;
  for (int i = 0; i < bladeCount; ++i)
  {
    int size, seconds;
    cin >> size >> seconds;
    blades.push_back({seconds, size});
  }
  sort(blades.begin(), blades.end());

  int i = 0;
  while (i < bladeCount && blades[i].second < start)
    i++;

  if (i == bladeCount)
  {
    cout << "-1\n";
    return 0;
  }

  int currSize = start;
  double res = 0;
  for (; i > 0 && currSize > target; --i)
  {
    if (target > blades[i - 1].second)
    {
      res += calculate(currSize, target, blades[i].first);
      currSize = target;
    }
    else
    {
      res += calculate(currSize, blades[i - 1].second, blades[i].first);
      currSize = blades[i - 1].second;
    }
  }

  if (currSize != target)
  {
    res += calculate(currSize, target, blades[0].first);
  }

  printf("%.5e", res);

  return 0;
}
