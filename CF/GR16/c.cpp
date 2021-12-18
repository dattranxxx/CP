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
const int N = 1e5;
int dp[N + 1];
string s, t;
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> s >> t; 
    s = ' ' + s; t = ' ' + t;
    for (int i = 1; i <= n; ++i) {
      if ((s[i] - '0') ^ (t[i] - '0')) {
        dp[i] = dp[i-1] + 2;
      } else {
        dp[i] = dp[i-1] + ((s[i] - '0') ^ 1);
        if (i > 1 && (s[i] - '0') ^ (s[i-1] - '0') && (t[i] - '0') ^ (t[i-1] - '0')) {
          dp[i] = max(dp[i], dp[i-2] + 2);
        }
      }
    }
    cout << dp[n] << '\n';
  }
  return 0;
}

