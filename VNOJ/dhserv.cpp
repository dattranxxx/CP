/*                 ..... .
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
             .''....;coolc,'',;.                */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const ll oo = 1e18;
const int N = 500;
bool check[N];
ll dis[N][N];
int checked[N];
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int k, c = 0;
  cin >> n >> m >> k;
  memset(dis, 0x3f, sizeof(dis));
  ll inf = dis[0][0];
  for (int i = 0; i < n; ++i) dis[i][i] = 0;
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    dis[u][v] = w;
  }
  for (int i = 0, t, u, v; i < k; ++i) {
    cin >> t;
    if (t == 1) {
      cin >> u; u--;
      if (check[u]) continue;
      check[u] = 1;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          dis[i][j] = min(dis[i][j], dis[i][u] + dis[u][j]);
      for (int d = 0, i = checked[d]; d < c; ++d, i = checked[d]) 
        for (int j = 0; j < n; ++j)
          dis[u][j] = min(dis[u][j], dis[u][i] + dis[i][j]),
          dis[j][u] = min(dis[j][u], dis[j][i] + dis[i][u]);
      checked[c] = u; c++;
    } else {
      cin >> u >> v; u--; v--;
      cout << (dis[u][v] == inf ? -1 : dis[u][v]) << '\n';
    }
  }
  return 0;
}

