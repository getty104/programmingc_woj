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

int main(){
  cin.sync_with_stdio(false);
  int n,m;
  cin >> n >> m;
  vector<string> mp(m);
  DVector dp(m,Vector(n,0));
  rep(i,m)cin >> mp[m-1-i];
  dp[0][0] = 1;
  rep(i,m)rep(j,n){
    if(i == 0 && j == 0)continue;
    if(mp[i][j] == 'X')continue;
    int cost = 0;
    if(i > 0)cost += dp[i-1][j];
    if(j > 0)cost += dp[i][j-1];
    dp[i][j] = cost;
  }
  cout << dp[m-1][n-1] << endl;
}
