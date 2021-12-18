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
const int N = 5e3;
int w, h, n;
bool no[N][N], vis[N * N];
vector<int> G[N * N];
int dfs(int u) {
  int res = 1;
  for (int v : G[u]) if (!vis[v]) 
   vis[v] = 1, res += dfs(v);
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> w >> h;
  cin >> n;
  for (int i = 0, a, b, c, d; i < n; ++i) {
    cin >> a >> b >> c >> d;
    if (a == c && b == d) continue;
    if (a == c) { // x1 = x2
      if (a <= 0 || a >= w) continue;
      if (b > d) swap(b, d);
      b = max(0, b); b = min(b, h);
      d = max(0, d); d = min(d, h);
      for (int j = b; j < d; ++j) {
        // no more canh giua (a-1, j) va (a, j)
        int u = j * w + a-1, v = j * w + a;
        no[u][v] = no[v][u] = 1;
      }
    } else { // b == d
      if (b <= 0 || b >= h) continue;
      if (a > c) swap(a, c); 
      a = max(0, a); a = min(a, w);
      c = max(0, c); c = min(c, w);
      for (int j = a; j < c; ++j) {
        int u = (b-1) * w + j, v = b * w + j;
        no[u][v] = no[v][u] = 1;
      }
    }
  }
    for (int i = 0, u, v; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        u = i * w + j;
        if (i > 0) {
          v = (i - 1) * w + j;
          if (!no[u][v]) {
            G[u].emplace_back(v);
          }
        }
        if (j > 0) {
          v = i * w + j - 1;
          if (!no[u][v]) {
            G[u].emplace_back(v);
          }
        }
        if (i+1 < h) {
          v = (i + 1) * w + j;
          if (!no[u][v]) {
            G[u].emplace_back(v);
          }
        }
        if (j+1 < w) {
          v = i * w + j + 1;
          if (!no[u][v]) {
            G[u].emplace_back(v);
          }
        }
      }
    }
    vector<int> res;
    for (int i = 0; i < w*h; ++i) if (!vis[i]) {
      vis[i] = 1; res.emplace_back(dfs(i));
    }
    sort(res.rbegin(), res.rend());
    for (int x : res)
      cout << x << '\n';
  return 0;
}
