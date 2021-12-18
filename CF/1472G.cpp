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
const int oo = 1e9;
const int N = 2e5;
vector<int> G[N];
int dis[N];
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) G[i].clear();
    for (int i = 0, u, v; i < m; ++i) {
      cin >> u >> v; u--; v--;
      G[u].push_back(v);
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    priority_queue<pair<int, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
      int u = q.top().second, d = -q.top().first;
      q.pop();
      if (d != dis[u]) continue;
      for (int v : G[u]) if (dis[u] + 1 < dis[v]) {
        dis[v] = dis[u] + 1;
        q.emplace(-dis[v], v);
      } 
    }
    vector<int> nodes(n), dp(n);
    iota(nodes.begin(), nodes.end(), 0);
    sort(nodes.begin(), nodes.end(), [&](int u, int v) {
      return dis[u] > dis[v]; 
    });
    for (int i = 0, u = nodes[i]; i < n; ++i, u = nodes[i]) {
      dp[u] = dis[u];
      for (int v : G[u]) {
        if (dis[v] > dis[u]) dp[u] = min(dp[u], dp[v]);
        else dp[u] = min(dp[u], dis[v]);
      }
    } 
    for (int i = 0; i < n; ++i)
      cout << dp[i] << ' ';
    cout << '\n';
  }
  return 0;
}

