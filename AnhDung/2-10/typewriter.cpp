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
int dp[N+1][N+1], lcp[N+1]; // i, i-1
int n, k;
int __lcp(int i, int j) {
  int k = 0;
  for (; k < min(a[i].size(), a[j].size()); ++k)
    if (a[i][k] != a[j][k]) return k;
  return k;
}
struct sparse_table {
  int log_2[N+1], spt[N+1][9];
  void build() {
    for (int i = 2; i <= n; ++i)
      log_2[i] = log_2[i / 2] + 1;
    for (int i = 1; i <= n-1; ++i)
      spt[i][0] = lcp[i];
    for (int j = 1; j <= log_2[n-1]; ++j) 
      for (int i = 1; i + (1 << j) - 1 <= n-1; ++i)
        spt[i][j] = min(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
  }
  int get(int l, int r) {
    assert(l < r);
    r--;
    int k = log_2[r - l + 1];
    return min(spt[l][k], spt[r-(1<<k)+1][k]);
  }
} spt;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
      cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
      lcp[i] = __lcp(i, i+1);
    spt.build();
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0; int res = oo;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= i && j <= k; ++j) {
        for (int l = i-1; ~l; --l) {
          int x = spt.get(l, i);
          dp[i][j] = min(dp[i][j], dp[l][j-1] + int(a[l].size() - x) + int(a[i].size() - x));
        }
      }
      res = min(res, dp[i][k] + int(a[i].size()) + k);
    }
    cout << res << '\n';
  }
  return 0;
}

