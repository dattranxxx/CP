/*                 ..... .
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
             .''....;coolc,'',;.                */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
void file() {
  const string FILE_NAME = "mine";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9, M = 1e6 + 3;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
int mul(ll x, ll y) {
  return x * y % M;
}
const int N = 2e3;
int n, m;
int dp[N*2], C[N], a[N];
int call(int l) {
  if (l == n*2) return 1; 
  if (dp[l] != -1) return dp[l];
  int res = 0;
  for (int r = l + 1; r < n*2; r += 2) if (a[r] - a[l] <= m) { 
    add(res, mul(C[(r - l - 1) / 2], call(r + 1)));
  }
  return dp[l] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  // dem so cach phan 2n so thanh n cap sao cho
  // a[p[i]] - a[i] <= m va a[p[j]] < a[p[i]] voi i < j < p[i]
  cin >> n >> m;
  for (int i = 0; i < n*2; ++i)
    cin >> a[i];
  C[0] = C[1] = 1;
  for (int i = 2; i < n; ++i) {
    C[i] = 0;
    for (int j = 0; j < i; ++j)
      add(C[i], mul(C[j], C[i-j-1]));
  }
  memset(dp, -1, sizeof(dp));
  cout << call(0);
  return 0;
}

