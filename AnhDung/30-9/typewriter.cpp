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
const int N = 300;
string a[N+1];
int dp[N+1][N+1], cur[N+1][N+1], lcp[N+1]; // i, i-1
int n, k;
int __lcp(int i, int j) {
  int k = 0;
  for (; k < min(a[i].size(), a[j].size()); ++k)
    if (a[i][k] != a[j][k]) return k;
  return k;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i)
      lcp[i] = __lcp(i, i-1);
    for (int i = 1; i <= n; ++i) {
      cur[i][i] = a[i].size();
      for (int j = i + 1; j <= n; ++j) {
        cur[i][j] = cur[i][j-1] + (a[j-1].size() - lcp[j]) + (a[j].size() - lcp[j]);
      }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= i && j <= k; ++j) {
        dp[i][j] = dp[i-1][j];
        for (int l = 1; l <= j; ++l)
          dp[i][j] = min(dp[i][j], dp[i-l][j-l] + cur[i-l+1][i] + int(a[i].size()));
      }
    cout << dp[n][k] + k << '\n';
  }
  return 0;
}

