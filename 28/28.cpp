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
int n;
struct Params{
  int parent;
  int brother;
  int child_size;
  int depth;
  int height;
};
DVector tree;
vector<Params> ans;

int dfs(int parent, int current, int depth, int brother){
  int mx = depth;
  int size = tree[current].size();
  rep(i,size){
    int itr = tree[current][i];
    if( itr == parent)continue;
    maxch(mx, dfs(current, itr, depth+1, tree[current][(i+1)%2]));
  }
  ans[current] = Params{parent, brother, size, depth, (mx - depth)};
  return mx;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  tree.resize(n);
  ans.resize(n);
  vector<bool> parent(n,true);
  rep(i,n){
    int ct = 2;
    int p, tmp;
    cin >> p;
    rep(j,ct){
      cin >> tmp;
      if(tmp != -1){
        tree[p].pb(tmp);
        parent[tmp] = false;
      }
    }
  }
  rep(i,n)if(parent[i])dfs(-1,i,0,-1);
  rep(i,n)cout << i << " " << ans[i].parent << " " << ans[i].brother << " " << ans[i].child_size << " " << ans[i].depth << " " << ans[i].height << endl;
}
