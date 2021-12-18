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
void file() {
  const string file_name = "apples";
  freopen((file_name + ".in").c_str(), "r", stdin);
  freopen((file_name + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
int n; ll A;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> A;
    if (n == 2) {
      // sau khi A-=a1 va a1*=2 thi no dc 1/3X va X
      // 2a1 = X, 3A-3a1 = X <> 
      if (A % 5 == 0) cout << A << ' ' << A * 3 / 5 << '\n';
      else cout << -1 << '\n';
    } else if (n == 3) {
      // (A-a1)*2 = 1/3X, a1*2-a2 = 2/3X, a2*2-A = X
      // 6A - 6a1 = X, 6a1 - 3a2 = 2X, 2a2 - A = X
      // 2A - a2 = 2a2 - A
      // 3A = 3a2 <> a2 = A -> X = A
      // -> a1 = 0
      // 6a1 = 5A -> a1 = 5A/6 
      if (A % 6 != 0) cout << -1 << '\n';
      else cout << A << ' ' << 5*A/6 << ' ' << A << '\n';
      // sau khi a2-=a3 va a3*=2 sau cung dc 1/3X 2/3X X
    } 
  }
  return 0;
}

