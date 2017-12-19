#include <bits/stdc++.h>
#define REP(i, a, n) for(ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

ll N, A[200000];

class BinaryIndexedTree {
  vector<int> v;

  public:
  BinaryIndexedTree(int n) {
    REP(i, 0, n) v.push_back(0);
  }

  int query(int i) {
    if(!(i + 1)) return 0;
    return binop(v[i], query((i + 1) - ((i + 1) & -(i + 1)) - 1));
  }

  void update(int i, int n) {
    if(i > v.size()) return;
    v[i] = binop(v[i], n);
    update((i + 1) + ((i + 1) & -(i + 1)) - 1, n);
  }

  private:
  int binop(int a, int b) {
    return a + b;
  }
};

int main(void) {
  cin >> N;
  REP(i, 0, N) cin >> A[i];
  reverse(A, A + N);

  BinaryIndexedTree bit(N + 1);
  ll ans = 0;
  REP(i, 0, N) {
    ans += bit.query(N) - bit.query(A[i]);
    bit.update(A[i], 1);
  }
  cout << ans << endl;
}
