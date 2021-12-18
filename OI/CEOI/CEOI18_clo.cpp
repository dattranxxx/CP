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
const ll oo = 1e18;
struct S {
  int c, f, v, t;
  S(int c, int f, int v, int t): c(c), f(f), v(v), t(t) {}
};
const int N = 2000;
ll dp[2][N * 50 + 1];
vector<S> a;
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n; a.reserve(n);
  int sum_c = 0;
  for (int i = 0, c, f, v; i < n; ++i) {
    cin >> c >> f >> v;
    a.emplace_back(c, f, v, 0);
    sum_c += c;
  }
  cin >> m;
  for (int i = 0, c, f, v; i < m; ++i) {
    cin >> c >> f >> v;
    a.emplace_back(c, f, v, 1);
  }
  sort(a.begin(), a.end(), [&](S& u, S& v) {
    if (u.f == v.f) return u.t < v.t;
    return u.f > v.f;
  });
  fill(begin(dp[0]), end(dp[0]), -oo);
  dp[0][0] = 0;
  for (int i = 0; i < a.size(); ++i) {
    int cur = i & 1, nxt = cur ^ 1;
    fill(begin(dp[nxt]), end(dp[nxt]), -oo);
    for (int j = 0; j <= sum_c; ++j) if (dp[cur][j] != -oo) {
      dp[nxt][j] = max(dp[nxt][j], dp[cur][j]);
      if (a[i].t == 0) {
        // mua 
        dp[nxt][j + a[i].c] = max(dp[nxt][j + a[i].c], dp[cur][j] - a[i].v);
      } else {
        // ban 
        if (j >= a[i].c) 
          dp[nxt][j - a[i].c] = max(dp[nxt][j - a[i].c], dp[cur][j] + a[i].v);
      }
    }
  }
  ll res = 0;
  for (int i = 0; i <= sum_c; ++i)
    res = max(res, dp[int(a.size()) & 1][i]);
  cout << res;
  return 0;
}

