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
const int N = 2e3 + 1, M = 5e5;
int p_a[N], p_b[N], res[N];
vector<int> r_a[N], r_b[N], a[N], b[N];
int n, m, root;
bool cnt[M+1];
void dfs(int u, int e) {
  for (int x : r_a[u]) cnt[x] = 1;
  for (int v = u; v; v = p_b[v])
    for (int x : r_b[v]) res[u] += cnt[x];
  for (int v : a[u]) dfs(v, u);
  for (int x : r_a[u]) cnt[x] = 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1, u, v; i <= n; ++i) {
    cin >> v >> u; 
    p_a[i] = u; p_b[i] = v;
    a[u].push_back(i);
    if (u == 0) root = i;
  }
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> v >> u; 
    r_a[u].push_back(i);
    r_b[v].push_back(i);
  }
  dfs(root, 0);
  for (int i = 1; i <= n; ++i)
    cout << res[i] << '\n';
  /*
  for (int u = 1; u <= n; ++u) {
    set<int> cur; int res = 0;
    for (int v = u; v; v = p_a[v]) 
      for (int x : r_a[v]) cur.insert(x);
    for (int v = u; v; v = p_b[v])
      for (int x : r_b[v]) res += cur.count(x);
    cout << res << '\n';
  }
  */
  return 0;
}

