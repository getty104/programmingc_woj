#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, A[20], Q, M[2000];

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> A[i];
  cin >> Q;
  REP(i, 0, Q) cin >> M[i];

  set<ll> st;
  REP(i, 0, 1LL << N) {
    ll sum = 0;
    REP(j, 0, N) if(i & (1LL << j)) sum += A[j];
    st.insert(sum);
  }

  REP(i, 0, Q) cout << (st.count(M[i]) ? "true" : "false") << endl;
}
