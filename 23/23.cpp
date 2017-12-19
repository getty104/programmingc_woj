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
Vector A,B;
ll n;
ll mx = -INF;
int CountingSort(){
  Vector C(mx+1,0);
  rep(i,n)C[A[i]]++;
  rep(i,mx+1)cout << (i == 0 ? "" : " ") << C[i];
  cout << endl;
  repl(i,1,mx)C[i] = C[i] + C[i-1];
  for(ll i = n-1; i >= 0; i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  A.resize(n);
  B.resize(n);
  rep(i,n){
    cin >> A[i];
    maxch(mx, A[i]);
  }
  CountingSort();
  rep(i,n)cout << (i == 0 ? "" : " ") << B[n-1-i];
  cout << endl;
}
