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
const int N = 1000;
vector<int> G[N];
int dis[N];
bool in[N];
int n, m, t;
string s;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m >> t >> s;
  for (int i = 0, u, v; i < m; ++i) {
    cin >> u >> v; u--; v--;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  int G_ = 0, Y_ = 0;
  queue<int> q;
  vector<int> pos_g, pos_y;
  for (int i = 0; i < n; ++i)
    if (s[i] == 'G') pos_g.emplace_back(i);
    else pos_y.emplace_back(i);
  for (int st = 0; st < n; ++st) {
    char ch = s[st];
    memset(dis, 0x3f, sizeof(dis));
    memset(in, 0, sizeof(in));
    dis[st] = 0; q.emplace(st);
    while (!q.empty()) {
      int u = q.front(); q.pop();
      in[u] = 0;
      for (int v : G[u]) {
        int w = 1; if (s[v] != ch) w += t;
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w; 
          if (!in[v]) {
            q.emplace(v); in[v] = 1;
          }
        }
      }
    }
    if (ch == 'G') 
      for (auto it = upper_bound(pos_g.begin(), pos_g.end(), st); it != pos_g.end(); it++) 
        G_ += dis[*it];
    else
      for (auto it = upper_bound(pos_y.begin(), pos_y.end(), st); it != pos_y.end(); it++) 
        Y_ += dis[*it];
  }
  cout << G_ << ' ' << Y_;
  return 0;
}
