#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
  int n;
  cin >> n;

  vector<vector<int>> cache(n, vector<int>(2001));
  int weight;
  cin >> weight;
  cache[0][0] = 1;
  cache[0][weight] = 1;
  for (int i = 1; i < n; ++i)
  {
    int weight;
    cin >> weight;
    cache[i][weight] = 1;
    for (int j = 0; j < 2001; ++j)
    {
      if (cache[i - 1][j])
      {
        cache[i][j] = 1;
        if (j + weight <= 2000)
          cache[i][j + weight] = 1;
      }
    }
  }

  for (int i = 1000, j = 1000; i < 2001, j >= 0; ++i, --j)
  {
    if (cache[n - 1][i])
    {
      cout << i;
      return 0;
    }
    if (cache[n - 1][j])
    {
      cout << j;
      return 0;
    }
  }

  return 0;
}
