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
const int oo = 1e9;
mt19937 rng(time(0));
const int N = 2e5 + 2;
int log_2[N];
ll a[N], spt[N][19];
tuple<int, int, int> q[N];
int n;
ll __lcm(ll x, ll y) {
  return x / __gcd(x, y) * y;
}
void build() {
  for (int i = 2; i <= n; ++i) 
    log_2[i] = log_2[i / 2] + 1;
  for (int i = 0; i < n; ++i) spt[i][0] = a[i];
  for (int j = 1; j <= 20; ++j)
    for (int i = 0; i + (1 << j) <= n; ++i)
      spt[i][j] = __gcd(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
}
ll get(int l, int r) {
  int k = log_2[r - l + 1];
  ll x = spt[l][k], y = spt[r-(1<<k)+1][k];
  return __gcd(x, y);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  n = 20;
  int m = 20;
  cout << n << ' ' << m << '\n';
  for (int i = 0; i < n;++i)
    a[i] = rng() % 4 + 1;
  build();
  for (int i = 0, l, r; i < m; ++i) {
    r = max(n-1, (int)rng() % n + 1), l = min(r, int(rng() % r) + 10);
    cout << l << ' ' << r << ' ' << get(l, r) << '\n';
  }
  return 0;
}

