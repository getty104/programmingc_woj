#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll M, Nmin, Nmax, A[200];

int main(void) {
  cin >> M >> Nmin >> Nmax;
  REP(i, 0, M) cin >> A[i];

  sort(A, A + M);

  ll m = -1, ans;
  REP(i, Nmin, Nmax + 1) {
    if(m <= A[M - i] - A[M - i - 1]) {
      m = A[M - i] - A[M - i - 1];
      ans = i;
    }
  }
  cout << ans << endl;
}
