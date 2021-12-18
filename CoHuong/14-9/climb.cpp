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
  const string FILE_NAME = "climb";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e6;
vector<int> G[N];
int a[N], dp[N];
int n, m;
int call(int u) {
  if (dp[u] != -1) return dp[u];
  dp[u] = 1;
  for (int v : G[u]) 
    dp[u] = max(dp[u], call(v) + 1);
  return dp[u];
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m;
  for (int i = 0, x; i < n; ++i) 
    for (int j = 0; j < m; ++j) 
      cin >> x, a[i*m+j] = x;
  for (int i = 0, u, v; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      u = i * m + j;

      v = i * m + j - 1;
      if (j > 0 && a[u] < a[v])  
        G[u].push_back(v);
      
      v = i * m + j + 1;
      if (j < m-1 && a[u] < a[v]) 
        G[u].push_back(v);

      v = (i - 1) * m + j;
      if (i > 0 && a[u] < a[v]) 
        G[u].push_back(v);
      
      v = (i + 1) * m + j;
      if (i < n-1 && a[u] < a[v]) 
        G[u].push_back(v);
      
    }
  
  memset(dp, -1, sizeof(dp));
  int res = 1;
  for (int i = 0; i < n*m; ++i)
    res = max(res, call(i));
  cout << res;
  
  return 0;
}

