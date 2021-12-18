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
const int N = 5e3;
struct S {
  int h, p;
  S(): h(0), p(0) {}
  bool operator < (const S& s) const {
    return h + p < s.h + s.p;
  }
};
S a[N];
ll dp[N][N+1];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) 
    cin >> a[i].h >> a[i].p;
  sort(a, a + n);
  // dp[i][j] la toynano nho nhat xet den i va chon j cai
  memset(dp, 0x3f, sizeof(dp)); 
  ll inf = dp[0][0];
  dp[0][0] = 0; dp[0][1] = a[0].p;
  for (int i = 1; i < n; ++i)
    for (int j = 0; j <= i + 1; ++j) {
      dp[i][j] = dp[i-1][j];
      if (a[i].h >= dp[i-1][j-1]) 
        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + a[i].p);
    }
  int res = 0;
  for (int i = 1; i <= n; ++i) 
    if (dp[n-1][i] != inf) res = i;
  cout << res;
  return 0;
}

