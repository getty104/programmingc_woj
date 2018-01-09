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
DVector mp;
Vector dfs_vec;
Vector rds_vec;

void dfs(int current){
  dfs_vec.pb(current);
  rep(i, mp[current].size()){
    if(exist(dfs_vec,mp[current][i]))continue;
    dfs(mp[current][i]);
  }
}

void rds(int st){
  queue<ll> q;
  q.push(st);
  while(q.size() > 0){
    int current = q.front();
    q.pop();
    if(exist(rds_vec,current))continue;
    rds_vec.pb(current);
    rep(i, mp[current].size()){
      q.push(mp[current][i]);
    }
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  mp.resize(n);
  rep(i,n){
    int idx,dim;
    cin >> idx >> dim;
    rep(j,dim){
      int num;
      cin >> num;
      mp[i].pb(num-1);
    }
  }
  rds(0);
  dfs(0);
  rep(i,rds_vec.size())cout << (i == 0 ? "" : " ") << rds_vec[i]+1;
  cout << endl;
  rep(i,dfs_vec.size())cout << (i == 0 ? "" : " ") << dfs_vec[i]+1;
  cout << endl;
}
