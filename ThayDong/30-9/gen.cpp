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
  int w = 5, h = 5, n = 5;
  cout << w << ' ' << h << ' ' << n << '\n';
  for (int i = 0; i < n; ++i) {
    if (rng() & 1) {
      int r = rng() % h + 1;
      cout << rng() % w + 1 << ' ' << r << ' ' << rng() % w + 1 << ' ' << r << '\n';
    } else {
      int c = rng() % w + 1;
      cout << c << ' ' << rng() % h + 1 << ' ' << c << ' ' << rng() % h + 1 << '\n';

    }
  }
  return 0;
}

