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
vector<string> mp(10);
struct State{
  int cost;
  int x;
  int y;
};

int rds(int x,int y){
  queue<P> pre;
  queue<State> states;
  Vector dir_x(4);
  Vector dir_y(4);
  dir_x[0] = 1;
  dir_x[1] = 0;
  dir_x[2] = -1;
  dir_x[3] = 0;
  dir_y[0] = 0;
  dir_y[1] = -1;
  dir_y[2] = 0;
  dir_y[3] = 1;
  states.push(State{0,x,y});
  pre.push(mkp(-1,-1));
  while(states.size() > 0){
    x = states.front().x;
    y = states.front().y;
    int cost = states.front().cost;
    int pre_x = pre.front().fi;
    int pre_y = pre.front().se;
    pre.pop();
    states.pop();
    if(mp[x][y] == 'G')return cost;
    rep(i,4){
      int tmp_x = x + dir_x[i];
      int tmp_y = y + dir_y[i];
      if(tmp_x >= 0 && tmp_x <= 9 && tmp_y >= 0 && tmp_y <= 9 && !(tmp_x == pre_x && tmp_y == pre_y)){
        if(mp[tmp_x][tmp_y] == '.' || mp[tmp_x][tmp_y] == 'G'){
          State tmp_state;
          tmp_state.cost = cost+1;
          tmp_state.x = tmp_x;
          tmp_state.y = tmp_y;
          states.push(tmp_state);
          pre.push(mkp(x,y));
        }
      }
    }
  }
  return 0;
}

int main(){
  cin.sync_with_stdio(false);
  rep(i,10)cin >> mp[i];
  int x,y;
  rep(i,10)rep(j,10){
    if(mp[i][j]=='S'){
      x = i;
      y = j;
      break;
    }
  }
  cout << rds(x,y) << endl;
}
