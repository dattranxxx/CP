#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "bookcase";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 70;
struct S {
  int h, t;
  bool operator < (const S& s) const {
    return h > s.h;
  }
};
S a[N];
int f[N], dp[2][2101][1051]; // gia su s1 >= s2 -> s2 ~ N*T/2
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    int max_t = -oo;
    for (int i = 0; i < n; ++i)
      cin >> a[i].h >> a[i].t,
      max_t = max(max_t, a[i].t);
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
      f[i] = (i ? f[i-1] : 0) + a[i].t;
    memset(dp, 0x3f, sizeof(dp));
    int inf = dp[0][0][0]; dp[0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
      int cur = i & 1, nxt = cur ^ 1;
      memset(dp[nxt], 0x3f, sizeof(dp[nxt]));
      for (int j = 0; j <= n * max_t; ++j)
        for (int k = 0; k <= n * max_t / 2; ++k) if (dp[cur][j][k] != inf) {
          // printf("%d %d %d, max = %d\n", j, k, f[i] - (j + k + a[i].t), dp[cur][j][k]);
          if (j != 0) 
            dp[nxt][j + a[i].t][k] = min(dp[nxt][j + a[i].t][k], dp[cur][j][k]);
          else 
            dp[nxt][j + a[i].t][k] = min(dp[nxt][j + a[i].t][k], dp[cur][j][k] + a[i].h);

          if (k != 0 && k + a[i].t <= n * max_t / 2) {
            dp[nxt][j][k + a[i].t] = min(dp[nxt][j][k + a[i].t], dp[cur][j][k]);
          } else if (k + a[i].t <= n * max_t / 2)
            dp[nxt][j][k + a[i].t] = min(dp[nxt][j][k + a[i].t], dp[cur][j][k] + a[i].h);

          if (j + k + a[i].t != f[i]) 
            dp[nxt][j][k] = min(dp[nxt][j][k], dp[cur][j][k]);
          else
            dp[nxt][j][k] = min(dp[nxt][j][k], dp[cur][j][k] + a[i].h);
        }
    }
    int res = oo;
    for (int j = 1; j <= n * max_t; ++j)
      for (int k = 1; k <= n * max_t / 2; ++k) if (dp[n & 1][j][k] != inf && f[n-1] - (j + k)) 
        res = min(res, dp[n & 1][j][k] * max({j, k, f[n-1] - (j + k)}));
    cout << res << '\n';
  }
  return 0;
}

