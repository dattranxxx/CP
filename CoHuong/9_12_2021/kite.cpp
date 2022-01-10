#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "kite";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
struct fenwick_tree {
  int n;
  vector<int> bit;
  fenwick_tree(int n): n(n), bit(n + 1) {}
  void add(int i) {
    for (; i <= n; i += i & -i)
      bit[i]++;
  }
  int get(int i) {
    int res = 0;
    for (; i; i -= i & -i)
      res += bit[i];
    return res;
  }
};
const int oo = 1e9;
const int N = 1e5;
int a[N];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i], c[i] = a[i];
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  for (int i = 0; i < n; ++i) 
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin(), 
    a[i] = c.size() - a[i];
  fenwick_tree bit(c.size());
  for (int i = 0; i < n; ++i)
    cout << bit.get(a[i] - 1) + 1 << '\n',
    bit.add(a[i]);
  return 0;
}

