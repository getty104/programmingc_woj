#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N;

ll fact(ll n) {
  if(n == 0) return 1;
  return fact(n - 1) * n;
}

int main(void) {
  cin >> N;
  cout << fact(N) << endl;
}
