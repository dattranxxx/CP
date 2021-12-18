/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
void file() {
  const string FILE_NAME = "bus";
  freopen((FILE_NAME + ".inp"), "r", stdin);
  freopen((FILE_NAME + ".out"), "w", stdout);
}
struct C {
  int v, w;
  C(int v, int w): v(v), w(w) {}
};
struct S {
  int u; ll dis;
  S(int u, ll dis): u(u), dis(dis) {}
  bool operator < (const S& s) const {
    return dis > s.dis;
  }
};
const int N = 1e5;
vector<C> G[N];
ll dis[N];
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m;
  for (int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w; u--; v--;
    G[u].push_back(C(v, w));
    G[v].push_back(C(u, w));
  }
  int Q;
  cin >> Q;
  priority_queue<S> q;
  for (int i = 0, st, en; i < Q; ++i) {
    cin >> st >> en; st--; en--;
    memset(dis, 0x3f, sizeof(dis));
    dis[st] = 0; q.push(S(st, 0));
    while (!q.empty()) {
      S s = q.top(); q.pop();
      if (s.dis != dis[s.u]) continue;
      for (C& c : G[s.u]) 
        if (dis[s.u] + c.w < dis[c.v]) {
          dis[c.v] = dis[s.u] + c.w;
          q.push(S(c.v, dis[c.v]));
        }
    }
    cout << dis[en] << '\n';
  }
  return 0;
}

