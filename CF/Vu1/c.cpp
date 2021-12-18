/*                 ..... .
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
             .''....;coolc,'',;.                */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
int n, q, k;
vector<pair<int, int>> a, b;
int check(int len, int L, int R) {
  // ton tai doan do dai len ma ko co k doan nao phu dc
  // k = 1 -> doa dai nhat ko bi doan nao phu
  for (int i = 0; i < n; ++i)
    if ()
}
  int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> q >> k;
  a.resize(n); b.resize(n);
  int u, v;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v;
    a[i] = {u, v};
    b[i] = {u, v};
  }
  sort(a.begin(), a.end());
  
  while (q--) {
    cin >> u >> v;
    int lo = 0, hi = v - u + 1, mid, ans = 0;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (check(mid, u, v)) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
  }
  return 0;
}

