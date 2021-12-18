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
const int N = 1e4, M = 1e3, MOD = 1e9 + 7;
void add(int& x, int y) {
  x += y; if (x >= MOD) x -= MOD;
}
int dp[2][M];
int n, m;
string s;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> m >> n >> s;
  // dp[i][j] la so xau con xet den i co chenh lech R - L = j
  for (int i = 0; i < n; ++i) {
    int cur = i & 1, nxt = cur ^ 1, c = s[i] == 'R' ? 1 : -1;
    memset(dp[nxt], 0, sizeof(dp[nxt]));
    if (c == 1) dp[nxt][c] += 1;
    for (int j = 0; j < m; ++j) 
      add(dp[nxt][j], dp[cur][j]);
    for (int j = 0; j < m; ++j) if (0<=j+c&&j+c<m)  
      add(dp[nxt][j+c], dp[cur][j]);
  }
  cout << dp[n&1][0];
  return 0;
}

