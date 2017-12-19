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
ll ct = 0;
ll n;
Vector A;
void merge(ll left, ll mid, ll right){
  ll n1 = mid - left;
  ll n2 = right - mid;
  Vector L(n1+1);
  Vector R(n2+1);
  rep(i,n1){
    L[i] = A[left + i];
  }
  rep(i,n2){
    R[i] = A[mid + i];
  }

  L[n1] = INF;
  R[n2] = INF;
  ll i = 0;
  ll j = 0;
  repl(k,left,right-1){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
     A[k] = R[j];
     ct+=n1 - i;
     j++;
   }
 }
}

void mergeSort(ll left, ll right){
  if(left+1 < right){
    ll mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);
    cout << ct << endl;
  }
}
int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  A.resize(n);
  rep(i,n)cin >> A[i];
  mergeSort(0,n);
}
