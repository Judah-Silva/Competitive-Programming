#include <iostream>
#include <stack>
using namespace std;

int main()
{
  int n;
  cin >> n;

  stack<int> monotonic;
  int count = 1;
  for (int i = 0; i < n; ++i)
  {
    int num;
    cin >> num;
    while (!monotonic.empty() && monotonic.top() < num)
    {
      monotonic.pop();
      count++;
    }

    if (monotonic.empty())
    {
      count--;
      monotonic.push(num);
    }
    else
    {
      monotonic.push(num);
    }
  }

  cout << count + n - 1 << endl;

  return 0;
}

// 5

// 4
// 2
// 3
// 5
// 1

// 7