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
  const string FILE_NAME = "orchid";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
struct C {
  int v, w;
  C(int v, int w): v(v), w(w) {}
};
const int N = 1e5;
vector<C> G[N];
int res[N], dp_best[N], dp_second[N], best[N];
void build(int u, int e) {
  for (C& c : G[u]) if (c.v != e) {
    build(c.v, u);
    if (dp_best[c.v] + c.w > dp_best[u]) {
      dp_best[u] = dp_best[c.v] + c.w;
      best[u] = c.v;
    }
  }
  for (C& c : G[u]) if (c.v != e && c.v != best[u])
    dp_second[u] = max(dp_second[u], dp_best[c.v] + c.w);
}
void dfs(int u, int e, int dp_from_parent) {
  res[u] = max(dp_best[u], dp_from_parent);
  for (C& c : G[u]) if (c.v != e) {
    if (c.v != best[u]) {
      dfs(c.v, u, max(dp_best[u], dp_from_parent) + c.w);
    } else {
      dfs(c.v, u, max(dp_second[u], dp_from_parent) + c.w);
    } 
  }
} 
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0, u, v, w; i < n-1; ++i) {
    cin >> u >> v >> w; u--; v--;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  build(0, 0);
  dfs(0, 0, 0);
  for (int i = 0; i < n; ++i)
    cout << res[i] << ' ';
  return 0;
}

