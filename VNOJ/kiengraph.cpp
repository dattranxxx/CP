/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 300, M = 1e9 + 7;
int dp[N+1][N+1], res[N+1][N+1], C[N+1][N+1];
int n, m, l;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
int mul(int x, int y) {
  return ll(x) * y % M;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m >> l;
  C[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= n; ++j) 
      if (j == 0) C[i][j] = C[i-1][j];
      else add(C[i][j], C[i-1][j] + C[i-1][j-1]);
  dp[0][0] = res[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= m; ++j) {
      for (int k = 1; k <= min(i, l); ++k) {
        if (j >= k-1) {
          add(dp[i][j], dp[i-k][j-k+1]);
        }
        if (k != 1 && j >= k) {
          add(dp[i][j], dp[i-k][j-k]);
        }
        printf("%d %d = %d\n", i, j, dp[i-k][j]);
      }
    }
  cout << dp[n][m];
  return 0;
}

