#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

typedef long long ll;
const int maxn = 1e8;
bitset<maxn> bs;
vector<int> primes;

bool isPrime(ll num) {
  if (num <= maxn) return bs[num];
  for (auto prime : primes) {
    if (prime >= num) break;
    if (num % prime == 0) return false;
  }

  return true;
}

int main() {
  bs.set(); bs[0] = bs[1] = 0;
  for (ll i = 2; i <= maxn; ++i) {
    if (bs[i]) {
      for (ll j = i * i; j <= maxn; j += i) bs[j] = 0;
      primes.push_back(i);
    }
  }

  int x;
  cin >> x;

  int numPrimes = 0;
  for (auto prime : primes) if (prime <= x) numPrimes++;
  cout << numPrimes << "\n";

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    ll num; cin >> num;
    cout << isPrime(num) << "\n";
  }

  return 0;
}
