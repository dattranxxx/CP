#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "city";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
struct fenwick_tree {
  int n;
  vector<int> bit;
  fenwick_tree(int n = 0): n(n), bit(n + 1) {}
  void update(int i, int x) {
    for (; i <= n; i += i & -i)
      bit[i] += x;
  }
  int get(int i) {
    int res = 0;
    for (; i; i -= i & -i)
      res += bit[i];
    return res;
  }
};
const int N = 1e5;
int a[N], last[N];
struct P {
  int l = 0, r = 0, i = 0;
  bool operator < (const P& p) const {
    return r < p.r;
  }
} p[N];
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  vector<int> c(n);
  for (int i = 1; i <= n; ++i)
    cin >> a[i], c[i - 1] = a[i];
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
  cin >> m;
  for (int i = 0; i < m; ++i)
    cin >> p[i].l >> p[i].r, p[i].i = i;
  sort(p, p + m);
  vector<int> res(m);
  fenwick_tree bit(n);
  memset(last, -1, sizeof(last));
  for (int r = 1, i = 0; i < m; ++i) {
    while (r <= p[i].r) {
      if (last[a[r]] != -1)
        bit.update(last[a[r]], -1);
      last[a[r]] = r;
      bit.update(last[a[r]], 1);
      r++;
    }  
    res[p[i].i] = bit.get(p[i].r) - bit.get(p[i].l - 1);
  }
  for (int i = 0; i < m; ++i)
    cout << res[i] << '\n';
  return 0;
}

