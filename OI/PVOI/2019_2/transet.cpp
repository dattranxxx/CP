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
#define print(_v) for (auto &_ : _v) {cerr << _ +1<< ' ';} cerr << endl;
using namespace std;
using ll = long long;
void file() {
  const string FILE_NAME = "transet";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e3;
vector<int> G[N];
int dp[N][51];
int n;
int call(int u, int k) {
  if (dp[u][k] != -1) return dp[u][k];
  if (k == 0) return 1;
  if (k == 1) return G[u].size();
  dp[u][k] = -oo;
  for (int v : G[u]) 
    for (int i = 0; i < k; ++i)
      dp[u][k] = max(dp[u][k], call(u, k-i) + call(v, i) - 1);
  return dp[u][k];
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  //file();
  int S;
  cin >> n;
  for (int i = 0, k; i < n; ++i) {
    cin >> k; G[i].resize(k);
    for (int& x : G[i])
      cin >> x, x--;
  }
  cin >> S; 
  int res = 0;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; ++i) 
    res = max(res, call(i, S));
  cout << res;
  return 0;
}

