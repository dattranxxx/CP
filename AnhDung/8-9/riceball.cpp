/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
void file() {
  const string FILE_NAME = "riceball";
  freopen((FILE_NAME + ".inp"), "r", stdin);
  freopen((FILE_NAME + ".out"), "w", stdout);
}
const int N = 400;
int a[N+1], f[N+1], dp[N+1][N+1];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  int res = -oo;
  for (int i = 1; i <= n; ++i)
    cin >> a[i], f[i] = f[i-1] + a[i], dp[i][i] = 1, res = max(res, a[i]);
  for (int len = 2; len <= n; ++len) {
    for (int l = 1; l <= n; ++l) {
      int r = l + len - 1;
      for (int m = l + 1; m <= r; ++m) 
        if (dp[l][m-1] && dp[m][r] && f[m-1] - f[l-1] == f[r] - f[m-1])
          dp[l][r] = 1, res = max(res, f[r] - f[l-1]);
      for (int m = l + 1; m < r; ++m)
        if (dp[l][m-1] && dp[m+1][r] && f[m-1] - f[l-1] == f[r] - f[m])
          dp[l][r] = 1, res = max(res, f[r] - f[l-1]);
    }
  }
  cout << res;
  return 0;
}

