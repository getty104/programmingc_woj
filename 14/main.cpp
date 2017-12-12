#include <iostream>
#define REP(i, a, n) for(ll i = (a); i < (n); i++)
using namespace std;
typedef long long ll;

int T;
string S;

int mod[10] = { 1, 5, 3, 3, 3, 3, 3, 4, 3, 4 };
char key[10][5] = {
  { '0', '0', '0', '0', '0' },
  { '.', ',', '!', '?', ' ' },
  { 'a', 'b', 'c', '0', '0' },
  { 'd', 'e', 'f', '0', '0' },
  { 'g', 'h', 'i', '0', '0' },
  { 'j', 'k', 'l', '0', '0' },
  { 'm', 'n', 'o', '0', '0' },
  { 'p', 'q', 'r', 's', '0' },
  { 't', 'u', 'v', '0', '0' },
  { 'w', 'x', 'y', 'z', '0' },
};

int main(void) {
  cin >> T;
  while(T--) {
    cin >> S;
    string ans = "";
    REP(i, 0, S.length()) {
      if(S[i] == '0') continue;
      ll j;
      for(j = i; S[j] != '0'; j++);
      ll n = S[i] - '0';
      ll p = (j - i - 1) % mod[n];
      ll k = key[n][p];
      ans += k;
      i = j;
    }
    cout << ans << endl;
  }
  return 0;
}
