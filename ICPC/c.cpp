#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 100, K = 2;
ll dp[N+1][N+1];
int p[N+1], nxt[N+1][K];
using ld = long double;
string s;
int n = 100, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s; 
    m = s.size(); 
    s = ' ' + s;
    p[1] = 0;
    for (int i = 2; i <= m; ++i) {
      int k = p[i-1];
      while (k > 0 && s[k+1] != s[i]) k = p[k];
      if (s[k+1] == s[i]) p[i] = k+1;
    }

    nxt[0][s[1] - '0'] = 1; 
    for (int i = 1; i < m; ++i) {
      for (int c = 0; c < K; ++c) {
       char ch = c + '0';
        if (ch == s[i+1]) { 
           nxt[i][c] = i+1; continue;
        }
        int k = p[i];
        while (k > 0 && s[k+1] != ch) k = p[k];
        if (s[k+1] == ch) nxt[i][c] = k+1;
      }
    }
    dp[0][0] = 1; 
    for (int i = 0; i < n; ++i) {
      for (int d = 0; d <= m; ++d) {
        for (int c = 0; c < K; ++c) {
          if (d == m) dp[i+1][d] += dp[i][d];
          else dp[i+1][nxt[d][c]] += dp[i][d]; 
        }
      }
    }
    ld res = 0;
    for (int i = m; i <= 100; ++i)
      res += dp[i-m][0] * 1.0 / pow(2, i) * i;
    cout << res << '\n';
  }
  return 0;
}

