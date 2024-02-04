#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;

  long long res = 0, currVal = 0;
  for (long long i = 1; i <= n; ++i)
  {
    currVal = (pow(10, floor(log10(i)) + 1) * currVal) + i;
    if ((currVal % k) == 0)
      res++;
    currVal %= k;
  }

  cout << res << endl;

  return 0;
}
