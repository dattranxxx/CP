/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
int n; string s;
int check() {
  for (int i = 0; i < n; ++i)
    if (s[i] == 'U') return 1;
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    string res = "";
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'U') res += 'D';
      else if (s[i] == 'D') res += 'U';
      else res += s[i];
    }
    cout << res << '\n';
  }
  return 0;
}

