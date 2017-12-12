#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, M;

int main(void) {
  cin >> N >> M;

  ll ans = 0;
  REP(i, 0, 1LL << N) {
    bool f = false;
    ll cnt = 0;
    REP(j, 0, N) {
      if(i & (1LL << j)) cnt++;
      else cnt = 0;
      if(cnt == M) f = true;
    }
    if(f) ans++;
  }
  cout << ans << endl;
}
