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
int a[20];
int n;
int check(int l, int r) {
  for (int i = l; i <= r; ++i)
    for (int j = i+1; j <= r; ++j)
      for (int k = j+1; k <= r; ++k) 
        if (a[i] + a[j] <= a[k] || a[i] + a[k] <= a[j] || a[j] + a[k] <= a[i]) {
          return 0;
        }
  return 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int res = 0;
  for (int l = 0; l < n; ++l)
    for (int r = l; r < n; ++r) if (check(l, r) && r - l + 1 > res) {
      res = r - l + 1;
    }
  cout << res;
  return 0;
}

