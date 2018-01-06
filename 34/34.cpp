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

struct Heap{
  int idx;
  int value;

  int left(){
    return (2*idx + 1);
  }
  int right(){
    return(2*idx + 2);
  }
  int parent(){
    return(ceil(((double)idx)/2.0)-1);
  }
};

vector<Heap> heap;

void maxHeapify(int i){
  int l = heap[i].left();
  int r = heap[i].right();
  int largest;
  if(l < heap.size() && heap[l].value > heap[i].value)largest = l;
  else largest = i;
  if(r < heap.size() && heap[r].value > heap[largest].value)largest = r;

  if(largest != i){
    swap(heap[i].value,heap[largest].value);
    maxHeapify(largest);
  }
}

void buildMaxHeap(){
  for(int i = (heap.size()/2)-1; i >= 0; i--)maxHeapify(i);
}

int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  rep(i,n){
    int tmp;
    cin >> tmp;
    heap.pb(Heap{(int)i,tmp});
  }
  buildMaxHeap();
  rep(i,n)cout << " " << heap[i].value;
  cout << endl;
}
