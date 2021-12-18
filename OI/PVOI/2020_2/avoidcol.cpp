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
void file() {
  const string FILE_NAME = "avoidcol";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 10;
struct C {
  int v, w;
  C(int v, int w): v(v), w(w) {}
};
vector<C> G[N];
int dp[N][2][1 << N], cnt[N][2][1 << N];
int n, m;
void call(int u, int t, int mask) {
  if (dp[u][t][mask] != -1) return;
  if (t == 0 && u == 0 && mask != 0) {
    dp[u][t][mask] = oo; cnt[u][t][mask] = 0; return;
  }
  if (t == 1 && u == 0) {
    dp[u][t][mask] = 0; cnt[u][t][mask] = 1; return;
  }
  dp[u][t][mask] = oo; cnt[u][t][mask] = 0;
  if (t == 0 && u == n-1) {
    for (C& c : G[u]) if (!(mask & (1 << c.v))) {
      call(c.v, 1, mask ^ (1 << c.v));
      if (dp[c.v][1][mask^(1<<c.v)] + c.w < dp[u][t][mask]) {
        dp[u][t][mask] = dp[c.v][1][mask^(1<<c.v)] + c.w;
        cnt[u][t][mask] = cnt[c.v][1][mask^(1<<c.v)];
      } else if (dp[c.v][1][mask^(1<<c.v)] == dp[u][t][mask]) {
        cnt[u][t][mask] += cnt[c.v][1][mask^(1<<c.v)];
      }
    }
    return;
  }
  for (C& c : G[u]) if (!(mask & (1 << c.v))) {
    call(c.v, t, mask ^ (1 << c.v));
    if (dp[c.v][t][mask^(1<<c.v)] + c.w < dp[u][t][mask]) {
      dp[u][t][mask] = dp[c.v][t][mask^(1<<c.v)] + c.w;
      cnt[u][t][mask] = cnt[c.v][t][mask^(1<<c.v)];
    } else if (dp[c.v][t][mask^(1<<c.v)] + c.w == dp[u][t][mask]) {
      cnt[u][t][mask] += cnt[c.v][t][mask^(1<<c.v)];
    }
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m;
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  memset(dp, -1, sizeof(dp));
  call(0, 0, 0);
  cout << cnt[0][0][0];
  return 0;
}

