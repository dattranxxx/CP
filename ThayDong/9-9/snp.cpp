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
const int N = 1e5;
int dp[N+1][350];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  int res = 0;
  dp[1][1] = 1;
  for (int i = 2; i <= n; ++i)
    for (int k = 1; k * k <= i; ++k) {
      add(dp[i][k], dp[i-k][k]);
      if (i - 1 - 2 * (k - 1) >= 0) 
        add(dp[i][k], dp[i-1-2*(k-1)][k-1]);
      if (i == n) add(res, dp[i][k]);
    }
  cout << res;
  return 0;
}

