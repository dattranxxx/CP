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
using ld = long double;
const int oo = 1e9;
const int N = 1e5;
ll a[N+1], f[N+1];
ld pre[N+1], suf[N+2];
ll n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> a[i], f[i] = f[i-1] + a[i];
  for (int i = 1; i <= n; ++i)
    pre[i] = pre[i-1] + a[i] * i;
  for (int i = n; i; --i)
    suf[i] = suf[i+1] + a[i] * (n-i+1);
  ld res = 0;
  for (int k = 1; k <= n/2; ++k) {
    // <> n-k+1
    // k so dau k so cuoi va n-2k so giua
    ld x = (pre[k] + suf[n-k+1]) + (f[n-k] - f[k]) * k;
    res += x / k + x / (n - k + 1);
  }
  if (n & 1) {
    int k = n / 2;
    ld x = (pre[k] + suf[n-k+1]) + (k + 1) * (f[n-k] - f[k]);
    res += x / (k + 1);
  }
  cout << fixed << setprecision(6) << res / (n * (n + 1) / 2);
  return 0;
}

