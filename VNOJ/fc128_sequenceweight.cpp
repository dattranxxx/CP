/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e4+1;
ll a[N], cnt[N], last[N], cur[N], f[N];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> c(n);
    for (int i = 1; i <= n; ++i)
      cin >> a[i], c[i-1] = a[i];
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (int i = 1; i <= n; ++i)
      a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
    memset(cnt, 0, sizeof(cnt));
    memset(cur, 0, sizeof(cur));
    memset(last, 0, sizeof(last));
    ll res = 0;
    for (int r = 1; r <= n; ++r) {
      // idx[x] = [i1, i2, i3, .. ,ik]
      // += (ik - ik-1) + 2*(ik-1 - ik-2) + .. (k-1)*(i2 - i1) + k*i1
      // them ik+1 -> (ik+1 - ik) + 2*(ik - ik-1) + .. + k*(i2 - i1)
      // -> * 2 + ik+1 - ij
      f[r] = f[r-1] + cnt[a[r]];
      res += f[r];
      cur[a[r]] += r - last[a[r]],
      cnt[a[r]] += cur[a[r]];
      last[a[r]] = r;
    }
    cout << res << '\n';
  }
  return 0;
}

