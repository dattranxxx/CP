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
int a[10], b[10], dp[31][1000][1000];
int n, A, B, last;
int call(int pos, int remA, int remB) {
  if (pos == last) return remA == 0 && remB == 0;
  if (dp[pos][remA][remB] != -1) return dp[pos][remA][remB];
  int res = 0;
  for (int msk = 0; msk < (1 << n); ++msk) {
    int curA = remA, curB = remB;
    for (int i = 0; i < n; ++i) if (msk & (1 << i)) 
      curA += a[i], curB += b[i];
    int nxt_remA = curA / 2; curA %= 2;
    int nxt_remB = curB / 2; curB %= 2;
    if (curA == !!(A & (1 << pos)) && curB == !!(B & (1 << pos)))
      add(res, call(pos + 1, nxt_remA, nxt_remB));
  }
  return dp[pos][remA][remB] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> A >> B;
  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];
  memset(dp, -1, sizeof(dp));
  last = 33 - min(__builtin_clz(A), __builtin_clz(B)); 
  cout << call(0, 0, 0);
  return 0;
}

