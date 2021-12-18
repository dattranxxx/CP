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
const ll oo = 1e18;
void file() {
  const string FILE_NAME = "bank";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int N = 1e3;
ll cur[N+2], nxt[N+2];
vector<ll> val[N+1];
int n, e = 0;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0, a, t; i < n; ++i) {
    cin >> a >> t;
    val[t].push_back(a);
  }
  for (int t = 0; t <= N; ++t) if (val[t].size()) {
    e = t + 1;
    sort(val[t].rbegin(), val[t].rend());
    for (int i = 1; i < val[t].size(); ++i)
      val[t][i] += val[t][i-1];
  }
  
  fill(begin(cur), end(cur), -oo);
  cur[1] = 0;
  for (int t = 0; t < e; ++t) { 
    fill(begin(nxt), end(nxt), -oo);
    for (int h = 0; h <= e; ++h) if (cur[h] != -oo) {
      nxt[h + 1] = max(nxt[h + 1], cur[h]);
      for (int i = 0; i < val[t].size() && i < h; ++i) {
        // lay i + 1 phan tu 
        nxt[h - i] = max(nxt[h - i], cur[h] + val[t][i]); 
      }
    }
    swap(cur, nxt);
  }
  ll res = 0;
  for (int h = 0; h <= e; ++h)
    res = max(res, cur[h]);
  cout << res;
  return 0;
}

