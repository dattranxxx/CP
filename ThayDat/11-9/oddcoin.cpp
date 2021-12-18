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
void file() {
  const string FILE_NAME = "addcoin";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
int coins[] = {1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000, -1};
int dp[int(1e5) + 1][16];
int call(int x, int i) {
  if (i == -1) return x == 0 ? 0 : oo;
  if (dp[x][i]) return dp[x][i];
  int res = call(x, i - 1);
  if (x >= coins[i]) res = min(res, call(x - coins[i], i) + 1);
  return dp[x][i] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  // {1, 3, 5, 10..}
  int x, t, q;
  cin >> q;
  while (q--) {
    cin >> x >> t; coins[15] = x;
    int res = 0, mx = max(coins[14], x);
    while (t - mx >= int(1e5)) t -= mx, res++;
    if (mx == x && t >= int(1e5)) {
      mx = coins[14];
      while (t - mx >= int(1e5)) t -= mx, res++;
    }
    cout << res + call(t, 15) << '\n';
  }
  return 0;
}

