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
const int oo = 1e9;
void file() {
  const string FILE_NAME = "mario";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int N = 700;
ll dis[N*N+N];
vector<pair<int, int>> G[N*N+N];
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0, u, v, w; i < n; ++i)
    for (int j = 0; j < m-1; ++j) {
      cin >> w; u = i*m+j, v = i*m+j+1;
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
  for (int i = 0, u, v, w; i < n-1; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> w; u = i*m+j, v = (i+1)*m+j;
      G[u].emplace_back(v, w);
      G[v].emplace_back(u, w);
    }
  priority_queue<pair<ll, int>> q;
  memset(dis, 0x3f, sizeof(dis));
  dis[0] = 0; ll d;
  q.emplace(0, 0);
  while (!q.empty()) {
    int u = q.top().second; d = -q.top().first; 
    q.pop();
    if (d != dis[u]) continue;
    for (auto& c : G[u]) {
      int v = c.first, w = c.second;
      if (dis[u] + w < dis[v]) {
        dis[v] = dis[u] + w;
        q.emplace(-dis[v], v);
      }
    }
  } 
  cout << dis[(n-1)*m+m-1];
  return 0;
}

