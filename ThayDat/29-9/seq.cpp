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
const int N = 16;
ll pw[N+1], d[N], d_[N];
ll k, p, c;
int call(int i, ll j, ll e) {
  printf("so thu %d cua hang %d ma cu xoa %d so != 9\n", j, i, e);
  string s;
  for (ll x = pw[i]; ; ++x) {
    s = to_string(x);
    int cnt = 0;
    for (char ch : s) cnt += ch != '9';
    if (e <= cnt) {
      return s[j];
    } else e -= cnt;
  } 
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  pw[0] = 1;
  for (int i = 1; i <= 16; ++i)
    pw[i] = pw[i-1] * 10;
  d[0] = 9; d_[0] = 8;
  for (int i = 1; i < 16; ++i)
    d[i] = (pw[i + 1] - pw[i]) * (i + 1),
    d_[i] = d[i] - 9 * d[i-1]; 
  int T;
  cin >> T;
  while (T--) {
    cin >> k >> p; c = 1;
    // so so hang 0 = d[0] = 9
    // so so hang i = d[i] = [(10^(i+1) - 1) - 10^i + 1] * (i + 1)
    // so digit 9 hang 0 = 1
    // so digit 9 hang i = 9 * so so hang i-1
    // -> so so khong phai 9 hang i la d'[i] = d[i] - 9 * d[i-1]
    // so so khong phai 9,8 hang i la d[i] - (9+8)*d[i-1]
    int j = 9, c = 9;
    for (int i = 0; i < 16; ++i) {
      ll x = i ? j : d[i] - c * d[i-1];
      if (k < x) {
        if ()
        cout << call(i, p, k) << '\n'; break;
      } else k -= x;
    }
  }
  return 0;
}

