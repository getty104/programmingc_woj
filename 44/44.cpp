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

bool dfs(DVector mp, int ct){
  if(ct == 8)return true;
  bool flag = false;
  rep(i,8)rep(j,8){
    if(mp[i][j] == 0){
      DVector tmp = mp;
      rep(k,8)tmp[i][k] = 1;
      rep(k,8)tmp[k][j] = 1;
      int k = i;
      int l = j;
      while(k < 8 && l < 8){
        tmp[k][l] = 1;
        k++;
        l++;
      }
      k = i;
      l = j;
      while(k > 0 && l > 0){
        tmp[k][l] = 1;
        k--;
        l--;
      }
      k = i;
      l = j;
      while(k > 0 && l < 8){
        tmp[k][l] = 1;
        k--;
        l++;
      }
      k = i;
      l = j;
      while(k < 8 && l > 0){
        tmp[k][l] = 1;
        k++;
        l--;
      }
      flag = flag || dfs(tmp,ct+1);
    }
  }
  return flag;
}

int main(){
  cin.sync_with_stdio(false);
  vector<string> tmp(8);
  int ct = 0;
  rep(i,8)cin >> tmp[i];
  DVector mp(8, Vector(8,0));
  rep(i,8)rep(j,8)if(tmp[i][j] == 'Q'){
    rep(k,8)mp[i][k] = 1;
    rep(k,8)mp[k][j] = 1;
    int k = i;
    int l = j;
    while(k < 8 && l < 8){
      mp[k][l] = 1;
      k++;
      l++;
    }
    k = i;
    l = j;
    while(k > 0 && l > 0){
      mp[k][l] = 1;
      k--;
      l--;
    }
    k = i;
    l = j;
    while(k > 0 && l < 8){
      mp[k][l] = 1;
      k--;
      l++;
    }
    k = i;
    l = j;
    while(k < 8 && l > 0){
      mp[k][l] = 1;
      k++;
      l--;
    }
    ct++;
  }
  cout << (dfs(mp,ct) ? "Yes" : "No") << endl;
}
