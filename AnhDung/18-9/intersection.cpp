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

typedef long double C;
typedef complex<C> P;
#define X real()
#define Y imag()
const C eps = 1e-9;
C cross(P u, P v) {
  return (conj(u)*v).Y;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  P a, b, p, q;
  C x, y;
  cin >> T;
  while (T--) {
    cin >> x >> y;
    a = P(x, y);
    cin >> x >> y;
    b = P(x, y);
    cin >> x >> y;
    p = P(x, y);
    cin >> x >> y;
    q = P(x, y);
    C c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
    if (abs(c1 - c2) < eps) {
      if (abs(c1) < eps) cout << "LINE\n";
      else cout << "NONE\n";
    } else {
      P res = (c1 * q - c2 * p) / (c1 - c2);
      cout << "POINT " << fixed << setprecision(2) << res.X << ' ' << res.Y << '\n';
    }
  }
  return 0;
}

