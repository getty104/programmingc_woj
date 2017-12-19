#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, A[500000];

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> A[i];

  sort(A, A + N, greater<ll>());
  REP(i, 0, N) cout << A[i] << (i + 1 != N ? " " : "\n");
  cout << N - 1 << endl;
}
