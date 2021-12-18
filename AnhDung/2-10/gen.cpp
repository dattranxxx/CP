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
mt19937 rng(time(0));
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T = 10;
  cout << T << '\n';
  while (T--) {
    int n = 3e5, q = 3e5;
    cout << n << ' ' << q << '\n';
    for (int i = 0; i < n; ++i) {
      cout << rng() % int(1e9) + 1 << ' ';
    }
    cout << '\n';
    for (int i = 0, l, r; i < q; ++i) {
      r = rng() % n + 1, l = rng() % r + 1;
      cout << l << ' ' << r << '\n';
    }
    cout << '\n';
  }
  return 0;
}

