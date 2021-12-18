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
const int N = 10;
int dp[N+1][1001];
int a[N], b[N], c[N], d[N];
int n, m, c0, d0;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> m >> n >> c0 >> d0;
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) 
    for (int j = 0; j <= m; ++j) if (dp[i][j] != -1) 
      for (int k = 0; j + c[i] * k <= m && k * b[i] <= a[i]; ++k) 
        dp[i + 1][j + c[i] * k] = max(dp[i + 1][j + c[i] * k], dp[i][j] + d[i] * k);
  int res = 0;
  for (int i = 0; i <= m; ++i) {
    res = max(res, dp[n][i] + ((m - i) / c0) * d0);
  }
  cout << res;
  return 0;
}

