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
mt19937 rng(time(0));
const int N = 100;
vector<int> G[N];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int n = rng() % N + 3;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) 
      if (j != i) G[i].push_back(j);
  }
  int m = rng() % (n * int(sqrt(n))) + 1;
  cout << n << ' ' << m << '\n';
  vector<pair<int, int>> d(m);
  for (int i = 0, u, v; i < m; ++i) {
    u = rng() % n, v = G[u][rng() % int(G[u].size())];
    cout << u << ' ' << v << '\n';
    d[i] = {u, v};
  }
  int q = rng() % N + 1;
  cout << q << '\n';
  for (int i = 0, u, v; i < q; ++i) {
    int x = rng() % m;
    cout << d[x].first << ' ' << d[x].second << '\n';
  }
  return 0;
}

