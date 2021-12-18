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
  const string FILE_NAME = "cock";
  freopen((FILE_NAME + ".inp"),c_str(), "r", stdin);
  freopen((FILE_NAME + ".out"),c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 300 + 5;
int row[N+1][N], col[N][N+1], nxt[N+1][N], occ[N+1], cur[N+1];
int n, k;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    // (n+1)*n row grid and n*(n+1) col grid 
    for (int i = 0, x, y; i < k; ++i) {
      cin >> x >> y;
      // add row x-1, y-1 and x, y-1
      row[x-1][y-1] = row[x][y-1] = 1;
      // add col x-1, y-1 and x-1, y
      col[x-1][y-1] = col[x-1][y] = 1;
    }
    for (int h = 0; h <= n; ++h) {
      int cur = n;
      for (int c = n-1; ~c; --c) {
        if (row[h][c]) cur = c;
        nxt[h][c] = cur;
      } 
    }
    int res = 0;
    for (int h1 = 0; h1 <= n-1; ++h1) {
      memset(occ, 0, sizeof(occ));
      for (int h2 = h1 + 1; h2 <= n; ++h2) {
        occ[0] |= row[h2-1][0];
        cur[0] = occ[0];
        for (int c = 1; c <= n; ++c) {
          occ[c] |= col[h2-1][c];
          cur[c] = cur[c-1] + occ[c];
        }
        for (int c1 = 0; c1 < n; ++c1) {
          if (occ[c1]) continue;
          int c2 = min(nxt[h1][c1], nxt[h2][c1]);
          // count number of row occupied in [c1, c2]
          int los = cur[c2] - cur[c1];
          res += (c2 - c1) - los;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}

