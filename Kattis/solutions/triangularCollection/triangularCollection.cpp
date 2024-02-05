#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> sides;
  for (int i = 0; i < n; ++i)
  {
    int side;
    cin >> side;
    sides.push_back(side);
  }

  sort(sides.begin(), sides.end());

  long long res = 0;
  for (int i = 0; i < n - 2; ++i)
  {
    for (int j = i + 1; j < n - 1; ++j)
    {
      long long count = 1;
      for (int h = j + 1; h < n; ++h)
      {
        if (sides[i] + sides[j] > sides[h])
        {
          // cout << "i: " << sides[i] << "\nj: " << sides[j] << "\nh: " << sides[h] << "\n";
          res += count;
          count *= 2;
        }
        else
        {
          break;
        }
      }
    }
  }

  cout << res << endl;

  return 0;
}