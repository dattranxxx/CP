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
int n, m, x, y, u, v; 
const int maxn = 200, maxm = 200;
int a[maxn+2][maxm+2], vis[maxn+2][maxm+2]; 
pair<pii, pii> len(int cx, int cy, int cu, int cv) {
  if (!a[cx - 1][cy]) cx--;
  if (!a[cu - 1][cv]) cu--;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
pair<pii, pii> phai(int cx, int cy, int cu, int cv) {
  if (!a[cx][cy + 1]) cy++;
  if (!a[cu][cv + 1]) cv++;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
pair<pii, pii> xuong(int cx, int cy, int cu, int cv) {
  if (!a[cx + 1][cy]) cx++;
  if (!a[cu + 1][cv]) cu++;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
pair<pii, pii> trai(int cx, int cy, int cu, int cv) {
  if (!a[cx][cy - 1]) cy--;
  if (!a[cu][cv - 1]) cv--;
  return make_pair(make_pair(cx, cy), make_pair(cu, cv));
}
void solve() {
  cin >> n >> m >> x >> y >> u >> v;
  x++; y++; u++; v++;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) cin >> a[i][j];
  for (int i = 0; i <= n+1; ++i) a[i][0] = a[i][m+1] = 1;
  for (int i = 1; i <= m+1; ++i) a[0][i] = a[n+1][i] = 1;
  queue<pair<pair<pii, pii>, string>> q; 
  q.push(make_pair( make_pair(make_pair(x, y), make_pair(u, v)), "" ));
  while (!q.empty()) {
    int cx = q.front().X.X.X, cy = q.front().X.X.Y;
    int cu = q.front().X.Y.X, cv = q.front().X.Y.Y;
    string s = q.front().Y; q.pop();
    if (cx == 1 && cy == 1 && cu == 1 && cv == 1) {
      cout << s.size() << '\n' << s;
      return;
    }
    if (cx == 1 && cy == 1) {
      swap(cx, cu); swap(cy, cv);
      pair<pair<pii, pii>, string> cur = {{{cx, cy}, {cu, cv}}, s};
      q = queue<pair<pair<pii, pii>, string>>();
      q.push(cur);
      memset(vis, 0, sizeof(vis));
    }
    if (vis[cx][cy]) continue; vis[cx][cy] = 1;
    q.push(make_pair( len(cx, cy, cu, cv), s + 'U' ));
    q.push(make_pair( phai(cx, cy, cu, cv), s + 'R' ));
    q.push(make_pair( xuong(cx, cy, cu, cv), s + 'D' ));
    q.push(make_pair( trai(cx, cy, cu, cv), s + 'L' ));
  }

}

int main() {
  solve(); // NHO TINH DO PHUC TAP KHONG DE TRAN SO
  return 0;
}
