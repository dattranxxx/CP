/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1000, M = 10000;
int w[N], v[N], dp[M+1];
int n_, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n_ >> m;
  int n = 0;
  for (int i = 0, wei, val, cnt; i < n_; ++i) {
    cin >> wei >> val >> cnt;
    for (int b = 0; cnt >= (1 << b); ++b) {
      w[n] = wei * (1 << b);
      v[n] = val * (1 << b);
      n++; cnt -= (1 << b);
    }
    if (cnt) {
      w[n] = wei * cnt;
      v[n] = val * cnt;
      n++;
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = m; j >= w[i]; --j) 
      dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
  cout << dp[m];
  return 0;
}
