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
const int N = 200, MX = 3575;
int dp[2][N+1][MX+1][2];
int a[N], b[N];
int n, k;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  ll x;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    while (x % 2 == 0) {
      x /= 2; a[i] += 1;
    }
    while (x % 5 == 0) {
      x /= 5; b[i] += 1;
    }
  }

  memset(dp, -1, sizeof(dp));
  dp[0][0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    int cur = i & 1, nxt = cur ^ 1;
    memset(dp[nxt], -1, sizeof(dp[nxt]));
    for (int j = 0; j <= i; ++j) {
      for (int cnt = 0; cnt <= MX; ++cnt) {
        // cnt_2
        if (dp[cur][j][cnt][0] != -1) {
          dp[nxt][j][cnt][0] = max(dp[nxt][j][cnt][0], dp[cur][j][cnt][0]);
          if (a[i] + cnt >= b[i]) {
            int nx = min(MX, cnt + a[i] - b[i]);
            dp[nxt][j + 1][nx][0] = max(dp[nxt][j + 1][nx][0], dp[cur][j][cnt][0] + b[i]);
          } else {
            int nx = min(MX, b[i] - cnt - a[i]);
            dp[nxt][j + 1][nx][1] = max(dp[nxt][j + 1][nx][1], dp[cur][j][cnt][0] + a[i] + cnt);
          }
        }
        // cnt_5
        if (dp[cur][j][cnt][1] != -1) {
          dp[nxt][j][cnt][1] = max(dp[nxt][j][cnt][1], dp[cur][j][cnt][1]);
          if (b[i] + cnt >= a[i]) {
            int nx = min(MX, b[i] + cnt - a[i]);
            dp[nxt][j + 1][nx][1] = max(dp[nxt][j + 1][nx][1], dp[cur][j][cnt][1] + a[i]);
          } else {
            int nx = min(MX, a[i] - cnt - b[i]);
            dp[nxt][j + 1][nx][0] = max(dp[nxt][j + 1][nx][0], dp[cur][j][cnt][1] + b[i] + cnt);
          }
        }
      }
    }
  }
  int res = 0;
  for (int i = 0; i <= MX; ++i)
    res = max(res, max(dp[n&1][k][i][0], dp[n&1][k][i][1]));
  cout << res;
  return 0;
}

