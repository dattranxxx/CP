#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
void file() {
  const string FILE_NAME = "painting";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e6, M = 1e9 + 7;
int add(int x, int y) {
  return x + y >= M ? x + y - M : x + y;
}
int sub(int x, int y) {
  return x - y < 0 ? x - y + M : x - y;
}
int mul(ll x, ll y) {
  return x * y % M;
}
int pw(int x, int k) {
  int res = 1;
  for (; k; k >>= 1, x = mul(x, x))
    if (k & 1) res = mul(res, x);
  return res;
}
int n, m, k;
int dp[N + 1];
int calc() {
  dp[0] = 1;
  dp[1] = m;
  for (int i = 2; i <= n; ++i) {
    if (i < k) dp[i] = mul(dp[i-1], m);
    else if (i > k) dp[i] = sub(mul(dp[i-1], m), mul(dp[i-k], m-1));
    else dp[i] = mul(m, sub(dp[i-1], dp[i-k]));
  }
  return dp[n];
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m >> k;
  cout << sub(pw(m, n), calc());
  return 0;
}

