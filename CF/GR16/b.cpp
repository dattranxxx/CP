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
string s;
int check_1() {
  for (int i = 0; i < s.size(); ++i) 
    if (s[i] != '1') return 0;
  return 1;
}
int check_0() {
  int first = 0, last = 0;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '0') {
      first = i; break;
    }
  for (int i = s.size() - 1; ~i; --i)
    if (s[i] == '0') {
      last = i; break;
    }
  for (int i = first + 1; i <= last - 1; ++i)
    if (s[i] != '0') return 0;
  return 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    if (check_1()) {
      cout << 0 << '\n'; 
    } else if (check_0()) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
  return 0;
}

