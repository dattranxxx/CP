/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
int n, m; 
int a[10], d[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int dp[N+1], tra[N+1];
int call(int cur) {
  if (cur == n) return dp[cur] = 0;
  if (dp[cur] != -1) return dp[cur];
  dp[cur] = -oo;
  for (int i = m-1; ~i; --i) if (cur + d[a[i]] <= n) {
    if (call(cur + d[a[i]]) + 1 > dp[cur]) {
      dp[cur] = dp[cur + d[a[i]]] + 1;
      tra[cur] = a[i];
    }
  }
  return dp[cur];
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) 
    cin >> a[i];
  memset(dp, -1, sizeof(dp));
  dp[0] = -oo;
  for (int i = m-1; ~i; --i) if (a[i] && d[a[i]] <= n) {
    if (call(d[a[i]]) + 1 > dp[0]) {
      dp[0] = dp[d[a[i]]] + 1;
      tra[0] = a[i];
    }
  }
  if (dp[0] <= 0) {
    cout << 0;
    return 0;
  }
  int cur = 0;
  while (cur < n) {
    cout << tra[cur]; cur += d[tra[cur]];
  }
  return 0;
}

