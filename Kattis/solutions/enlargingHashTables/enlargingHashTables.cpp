#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef long long ll;
const int maxn = 46340;
bitset<maxn> bs;
vector<ll> primes;


bool isPrime(ll num) {
  if (num <= maxn) return bs[num];
  for (auto prime : primes) {
    if (prime >= num) break;
    if (num % prime == 0) {
      return false;
    }
  } 
  primes.push_back(num);
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

  int num;
  cin >> num;
  while (num != 0) {
    bool originalPrime = isPrime(num);
    ll newNum = num * 2;
    while (!isPrime(++newNum));
    originalPrime ? (cout << newNum << "\n") : (cout << newNum << " (" << num << " is not prime)\n");
    cin >> num;
  }



  return 0;
}
