#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "guard";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
vector<int> G[N];
int n;
int dp[N][2][2]; // mau cua cha no va mau cua no
void dfs(int u, int e = -1) {
  int flag = 0, min_sub = oo;
  dp[u][0][1] = dp[u][1][1] = 1;
  for (int v : G[u]) if (v != e) {
    dfs(v, u);
    min_sub = min(min_sub, dp[v][0][1] - dp[v][0][0]);
    if (dp[v][0][1] < dp[v][0][0]) 
      flag = 1, dp[u][0][0] += dp[v][0][1];
    else
      dp[u][0][0] += dp[v][0][0];
    
    dp[u][1][0] += min(dp[v][0][0], dp[v][0][1]);

    dp[u][0][1] += min(dp[v][1][0], dp[v][1][1]);

    dp[u][1][1] += min(dp[v][1][0], dp[v][1][1]);

  }
  if (!flag) 
    dp[u][0][0] += min_sub;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0, u, v; i < n-1; ++i)
    cin >> u >> v, u--, v--,
    G[u].emplace_back(v),
    G[v].emplace_back(u);
  dfs(0);
  cout << min(dp[0][0][0], dp[0][0][1]);
  return 0;
}

