#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
string s;
int n, q, l, r;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> s; n = s.size(); s = ' ' + s;
  vector<int> f(n + 1);
  cin >> q;
  while (q--) {
    cin >> l, r = n - l + 1;
    // tang khoang [l, n - l + 1]
    if (l > r) swap(l, r);
    f[l]++;
    if (r <= n) f[r + 1]--;
  }
  for (int i = 1; i <= n; ++i) 
    if ((f[i] += f[i-1]) & 1) cout << s[n - i + 1];
    else cout << s[i];
  return 0;
}

