#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef vector<char> Vector;
typedef vector<vector<char> > DVector;

#define fi          first
#define se          second
#define pb          push_back
#define INF         INT_MAX/3
#define bcnt        __builtin_popcount
#define all(x)      (x).begin(),(x).end()
#define dbg(x)      cout<<#x"="<<x<<endl
#define ub(x,y)     upper_bound(all(x),y)-x.begin()
#define lb(x,y)     lower_bound(all(x),y)-x.begin()
#define uni(x)      x.erase(unique(all(x)),x.end())
#define rep(i,n)    repl(i,0,n-1)
#define repl(i,a,b) for(ll i=(ll)(a);i<=(ll)(b);i++)
#define mmax(x,y)   (x>y?x:y)
#define mmin(x,y)   (x<y?x:y)
#define maxch(x,y)  x=mmax(x,y)
#define minch(x,y)  x=mmin(x,y)
#define exist(x,y)  (find(all(x),y)!=x.end())
#define each(itr,v) for(auto itr:v)
#define usort(x)    sort(all(x))
#define dsort(x)    sort(all(x),greater<int>())
#define mkp(x,y)    make_pair(x,y)
int n,m;
DVector mp;
int ct = 1;

void dfs(int cn, int cm){
  int mx = 0;
  int flag = true;
  if(cn < n-1 && mp[cn+1][cm] == '.'){
    flag = false;
    mp[cn+1][cm] = '#';
    ct++;
    dfs(cn+1,cm);
  }

  if(cm < m-1 && mp[cn][cm+1] == '.'){
    flag = false;
    mp[cn][cm+1] = '#';
    ct++;
    dfs(cn,cm+1);
  }

  if(cn > 0 && mp[cn-1][cm] == '.'){
    flag = false;
    mp[cn-1][cm] = '#';
    ct++;
    dfs(cn-1,cm);
  }

  if(cm > 0 && mp[cn][cm-1] == '.'){
    flag = false;
    mp[cn][cm-1] = '#';
    ct++;
    dfs(cn,cm-1);
  }
}


int main(){
  cin.sync_with_stdio(false);

  while(true){
    ct = 1;
    cin >> m >> n;
    if(m == 0 && n == 0)break;
    int stn,stm;
    mp.resize(n,Vector(m));
    rep(i,n)rep(j,m){
      char tmp;
      cin >> tmp;
      if(tmp == '@'){
        stn = i;
        stm = j;
        mp[i][j] = '#';
      }
      else mp[i][j] = tmp;
    }

    dfs(stn,stm);
    cout << ct << endl;
  }
}
