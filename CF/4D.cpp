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
const int N = 5e3;
struct S {
  int w, h, i;
  S(int w, int h, int i): w(w), h(h), i(i) {}
  bool operator < (const S& s) const {
    return w < s.w && h < s.h;
  }
};
int dp[N], tr[N];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int n, w, h;
  cin >> n >> w >> h;
  S s(w, h, 0);
  vector<S> a; a.reserve(n);
  for (int i = 0, wi, hi; i < n; ++i) {
    cin >> wi >> hi;
    a.emplace_back(wi, hi, i);
  }
  sort(a.begin(), a.end(), [&](S& u, S& v) {
    if (u.w == v.w) return u.h < v.h;
    return u.w < v.w;
  });
  memset(tr, -1, sizeof(tr));
  for (int i = n-1; ~i; --i) {
    dp[i] = 1;
    for (int j = i + 1; j < n; ++j) if (a[i] < a[j]) 
      if (dp[j] + 1 > dp[i]) {
        dp[i] = dp[j] + 1;
        tr[i] = j;
      }
  }
  int res = 0, tra = -1;
  for (int i = 0; i < n; ++i) if (s < a[i]) 
    if (dp[i] > res) {
      res = dp[i];
      tra = i;
    }
  cout << res << '\n';
  for (int t = tra; ~t; t = tr[t]) {
    cout << a[t].i + 1 << ' ';
  }
  return 0;
}

