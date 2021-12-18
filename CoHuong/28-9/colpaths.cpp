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
void file() {
  const string FILE_NAME = "colpaths";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 3e5;
vector<vector<int>> G[N];
vector<ll> dp[N];
int n, m, k;
int col[N]; 
ll call(int u, int mask, int cnt) {
  if (dp[u][mask] != -1) return dp[u][mask];
  ll res = 1;
  if (cnt == k) return res;
  for (int v : G[u][mask]) 
    res += call(v, mask ^ (1 << col[v]), cnt + 1);
  return dp[u][mask] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i)
    cin >> col[i], col[i]--, G[i].resize(1 << k), dp[i].resize(1 << k, -1);
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v; u--; v--;
    for (int mask = 0; mask < (1 << k); ++mask) {
      if (mask & (1 << col[u]) && !(mask & (1 << col[v]))) 
        G[u][mask].emplace_back(v);
      if (mask & (1 << col[v]) && !(mask & (1 << col[u])))
        G[v][mask].emplace_back(u);
    }
  }
  if (k == 1) {
    cout << 0; return 0;
  }
  // n * 4!
  ll res = 0;
  for (int u = 0; u < n; ++u) 
    for (int v : G[u][1 << col[u]])
      res += call(v, (1 << col[u]) ^ (1 << col[v]), 2);
  cout << res;
  return 0;
}

