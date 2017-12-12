#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, M;

ll combination(int n, int r) {
  static ll comb[51][51];
  ll &ret = comb[n][r];
  if(ret != 0) return ret;
  if(n == 0 || r == 0) return ret = 1;
  if(n == r) return ret = 1;
  if(r == 1) return ret = n;
  return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main(void) {
  cin >> N >> M;

  cout << combination(N - 1, M - 1) << endl;
}
