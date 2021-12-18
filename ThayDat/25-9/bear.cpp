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
  const string FILE_NAME = "bear";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e4;
struct E {
  int u, v, w;
  E(int u, int v, int w): u(u), v(v), w(w) {}
  bool operator < (const E& c) const {
    return w < c.w;
  }
};
vector<E> e;
int S[N], li[N];
int n, m; 
ll res = 0;
int find(int u) {
  if (li[u] == u) return u;
  return li[u] = find(li[u]);
}
void unite(int u, int v, int w) {
  u = find(u); v = find(v);
  if (u == v) return;
  li[v] = u; res += w;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m; e.reserve(m);
  for (int i = 0; i < n; ++i)
    cin >> S[i], li[i] = i;
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    e.emplace_back(u, v, w);
  }
  for (E& c : e) c.w = c.w * 2 + S[c.u] + S[c.v];
  sort(e.begin(), e.end());
  for (E& c : e) unite(c.u, c.v, c.w);
  cout << res + S[0];
  return 0;
}

