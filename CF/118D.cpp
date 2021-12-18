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
const int oo = 1e9, M = 1e8;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
const int N = 100, K = 10;
int dp[N+1][N+1][K+1][K+1];
int n1, n2, k1, k2;
int call(int c1, int c2, int l1, int l2) {
  if (c1 == n1 && c2 == n2) return 1; 
  if (dp[c1][c2][l1][l2] != -1)
    return dp[c1][c2][l1][l2];
  int res = 0;
  if (c1 != n1 && l1 != k1) add(res, call(c1 + 1, c2, l1 + 1, 0));
  if (c2 != n2 && l2 != k2) add(res, call(c1, c2 + 1, 0, l2 + 1));
  return dp[c1][c2][l1][l2] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n1 >> n2 >> k1 >> k2;
  memset(dp, -1, sizeof(dp));
  cout << call(0, 0, 0, 0);
  return 0;
}

