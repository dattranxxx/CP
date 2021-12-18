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
const int oo = 1e9, M = 1e9 + 7;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
int mul(ll x, ll y) {
  return x * y % M;
}
const int N = 200, K = 1000;
int cur[N/2+1][K+1], nxt[N/2+1][K+1], a[N];
int n, k;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  cur[0][0] = cur[1][0] = 1;
  for (int i = 0; i < n-1; ++i) {
    memset(nxt, 0, sizeof(nxt));
    for (int j = 0; j <= i + 1 && j <= n / 2; ++j)
      for (int s = 0; s <= k; ++s) if (cur[j][s]) {
        if (s + j * (a[i+1] - a[i]) > k) continue;
        int nxt_s = s + j * (a[i+1] - a[i]);
        // ai+1 only segment
        add(nxt[j][nxt_s], cur[j][s]);
        // add ai+1 to any of open set
        add(nxt[j][nxt_s], mul(cur[j][s], j));
        // use ai+1 to open a new set
        if ((j + 1) <= n / 2) add(nxt[j+1][nxt_s], cur[j][s]);
        // use ai+1 to close any of open set
        if (j) add(nxt[j-1][nxt_s], mul(cur[j][s], j));
      }
    swap(cur, nxt);
  }
  int res = 0;
  for (int i = 0; i <= k; ++i)
    add(res, cur[0][i]);
  cout << res;
  return 0;
}

