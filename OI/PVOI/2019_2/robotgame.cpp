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
void file() {
  const string FILE_NAME = "robotgame";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int n;
  cin >> n;
  vector<pair<int, int>> pos(n << 1);
  vector<int> des(n << 1);
  ll res = 0;
  for (int i = 0, x, y; i < n*2; ++i) {
    cin >> x >> y;
    if (y >= 2) res += y - 2, pos[i].second = 2;
    else res += 1 - y, pos[i].second = 1;
    pos[i].first = x;
    des[i] = i / 2 + 1;
  }
  sort(pos.begin(), pos.end());
  for (int i = 0; i < n*2; ++i) 
    res += abs(pos[i].first - des[i]);
  for (int i = 0; i < n*2; i += 2)
    res += pos[i].second == pos[i+1].second;
  cout << res;
  return 0;
}

