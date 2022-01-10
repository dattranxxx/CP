#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "riddle";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
int a[N], b[N + 1];
int n, k;
int check(int m) {
  // dung m + 1 so 
  for (int i = 0; i <= m; ++i)
    b[i + 1] = a[i];
  sort(b + 1, b + m + 2);
  int cur = 0;
  for (int i = 1; i <= m + 1; ++i)
    if (cur >= k) return 1;
    else if (b[i] > cur + 1) return 0;
    else cur = b[i] + cur;
  return cur >= k;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) 
      cin >> a[i];
    int lo = 0, hi = n-1, mid, ans = -2;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (check(mid)) 
        ans = mid, 
        hi = mid - 1;
      else
        lo = mid + 1;
    }
    cout << ans + 1 << '\n';
  }
  return 0;
}

