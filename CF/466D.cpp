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
const int oo = 1e9, M = 1e9 + 7;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
int mul(ll x, ll y) {
  return x * y % M;
}
const int N = 2001;
int a[N], nxt[N], cur[N];
int n, h;
ent main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> h;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  cur[0] = 1;
  for (int i = 0; i < n; ++i) {
    memset(nxt, 0, sizeof(nxt));
    for (int j = 0; j <= i; ++j) if (cur[j]) {
      if (a[i] + j + 1 == h) {
        // []
        add(nxt[j], cur[j]);
        // ][
        if (j) add(nxt[j], mul(cur[j], j));
        // [
        add(nxt[j+1], cur[j]);
      } else if (a[i] + j == h) {
        // .
        add(nxt[j], cur[j]);
        // ]
        if (j) add(nxt[j-1], mul(cur[j], j));
      } 
    }
    swap(cur, nxt);
  }
  cout << cur[0];
  return 0;
}
