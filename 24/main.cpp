#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, A[200000];

ll dfs(ll l, ll r) {
  if(l + 1 >= r) {
    cout << A[l] << endl;
    return A[l];
  }

  ll lv = dfs(l, (r + l) / 2);
  ll rv = dfs((r + l) / 2, r);
  ll ret = min(lv, rv);
  cout << ret << endl;
  return ret;
}

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> A[i];

  dfs(0, N);
}
