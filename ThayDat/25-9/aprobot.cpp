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
const int N = 5000;
int a[N], b[N], min_g[N], max_g[N], dp[N][N+1];
int n, k;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; ++i) 
    cin >> a[i], b[i] = a[i];
  sort(b, b + n, greater<int>());
  int min_index, max_index, lo, hi, mid, res = 0;
  for (int i = 0; i < n; ++i) {
    min_index = -1, max_index = -1;
    lo = 0, hi = n-1;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (b[mid] <= a[i]) {
        min_index = mid;
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    lo = 0, hi = n-1;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (b[mid] >= a[i]) {
        max_index = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    min_g[i] = min_index; max_g[i] = max_index;
  }
  // xet den i lay j cai
  dp[0][0] = 1; dp[0][1] = min_g[0]/k <= 0 && 0 <= max_g[0]/k;
  for (int i = 1; i < n; ++i)
    for (int j = 0; j <= (i + 1); ++j) {
      dp[i][j] |= dp[i-1][j];
      // lay i
      if (min_g[i]/k <= i/k && i/k <= max_g[i]/k) 
        dp[i][j] |= dp[i-1][j-1];
    }
  for (int i = 0; i <= n; ++i)
    if (dp[n-1][i]) res = i;
  cout << n - res;
  return 0;
}

