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
  string a, b;
  cin >> a;
  cin >> b;
  DVector dp(a.size(),Vector(b.size(),0));
  rep(i,a.size())rep(j,b.size()){
    if(j > 0)dp[i][j] = dp[i][j-1];
    if(a[i] == b[j]){
      int flag = 0;
      if(i > 0 && j > 0)flag = dp[i-1][j-1];
      dp[i][j] = flag + 1;
    }else{
      int flag = 0;
      if(i > 0)maxch(flag,dp[i-1][j]);
      if(j > 0)maxch(flag,dp[i][j-1]);
      dp[i][j] = flag;
    }
  }
  cout << dp[a.size()-1][b.size()-1] << endl;
}
