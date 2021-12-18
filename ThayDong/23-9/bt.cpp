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
const int M = 1e9;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
using ll = long long;
const int oo = 1e9;
int a[10], b[10], dp[10][1001][1001];
int n, A, B;
int call(int pos, int curA, int curB) {
  if (pos == n) return curA == A && curB == B;
  if (dp[pos][curA][curB] != -1) return dp[pos][curA][curB];
  int res = 0;
  for (int x = 0; curA + x*a[pos] <= A && curB + x*b[pos] <= B; ++x) 
    add(res, call(pos + 1, curA + x*a[pos], curB + x*b[pos]));
  return dp[pos][curA][curB] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> A >> B;
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];
  memset(dp, -1, sizeof(dp));
  cout << call(0, 0, 0);
  return 0;
}
