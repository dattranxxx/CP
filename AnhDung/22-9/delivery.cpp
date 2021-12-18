                 /*..... .
                 .';:;;;;'':.
                .:::::::::cl'
                .c;;o,.cc::::.
                ';l:.. ..;;;;.
                 .,::.'',:...
                  '.'cxdo;..d.
                  d..:olo.'dO.
                  kk. .. :kOO.
                 .k0k...'000d.
                  c00'.,00k:..
                  l00..xOk;..co'
                 .l00cdOO, ...oO;.
           .,;;. .:ld::do  .  .OOx'.
       ,cokcc,......;. ..      oOO00Oooc'
    .oOOOc..... .......      ..oK000OOOOOl.
   :OOOO:....    .'...      .lO0KK000OOOOOOo.
   ,OOO00;  ..   .           x0KK0000OOOOOOO:.
    'ck00k.  ...  ...... ... ':000OOOOOOOOOk;.
      :OOO0kdld:':O0:.,,,l'.':'OOOOOOo:l:;'.
       .;ooolOOOOOO000O00000OOOOOOx:..
             .''....;coolc,'',;.*/
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
struct S {
  int i, u, t; ll d;
  S(int i, int u, int t, ll d): i(i), u(u), t(t), d(d) {}
  bool operator < (const S& s) const {
    return d > s.d;
  }
};
const int oo = 1e9;
const int N = 100, K = 5000;
int s[K], t[K];
ll dis[N][N], dp[K + 1][N][3];
int n, m, k;
void solve() {
  cin >> n >> m >> k;
  memset(dis, 0x3f, sizeof(dis)); 
  ll inf = dis[0][0];
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    dis[u][v] = dis[v][u] = min(dis[u][v], ll(w));
  }
  for (int i = 0; i < k; ++i) 
    cin >> s[i] >> t[i], s[i]--, t[i]--;
  for (int i = 0; i < n; ++i) 
    dis[i][i] = 0;
  for (int k = 0; k < n; ++k) 
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
  // ko co i/ co i / co i, i + 1
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0][0] = 0;
  priority_queue<S> q;
  q.emplace(0, 0, 0, 0);
  while (!q.empty()) {
    S c = q.top(); q.pop();
    if (c.d != dp[c.i][c.u][c.t] || c.i == k) continue;
    if (c.t == 0) {
      // lay hang e
      if (c.d + dis[c.u][s[c.i]] < dp[c.i][s[c.i]][1]) {
        dp[c.i][s[c.i]][1] = c.d + dis[c.u][s[c.i]];
        q.emplace(c.i, s[c.i], 1, dp[c.i][s[c.i]][1]);
      }
    } 
    if (c.t == 1) {
      // di giao hang 
      if (c.d + dis[c.u][t[c.i]] < dp[c.i + 1][t[c.i]][0]) {
        dp[c.i + 1][t[c.i]][0] = c.d + dis[c.u][t[c.i]];
        q.emplace(c.i + 1, t[c.i], 0, dp[c.i + 1][t[c.i]][0]);
      }
      // di lay i + 1
      if (c.i < k-1 && c.d + dis[c.u][s[c.i + 1]] < dp[c.i][s[c.i + 1]][2]) {
        dp[c.i][s[c.i + 1]][2] = c.d + dis[c.u][s[c.i + 1]];
        q.emplace(c.i, s[c.i + 1], 2, dp[c.i][s[c.i + 1]][2]);
      }
    }
    if (c.t == 2) {
      // di giao hang e
      if (c.d + dis[c.u][t[c.i]] < dp[c.i + 1][t[c.i]][1]) {
        dp[c.i + 1][t[c.i]][1] = c.d + dis[c.u][t[c.i]];
        q.emplace(c.i + 1, t[c.i], 1, dp[c.i + 1][t[c.i]][1]);
      } 
    }
  }
  cout << (dp[k][t[k-1]][0] == inf ? -1 : dp[k][t[k-1]][0]) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
}

