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
/* 
 * Author :  shora
 * Date   :  2021 Jul 07 03:27:03 PM
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cout << _ << ' ';} cout << endl;
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
using ll = long long;
ostream& operator << (ostream& os, const pii& p) {
  return os << p.X << ' ' << p.Y;
}
int n, m, x, y, u, v; 
const int maxn = 200, maxm = 200;
int a[maxn+2][maxm+2], vis[maxn+2][maxm+2]; 
pair<pii, pii> len(pair<pii, pii>& cur) {
  int cx = cur.X.X, cy = cur.X.Y, cu = cur.Y.X, cv = cur.Y.Y;
  if (!a[cx - 1][cy]) cx--;
  if (!a[cu - 1][cv]) cu--;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
pair<pii, pii> phai(pair<pii, pii>& cur) {
  int cx = cur.X.X, cy = cur.X.Y, cu = cur.Y.X, cv = cur.Y.Y;
  if (!a[cx][cy + 1]) cy++;
  if (!a[cu][cv + 1]) cv++;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
pair<pii, pii> xuong(pair<pii, pii>& cur) {
  int cx = cur.X.X, cy = cur.X.Y, cu = cur.Y.X, cv = cur.Y.Y;
  if (!a[cx + 1][cy]) cx++;
  if (!a[cu + 1][cv]) cu++;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
pair<pii, pii> trai(pair<pii, pii>& cur) {
  int cx = cur.X.X, cy = cur.X.Y, cu = cur.Y.X, cv = cur.Y.Y;
  if (!a[cx][cy - 1]) cy--;
  if (!a[cu][cv - 1]) cv--;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
pair<pii, char> trace[maxn+2][maxm+2];
void solve() {
  cin >> n >> m >> x >> y >> u >> v;
  x++; y++; u++; v++;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  for (int i = 0; i <= n+1; ++i) a[i][0] = a[i][m+1] = 1;
  for (int i = 1; i <= m+1; ++i) a[0][i] = a[n+1][i] = 1;
  queue<pair<pii, pii>> q; 
  pair<pii, pii> src = {{x, y}, {u, v}};
  q.push(src);
  pii start_xy = {x, y}, one = {1, 1};
  string res;
  while (!q.empty()) {
    pair<pii, pii> cur = q.front(); q.pop();
    if (cur.X == one) {
      pii cur_xy = cur.X; string t;
      while (cur_xy != start_xy) {
        t += trace[cur_xy.X][cur_xy.Y].second;
        cur_xy = trace[cur_xy.X][cur_xy.Y].first;
      }
      reverse(t.begin(), t.end());
      res += t;
      if (cur.Y == one) {
        cout << res.size() << '\n' << res;
        return;
      }
      swap(cur.X, cur.Y);
      start_xy = cur.X;
      memset(vis, 0, sizeof(vis));
      q = queue<pair<pii, pii>>();
      q.push(cur);
    }
    if (vis[cur.X.X][cur.X.Y]) continue; 
    vis[cur.X.X][cur.X.Y] = 1;

    pair<pii, pii> nxt;

    nxt = len(cur);
    trace[nxt.X.X][nxt.X.Y] = {cur.X, 'U'};
    q.push(nxt);

    nxt = phai(cur);
    trace[nxt.X.X][nxt.X.Y] = {cur.X, 'R'};
    q.push(nxt);

    nxt = xuong(cur);
    trace[nxt.X.X][nxt.X.Y] = {cur.X, 'D'};
    q.push(nxt);

    nxt = trai(cur);
    trace[nxt.X.X][nxt.X.Y] = {cur.X, 'L'};
    q.push(nxt);
  }
}

int main() {
  solve(); // NHO TINH DO PHUC TAP KHONG DE TRAN SO
  return 0;
}
