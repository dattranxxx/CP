#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
void file() {
  const string FILE_NAME = "cover";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e5;
struct S { 
  int l, r;
  S(int l = 0, int r = 0): l(l), r(r) {}
  bool operator < (const S& s) const {
    return l == s.l ? r < s.r : l < s.l;
  }
} a[N];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i].l >> a[i].r;
  sort(a, a + n);
  int res = 0;
  for (int i = 0; i < n;) {
    int l = a[i].l, r = a[i].r; i++;
    while (i < n && r >= a[i].l) 
      r = max(r, a[i].r), i++;
    res += r - l;
  }
  cout << res;
  return 0;
}

