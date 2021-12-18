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
const int N = 1e4;
vector<int> G[N], R[N], C[N], T[N];
int vis[N], a[N], wei[N], comp[N], dp[N];
stack<int> st; vector<int> ans;
int n, m, k = 0;
void build(int u, int t) {
  vis[u] = 1;
  if (t == 0) {
    for (int v : G[u]) if (!vis[v]) build(v, t);
    st.push(u);
  } else {
    for (int v : R[u]) if (!vis[v]) build(v, t);
    comp[u] = k; wei[k] += a[u]; 
  }
}
void dfs(int u) {
  vis[u] = 1;
  for (int v : C[u]) 
    if (!vis[v]) dfs(v);
  ans.push_back(u);
}
string s[100];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m; char ch;
  for (int i = 0; i < n; ++i)
    cin >> s[i];
  for (int i = 0, u, v; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ch = s[i][j];
      u = i * m + j;
      if (i < n-1 && s[i+1][j] != '#') {
        v = (i + 1) * m + j;
        G[u].push_back(v);
        R[v].push_back(u);
      }
      if (j < m-1 && s[i][j+1] != '#') {
        v = i * m + j + 1;
        G[u].push_back(v);
        R[v].push_back(u);
      }
      if (ch == 'W') {
        if (j && s[i][j-1] != '#') {
          v = i * m + j - 1;
          G[u].push_back(v);
          R[v].push_back(u);
        }
      } else if (ch == 'N') {
        if (i && s[i-1][j] != '#') {
          v = (i - 1) * m + j;
          G[u].push_back(v);
          R[v].push_back(u);
        }
      } else a[u] = ch - '0';
    }
  }
  n *= m;
  for (int u = 0; u < n; ++u) 
    if (!vis[u]) build(u, 0);
  memset(vis, 0, sizeof(vis));
  while (!st.empty()) {
    int u = st.top(); st.pop();
    if (!vis[u]) build(u, 1), k++;
  }
  for (int u = 0; u < n; ++u) {
    for (int v : G[u]) if (comp[u] != comp[v]) {
      C[comp[u]].push_back(comp[v]);
      T[comp[v]].push_back(comp[u]);
    }
  }
  for (int u = 0; u < k; ++u) {
    sort(C[u].begin(), C[u].end()); sort(T[u].begin(), T[u].end());
    C[u].erase(unique(C[u].begin(), C[u].end()), C[u].end());
    T[u].erase(unique(T[u].begin(), T[u].end()), T[u].end());
  }
   
  memset(vis, 0, sizeof(vis));
  for (int u = 0; u < k; ++u) 
    if (!vis[u]) dfs(u);
  reverse(ans.begin(), ans.end());

  int res = 0;
  fill(begin(dp), end(dp), -oo);
  dp[comp[0]] = wei[comp[0]];
  for (int u : ans) {
    for (int v : T[u]) { 
      dp[u] = max(dp[u], dp[v] + wei[u]);
    }
    res = max(res, dp[u]);
  }
  cout << res;
  return 0;
}

