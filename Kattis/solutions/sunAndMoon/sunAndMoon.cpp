#include <iostream>
using namespace std;

int main()
{
  int ds, ys, dm, ym;
  cin >> ds >> ys >> dm >> ym;

  for (int i = 1; i < 5000; ++i)
  {
    if ((i + ds) % ys == 0 && (i + dm) % ym == 0)
    {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
