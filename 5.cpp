#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<string, ll> P;
typedef vector<ll> Vector;
typedef vector<vector<ll>> DVector;

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

queue<ll> que;

void print_queue(){
  queue<ll> tmp;
  P t;
  t = que.front();
  que.pop();
  cout << t.fi << " " << t.se;
  tmp.push(t);
  while(tmp.size > 0){
    t = que.front();
    que.pop();
    tmp.push(t);
    cout << " " << t.fi << " " << t.se;
  }
  que = tmp;
  cout << endl;
}

int main(){
  cin.sync_with_stdio(false);
  ll n,time;
  cin >> n >> time;
  vector<P> ans;
  rep(i,n){
    string str;
    ll num;
    cin >> str >> num;
    que.push(P(str,num));
  }
  current_time = 0;
  while(true){
    current_time += time;
    P c = que.front();
    que.pop();
    c.se -= time;
    if(c.se > 0)que.push(c);
    else ans.pb P(c.fi,current_time);
    if(que.size() == 0)break;
    print_queue();
  }
}
