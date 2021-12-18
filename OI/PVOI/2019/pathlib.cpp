
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
  const string FILE_NAME = "pathlib";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const ll oo = 1e18;
struct C {
  int v, w;
  C(int v, int w): v(v), w(w) {}
};
struct S {
  int u, t; ll d;
  S(int u, ll d): u(u), d(d), t(0) {}
  S(int u, int t, ll d): u(u), t(t), d(d) {}
  bool operator < (const S& s) const {
    return d > s.d;
  }
  friend ostream& operator << (ostream& os, S& s) {
    return os << s.u+1 << ' ' << s.t << ' ' << s.d;
  }
};
const int N = 1e5;
vector<C> G[N];
vector<int> T[N];
ll ds[N], dt[N], dp[N][3];
int n, m, st, en, U, V;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m >> st >> en >> U >> V; st--; en--; U--; V--;
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  priority_queue<S> q;
  memset(ds, 0x3f, sizeof(ds));
  ds[st] = 0;
  q.emplace(st, 0);
  while (!q.empty()) {
    S s = q.top(); q.pop();
    if (s.d != ds[s.u]) continue;
    for (C& c : G[s.u]) if (ds[s.u] + c.w < ds[c.v]) {
      ds[c.v] = ds[s.u] + c.w; 
      q.emplace(c.v, ds[c.v]);
    }  
  }
  memset(dt, 0x3f, sizeof(dt));
  dt[en] = 0;
  q.emplace(en, 0);
  while (!q.empty()) {
    S s = q.top(); q.pop();
    if (s.d != dt[s.u]) continue;
    for (C& c : G[s.u]) if (dt[s.u] + c.w < dt[c.v]) {
      dt[c.v] = dt[s.u] + c.w; 
      q.emplace(c.v, dt[c.v]);
    }  
  }
  memset(dp, 0x3f, sizeof(dp));
  q.emplace(U, 0, 0);
  dp[U][0] = 0;
  ll res = oo;
  while (!q.empty()) {
    S s = q.top(); q.pop();
    if (s.d != dp[s.u][s.t]) continue;
    if (s.u == V) res = min(res, s.d);
    for (C& c : G[s.u]) {
      int in = ds[s.u] + c.w + dt[c.v] == ds[en] || dt[s.u] + c.w + ds[c.v] == dt[st];
      int nxt = in; if (s.t == 1 && !in) nxt = 2;
      int w = s.t != 2 && in ? 0 : c.w;
      if ((c.v == st || c.v == en) && in) nxt = 2;
      if (dp[s.u][s.t] + w < dp[c.v][nxt]) {
        dp[c.v][nxt] = dp[s.u][s.t] + w;
        q.emplace(c.v, nxt, dp[c.v][nxt]);
      }
    }
  }
  cout << res;
  return 0;
}
