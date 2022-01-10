#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
void file() {
  const string FILE_NAME = "lis";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 2e5;
struct segment_tree {
  struct V {
    int l, r, v;
    V(int l = 0, int r = 0, int v = 0): l(l), r(r), v(v) {}
  };
  vector<V> st;
  segment_tree(): st(1) {}
  int x, y, v;
  void get(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) 
      return v = max(v, st[k].v), void();
    int m = (l + r) >> 1;
    if (st[k].l) 
      get(st[k].l, l, m);
    if (st[k].r) 
      get(st[k].r, m+1, r);
  }
  void update(int k, int l, int r) {
    if (l > x || r < x) return;
    if (l == r) 
      return st[k].v = max(st[k].v, v), void();
    int m = (l + r) >> 1;
    if (!st[k].l)
      st[k].l = st.size(),
      st.emplace_back();
    update(st[k].l, l, m);
    if (!st[k].r)
      st[k].r = st.size(),
      st.emplace_back();
    update(st[k].r, m+1, r);
    st[k].v = max(st[st[k].l].v, st[st[k].r].v);
  }
  void clear() {
    vector<V>().swap(st);
    st.emplace_back();
  }
  int get(int l, int r) {
    if (l > r) return 0;
    x = l, y = r, v = 0;
    get(0, 1, 1e9);
    return v;
  }
  void update(int pos, int val) {
    x = pos, v = val;
    update(0, 1, 1e9);
  }  
} st;
int a[N], pre[N], suf[N];
int n, d;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> d;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  // tien to
  for (int i = 0; i < n; ++i) 
    pre[i] = st.get(1, a[i] - 1) + 1,
    st.update(a[i], pre[i]),
    cerr << pre[i] << " \n"[i == n-1];
  st.clear();
  // hau to
  for (int i = n-1; ~i; --i) 
    suf[i] = st.get(a[i] + 1, 1e9) + 1,
    st.update(a[i], suf[i]),
    cerr << suf[i] << " \n"[i == 0];
  st.clear();
  // duyet diem cat
  int res = 1;
  for (int i = 0; i < n; ++i)
    res = max(res, suf[i] + st.get(1, a[i] + d - 1)),
    st.update(a[i], pre[i]);
  cout << res;
  return 0;
}

