#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);

  set<string> st;
  cin >> N;
  REP(i, 0, N) {
    string C, S;
    cin >> C >> S;

    if(C == "add") st.insert(S);
    if(C == "remove") st.erase(S);
    if(C == "find") cout << (st.count(S) ? "yes" : "no") << endl;
  }
}
