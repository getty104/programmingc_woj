#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;
typedef pair<string, ll> psl;

ll N, Q, T[100000];
string S[100000];

int main(void) {
  cin >> N >> Q;
  REP(i, 0, N) cin >> S[i] >> T[i];

  queue<psl> q;
  REP(i, 0, N) q.push(psl(S[i], T[i]));

  ll time = 0;
  vector<psl> ans;
  while(q.size()) {
    string s = q.front().first;
    ll t = q.front().second;
    q.pop();

    if(t <= Q) {
      time += t;
      ans.push_back(psl(s, time));
    } else {
      time += Q;
      q.push(psl(s, t - Q));
    }

    ll sz = q.size();
    vector<psl> mid;
    REP(i, 0, sz) {
      psl p = q.front();
      q.pop();
      mid.push_back(p);
      q.push(p);
    }
    REP(i, 0, mid.size()) cout << mid[i].first << " " << mid[i].second << (i + 1 != mid.size() ? " " : "\n");
  }
  REP(i, 0, ans.size()) cout << ans[i].first << " " << ans[i].second << (i + 1 != ans.size() ? " " : "\n");
}
