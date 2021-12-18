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
void file() {
  const string FILE_NAME = "travel";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int N = 1e5;
int n, T;
int succ[N][34];
ll wei[N][34];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> T;
  for (int i = 0; i < n; ++i) 
    cin >> succ[i][0], succ[i][0]--;
  for (int i = 0; i < n; ++i)
    cin >> wei[i][0];
  for (int j = 1; j <= 33; ++j) {
    for (int i = 0; i < n; ++i) {
      succ[i][j] = succ[succ[i][j-1]][j-1];
      wei[i][j] = wei[i][j-1] + wei[succ[i][j-1]][j-1];
    }
  }
  int i; ll w, res;
  while (T--) {
    cin >> i >> w; i--;
    res = 0;
    for (int j = 33; ~j; --j) {
      if (w >= wei[i][j]) {
        w -= wei[i][j];
        i = succ[i][j];
        res += (1LL << j);
      }
    }
    cout << res << '\n';
  }
  return 0;
}

