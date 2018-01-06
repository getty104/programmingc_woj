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

bool find(int m, int current){
  if(tree.size() == 0 || current == -1)return false;
  if(tree[current].value == m)return true;
  else{
    if(m <= tree[current].value)return find(m, tree[current].left);
    else return find(m, tree[current].right);
  }
}

void del(int m, int current, int parent, int dir){
  if(tree[current].value == m){
    if(tree[current].left == -1 && tree[current].right == -1){
      if(parent != -1){
        if(dir)tree[parent].left = -1;
        else tree[parent].right = -1;
      }else{
        tree.pop_back();
      }
    }else if(tree[current].right == -1){
      if(parent != -1){
        if(dir)tree[parent].left = tree[current].left;
        else tree[parent].right = tree[current].left;
      }else{
        tree[current] = tree[tree[current].left];
      }
    }else if(tree[current].left == -1){
      if(parent != -1){
        if(dir)tree[parent].left = tree[current].right;
        else tree[parent].right = tree[current].right;
      }else{
        tree[current] = tree[tree[current].right];
      }
    }else{
      int value = tree[tree[current].left].value;
      tree[current].value = value;
      del(value, tree[current].left, current, 1);
    }
  }else{
    if(m <= tree[current].value && tree[current].left != -1)del(m, tree[current].left, current, 1);
    else if(m > tree[current].value && tree[current].right != -1) del(m, tree[current].right, current, 0);
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
    else if(command == "find"){
      cin >> op;
      cout << (find(op,0) ? "yes" : "no") << endl;
    }
    else if(command == "delete"){
      cin >> op;
      del(op, 0 , -1, -1);
    }
  }
}

