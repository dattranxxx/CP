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
const int N = 400;
bitset<N> a[N], A, X, U, G;
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T; string s;
  cin >> T;
  while (T--) {
    cin >> n >> m; n--;
    cin >> s; A.reset();
    for (int i = 0; i < m; ++i)
      A[i] = s[i] == 'Y';
    for (int i = 0; i < n; ++i) {
      cin >> s; a[i].reset();
      for (int j = 0; j < m; ++j)
        a[i][j] = s[j] == 'Y';
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
      X = a[i]; G = A & X; U.reset();
      int flag = 0;
      for (int j = 0; j < n; ++j) if (j != i) {
        if ((a[j] & G) == G) {
          U |= (a[j] & ~G);
          if ((a[j] & A) == A) 
            flag = 1, j = n;
        }
      }
      if (flag) continue;
      res |= ((X & ~G) & ~U).any();
    }
    cout << (res ? "Y\n" : "N\n");
  }
  return 0;
}

