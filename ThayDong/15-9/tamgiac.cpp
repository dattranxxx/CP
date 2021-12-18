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
int a[N];
int n;
struct T {
  int min, second_min, max;
  T(): min(oo), second_min(oo), max(-oo) {}
  T(int min, int second_min, int max): min(min), second_min(second_min), max(max) {}
};
struct sparse_table {
  int log_2[N];
  T spt[N][20];
  T merge(T& x, T& y) {
    T z;
    if (x.min < y.min) {
      z.min = x.min;
      z.second_min = min(x.second_min, y.min); // y.min <= y.second_min
    } else {
      z.min = y.min;
      z.second_min = min(y.second_min, x.min);
    }
    z.max = max(x.max, y.max);
    return z;
  }
  void build() {
    for (int i = 2; i <= n; ++i) 
      log_2[i] = log_2[i / 2] + 1;
    for (int i = 0; i < n; ++i) 
      spt[i][0] = T(a[i], oo, a[i]);
    for (int j = 1; j <= log_2[n]; ++j)
      for (int i = 0; i + (1 << j) - 1 < n; ++i) 
        spt[i][j] = merge(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
  }
  T get(int l, int r) {
    int k = log_2[r - l + 1];
    T res;
    for (int k = log_2[r - l + 1]; ~k; --k) {
      if (l + (1 << k) - 1 <= r) {
        res = merge(res, spt[l][k]);
        l += (1 << k);
      }
    }
    return res;
  }
} spt;
int check(int l, int r, int x) {
  T t = spt.get(l, r);
  return t.min + t.second_min > x && t.max - t.min < x;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
  spt.build();

  // x+y>z, y-x<z, x-y<z -> maintain min x+y, max |x-y| va 2 pts
  // min x+y = minx+miny; max |x-y| = max - min
  // -> ctdl lay ra 2 gia tri be nhat, lay ra 1 gia tri lon nhat
  //
  int res = 0;
  for (int l = 0, r = 0; l < n; ++l) {
    if (r < l) r++;
    while (r+1 < n && check(l, r, a[r+1])) ++r;
    res = max(res, r - l + 1);
  } 
  cout << res;
  return 0;
}

