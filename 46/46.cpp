#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;
typedef vector<ll> Vector;
typedef vector<Vector> DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define uni(x)      x.erase(unique(all(x)),x.end())
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
#define rep(i,n)    repl(i,0,n-1)
#define usort(x)    sort(all(x))
#define dsort(x)    sort(all(x),greater<ll>())
#define mkp(x,y)    make_pair(x,y)
#define mmax(x,y)   (x>y?x:y)
#define mmin(x,y)   (x<y?x:y)
#define maxch(x,y)  x=mmax(x,y)
#define minch(x,y)  x=mmin(x,y)
#define exist(x,y)  (find(all(x),y)!=x.end())
#define each(itr,v) for(auto itr:v)
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)

//// UnionFind Tree

struct UnionFind{
  vector<int> v;
  UnionFind(int n) : v(n, -1) {}

  // 初期化
  void init(){ for(int i = 0;i < v.size();i++)v[i]=-1; }

  // Find
  int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }

  // Union
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (-v[x] < -v[y]) swap(x, y);
    v[x] += v[y]; v[y] = x;
    return true;
  }

  // 以下、オプション
  // 根かどうか
  bool root(int x) { return v[x] < 0; }

  // 同じ連結成分か
  bool same(int x, int y) { return find(x) == find(y); }

  // 同じ連結成分のサイズ
  int size(int x) { return -v[find(x)]; }
};

struct State{
  int x;
  int y;
  int cost;
  bool operator<(const State& another) const {
    return cost < another.cost;
  }
};

int main(){
  cin.sync_with_stdio(false);
  int n;
  vector<State> states;
  cin >> n;
  UnionFind uf(n);
  rep(i,n)rep(j,n){
    int cost;
    State state;
    cin >> cost;
    state.x = i;
    state.y = j;
    state.cost = cost;
    if(cost >= 0)states.pb(state);
  }
  usort(states);
  int ct = 0;
  rep(i, states.size()){
    if(uf.same(states[i].x,states[i].y))continue;
    ct += states[i].cost;
    uf.unite(states[i].x,states[i].y);
  }
  cout << ct << endl;
}
