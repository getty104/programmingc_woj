#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, S[100000], Q, T[50000];

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> S[i];
  cin >> Q;
  REP(i, 0, Q) cin >> T[i];

  sort(S, S + N);

  vector<ll> ans;
  REP(i, 0, Q) if(!binary_search(S, S + N, T[i])) ans.push_back(T[i]);
  REP(i, 0, ans.size()) cout << ans[i] << (i + 1 != ans.size() ? " " : "\n");
  cout << ans.size() << endl;
}
