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
Vector A;
int ct =0;
int partition(int p, int r){
  ct++;
  int x = A[r];
  int i = p-1;
  repl(j,p,r-1){
    if(A[j] >= x){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);
  return i+1;
}

void quickSort(int p, int r){
  if(p < r){
    int q = partition(p,r);
    quickSort(p, q-1);
    quickSort(q+1,r);
  }
}


int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  A.resize(n);
  rep(i,n)cin >> A[i];
  quickSort(0,n-1);
  rep(i,n)cout << (i == 0 ? "" : " ") << A[i];
  cout << endl;
  cout << ct << endl;
}
