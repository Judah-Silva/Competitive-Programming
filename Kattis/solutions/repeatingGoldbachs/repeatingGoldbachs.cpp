#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int x;
  cin >> x;

  vector<int> prime(x + 1, 1);
  for (int i = 2; i * i <= x; i++)
  {
    if (!prime[i])
      continue;
    for (int j = i * i; j <= x; j += i)
      prime[j] = 0;
  }

  vector<int> primes;
  for (int i = 2; i < prime.size(); ++i)
  {
    if (prime[i])
      primes.push_back(i);
  }

  int steps = 0;
  int a = 0, b = primes.size() - 1;
  while (x >= 4)
  {
    a = 0;
    while (primes[b] + primes[a] != x)
    {
      if (primes[b] + primes[a] > x)
        b--;
      if (primes[b] + primes[a] < x)
        a++;
    }
    if (primes[b] + primes[a] == x)
      x = primes[b] - primes[a];
    steps++;
  }

  cout << steps << "\n";

  return 0;
}
