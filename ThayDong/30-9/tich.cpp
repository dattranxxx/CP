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
const ll oo = 1e18;
const int N = 5000 + 1;
int a[N], b[N];
ll dp[N][N]; // dang o i,j; 0: day a dang tim begin, 1: day b dang tim begin, 2: dang di, 3: di xong
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  memset(dp, -0x3f, sizeof(dp));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      dp[i][j] = ll(a[i]) * b[j];
  ll res = -oo;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      res = max(res, dp[i][j]);
      if (i+1<n && j+1<n)
        dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + ll(a[i+1]) * b[j+1]);
    }
  }
  cout << res;
  return 0;
}

