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
using C = long double;
const int oo = 1e9;
const int N = 3000;
typedef complex<C> P;
vector<int> G[N];
double dp[N][2], wei[N];
void call(int u, int e) {
  for (int v : G[u]) if (v != e) {
    call(v, u);
    dp[u][0] = max(dp[u][0], dp[v][1]);
    dp[u][1] = max(dp[u][1], dp[v][0] + wei[u]);
  }
}
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  double x;
  cin >> x;
  cout << x;
  /*
  cin >> n; 
  vector<P> a(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
  vector<pair<int, int>> diag(n-3);
  for (int i = 0, u, v; i < n-3; ++i) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  for (int u = 0; u < n; ++u) {
    sort(G[u].begin(), G[u].end(), [&](int u, int v) {

    })
  }
  */
  return 0;
}

