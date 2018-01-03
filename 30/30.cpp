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

struct Node{
  int value;
  int left;
  int right;
};

vector<Node> tree;

void insert(int m){
  if(tree.size() == 0){
    tree.pb(Node{m,-1,-1});
    return;
  }

  int current = 0;
  while(1){
    if(m <= tree[current].value){
      if(tree[current].left == -1){
        tree[current].left = tree.size();
        tree.pb(Node{m,-1,-1});
        break;
      }
      current = tree[current].left;
    }else{
      if(tree[current].right == -1){
        tree[current].right = tree.size();
        tree.pb(Node{m,-1,-1});
        break;
      }
      current = tree[current].right;
    }
  }
}

void pre_order(int current){
  cout << " " << tree[current].value;
  if(tree[current].left != -1)pre_order(tree[current].left);
  if(tree[current].right != -1)pre_order(tree[current].right);
}

void in_order(int current){
  if(tree[current].left != -1)in_order(tree[current].left);
  cout << " " << tree[current].value;
  if(tree[current].right != -1)in_order(tree[current].right);
}

int main(){
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  rep(i,n){
    string command;
    int op;
    cin >> command;
    if(command == "insert"){
      cin >> op;
      insert(op);
    }
    else if(command == "print"){
      in_order(0);
      cout << endl;
      pre_order(0);
      cout << endl;
    }
  }
}

