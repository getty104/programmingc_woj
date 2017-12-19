#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, A[200000];

ll dfs(ll l, ll r, ll &ans) {
  if(r - l <= 1) return 0;

  ll ret = 0;
  ll m = (l + r) / 2;
  dfs(l, m, ans);
  dfs(m, r, ans);

  REP(i, m, r) ret += (A + m) - upper_bound(A + l, A + m, A[i]);

  ll xl = l, xr = m;
  vector<ll> s;
  while(xl < m || xr < r) {
    if(xl < m && xr < r && A[xl] <= A[xr]) s.push_back(A[xl++]);
    else if(xl < m && xr < r && A[xr] < A[xl]) s.push_back(A[xr++]);
    else if(xl < m) s.push_back(A[xl++]);
    else if(xr < r) s.push_back(A[xr++]);
  }
  REP(i, l, r) A[i] = s[i - l];

  ans += ret;
  cout << ans << endl;
  return ret;
}

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> A[i];

  ll ans = 0;
  dfs(0, N, ans);
}
