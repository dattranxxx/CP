/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 5e3;
int a[N+1], f[N+1];
unordered_map<int, int> idx;
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) 
    cin >> a[i];
  // voi moi r tim l nho nhat thoa man ton tai l < m < r 
  // sao cho f[r] - f[m] == f[m] - f[l]; <-> (l, r]
  // <=> f[l] == 2f[m] - f[r] va l nho nhat
  idx.reserve(n + 1);
  f[0] = 0; idx[f[0]] = 0;
  int res = 0;
  for (int r = 1; r <= n; ++r) {
    f[r] = f[r - 1] + a[r];
    for (int m = r-1; m >= 1; --m)
      if (idx.count(2*f[m] - f[r]) && idx[2*f[m] - f[r]] < m) 
        res = max(res, r - idx[2*f[m] - f[r]]);
    if (!idx.count(f[r]))
      idx[f[r]] = r;
  }
  cout << res;
  return 0;
}

