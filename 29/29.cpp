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
int n;
struct Params{
  int left;
  int right;
};
vector<Params> tree;

void pre_order(int current){
  cout << " " << current;
  if(tree[current].left != -1)pre_order(tree[current].left);
  if(tree[current].right != -1)pre_order(tree[current].right);
}

void in_order(int current){
  if(tree[current].left != -1)in_order(tree[current].left);
  cout << " " << current;
  if(tree[current].right != -1)in_order(tree[current].right);
}

void post_order(int current){
  if(tree[current].left != -1)post_order(tree[current].left);
  if(tree[current].right != -1)post_order(tree[current].right);
  cout << " " << current;
}

int main(){
  cin.sync_with_stdio(false);
  cin >> n;
  tree.resize(n);
  vector<bool> parent(n,true);
  rep(i,n){
    int p;
    int tmp[2];
    cin >> p;
    rep(j,2){
      cin >> tmp[j];
      if(tmp[j] != -1)parent[tmp[j]] = false;
    }
    tree[p] = Params{tmp[0], tmp[1]};
  }

  rep(i,n)if(parent[i]){
    cout << "Preorder" << endl;
    pre_order(i);
    cout << endl;
    cout << "Inorder" << endl;
    in_order(i);
    cout << endl;
    cout << "Postorder" << endl;
    post_order(i);
    cout << endl;
  }

}
