#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "skiing";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 1e5 - 2;
vector<int> a[N];
struct segment_tree {
  int x, y, v, st[N * 4];
  segment_tree() { memset(st, 0, sizeof(st)); }
  void update(int k, int l, int r) {
    if (l > x || r < x) return;
    if (l == r)
      return st[k] = max(st[k], v), void();
    int m = (l + r) >> 1;
    update(k << 1, l, m);
    update(k << 1 | 1, m + 1, r);
    st[k] = max(st[k << 1], st[k << 1 | 1]);
  }
  void get(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y)
      return v = max(st[k], v), void();
    int m = (l + r) >> 1;
    get(k << 1, l, m);
    get(k << 1 | 1, m + 1, r);
  }
  void update(int pos, int val) {
    x = pos, v = val;
    update(1, 0, N);
  }
  int get(int l, int r) {
    x = l, y = r, v = 0;
    get(1, 0, N);
    return v;
  }
} st[2];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0, x, y; i < n; ++i) 
    cin >> x >> y, x--, y--,
    a[y].emplace_back(x);
  int res = 0;
  for (int y = N; ~y; --y) if (a[y].size()) {
    vector<int> dp[2];
    for (int x : a[y])
      dp[0].emplace_back(max(st[0].get(0, x - 1), st[1].get(x + 1, N) + 1)),
      dp[1].emplace_back(max(st[0].get(0, x - 1) + 1, st[1].get(x + 1, N))),
      res = max(res, max(dp[0].back(), dp[1].back()));
    for (int i = 0; i < a[y].size(); ++i) 
      st[0].update(a[y][i], dp[0][i]),
      st[1].update(a[y][i], dp[1][i]);
  }
  cout << res;
  return 0;
}

