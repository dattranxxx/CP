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
const int N = 700;
int dis[N], D[N], U[N], deg[N]; 
int n, m;
vector<int> E[N];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v;
    E[u].emplace_back(v);
    E[v].emplace_back(u); 
  }
  int T, s, e;
  cin >> T;
  queue<int> q;
  while (T--) {
    cin >> s >> e;
    int size = n;
    for (int i = 0; i < n; ++i) U[i] = i;
    memset(dis, -1, sizeof(dis));
    swap(U[s], U[size-1]); size--;
    q.emplace(s); dis[s] = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : E[u]) D[v] = 1;
      for (int i = 0; i < size; ++i) if (!D[U[i]]) {
        q.emplace(U[i]);
        dis[U[i]] = dis[u] + 1;
        swap(U[i], U[size-1]); size--; i--;
      }
      for (int v : E[u]) D[v] = 0;
    }
    cout << dis[e] << '\n';
  }
  return 0;
}

