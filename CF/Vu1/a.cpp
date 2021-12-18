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
void file() {
  const string FILE_NAME = "sumdiv";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
ll L, R, res = 0;
vector<pair<int, int>> seg;
void calc_d(ll d) {
  // ton tai x sao cho L <= x * d <= R
  ll l = (L + d - 1) / d, r = R / d;
  if (l <= r && L <= l*d && r*d <= R) {
    // l + l + 1 + l + 2 + .. + l + (r - l)
    // 1 + 2 + .. + r - l) + (r - l + 1) * l
    //ll res = d + (r - l + 1) * l + (r - l + 1) * (r - l) / 2;
    seg.push_back({l, r});
    seg.push_back({d, d});
  } 
}
int c[1001];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> L >> R;
  // dem L <= d * x <= R
  // -> for d, for x
  for (int d = 1; d * d <= R; ++d) 
    calc_d(d);
  sort(seg.begin(), seg.end());
  for (int i = 0; i < seg.size();) {
    ll l = seg[i].first, r = seg[i].second;
    ++i; 
    while (i < seg.size() && seg[i].first <= r) 
      r = max(r, (ll)seg[i].second), ++i;
    res += (r - l + 1) * l + (r - l + 1) * (r - l) / 2;
  }
  cout << res;
  return 0;
}

