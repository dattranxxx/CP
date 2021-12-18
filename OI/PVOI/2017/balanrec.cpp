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
const int N = 500;
int a[N+1][N+1], f[N+1];
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j];
  for (int h1 = 1; h1 <= n; ++h1) {
    memset(f, 0, sizeof(f));
    for (int h2 = h1; h2 <= n; ++h2) {
      for (int i = 1; i <= m; ++i) 
        f[i] = f[i-1] + f[i] + (a[h2][i] ? 1 : -1),
        cerr << f[i] << ' ';
      cerr << '\n';
      // voi moi r tim l sao cho f[r] == f[l-1]


    }
  }
  return 0;
}

