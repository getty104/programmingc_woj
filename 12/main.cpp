#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = (a); i < (n); i++)
using namespace std;
typedef long long ll;

ll N, A[100000];

int main(void) {
  while(1) {
    cin >> N;
    if(N == 0) break;
    REP(i, 0, N) cin >> A[i];

    sort(A, A + N);

    ll ans = (1LL << 60);
    REP(i, 0, N - 1) ans = min(ans, A[i + 1] - A[i]);
    cout << ans << endl;
  }
}
