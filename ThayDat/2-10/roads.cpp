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
const int N = 1e5;
struct E {
  int u, v, w;
  E(): u(0), v(0), w(0) {}
  bool operator < (const E& e) const {
    return w < e.w;
  }
} e[N];
struct C {
  int v, i;
  C(int v, int i): v(v), i(i) {}
};
vector<C> G[N];
int n, m, root;
int A[N], B[N], dep[N], up[N][17], dp[N][17], up_e[N], li[N];
void dfs(int u, int p, int _) {
  dep[u] = dep[p] + 1;
  up[u][0] = p;
  dp[u][0] = _ == -1 ? -oo : e[_].w;
  up_e[u] = _;
  li[u] = u;
  for (int i = 1; i <= 16; ++i)
    up[u][i] = up[up[u][i-1]][i-1],
    dp[u][i] = max(dp[u][i-1], dp[up[u][i-1]][i-1]);
  for (C& c : G[u]) if (c.v != p)
    dfs(c.v, u, c.i);
}
pair<int, int> lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  int res = -oo;
  for (int i = 16; ~i; --i) 
    if (dep[u] - dep[v] >= (1 << i))
      res = max(res, dp[u][i]),
      u = up[u][i];
  if (u == v) return {u, res};
  for (int i = 16; ~i; --i) 
    if (up[u][i] != up[v][i]) 
      res = max(res, max(dp[u][i], dp[v][i])),
      u = up[u][i], v = up[v][i];
  return {up[u][0], max(res, max(dp[u][0], dp[v][0]))};
}
int find(int u) {
  if (u == li[u]) return u;
  return li[u] = find(li[u]);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].w; 
    e[i].u--; e[i].v--;
    if (i < n-1) {
      G[e[i].u].emplace_back(e[i].v, i);
      G[e[i].v].emplace_back(e[i].u, i);
    }
    A[i] = oo; B[i] = oo; // minimize a
  }
  root = e[0].u;
  dfs(root, root, -1); 
  vector<int> idx(m - n + 1);
  for (int i = n - 1; i < m; ++i)
    idx[i - n + 1] = i;
  sort(idx.begin(), idx.end(), [&](int u, int v){
    return e[u] < e[v];
  });
  for (int i : idx) {
    auto l = lca(e[i].u, e[i].v);
    B[i] = e[i].w - l.second;
    for (int u = find(e[i].u); dep[u] > dep[l.first]; u = find(u)) 
      A[up_e[u]] = e[i].w,
      li[u] = up[u][0];
    for (int v = find(e[i].v); dep[v] > dep[l.first]; v = find(v)) 
      A[up_e[v]] = e[i].w,
      li[v] = up[v][0];
  }
  for (int i = 0; i < n; ++i)
    if (A[i] != oo) A[i] -= e[i].w;
  ll res = 0;
  for (int i = 0; i < m; ++i) {
    res += ll(i + 1) * (A[i] == oo ? -1 : A[i]);
    res += ll(i + 1) * (i + 1) * (B[i] == oo ? -1 : B[i]);
  }
  cout << res;
  return 0;
}

