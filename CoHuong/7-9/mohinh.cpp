/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
void file() {
  const string FILE_NAME = "mohinh";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int N = 1e3 + 2;
int a[N][N], li[N * N], dead[N * N], sz[N * N], val[N * N];
vector<pair<int, int>> idx[N * N];
int n, m, k;
int cur = 0;
int find(int u) {
  if (u == li[u]) return u;
  return li[u] = find(li[u]);
}
void unite(int u, int v) {
  if (li[v] == -1) return;
  u = find(u), v = find(v);
  if (u == v) return;
  if (sz[u] < sz[v]) swap(u, v);
  li[v] = u; 
  if (dead[v] && !dead[u]) 
    cur -= sz[u];
  else if (!dead[v] && dead[u]) 
    cur -= sz[v];
  dead[u] |= dead[v];
  sz[u] += sz[v];
}
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
void insert(int x, int y) {
  cur += 1;
  int u = x * (m+2) + y;
  li[u] = u;
  sz[u] = 1;
  for (int i = 0; i < 4; ++i) 
    unite(u, (x + dx[i]) * (m+2) + y + dy[i]);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m;
  vector<int> c(n * m);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      cin >> a[i][j], c[(i-1) * m + (j-1)] = a[i][j];
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  k = c.size();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) {
      int x = lower_bound(c.begin(), c.end(), a[i][j]) - c.begin();
      idx[x].push_back({i, j});
      val[x] = a[i][j]; a[i][j] = x;
    }
  memset(li, -1, sizeof(li));
  for (int i = 0; i <= m+1; ++i)
    li[i] = i, li[(n+1)*(m+2)+i] = (n+1)*(m+2)+i, dead[i] = dead[(n+1)*(m+2)+i] = 1;
  for (int i = 1; i <= n; ++i)
    li[i*(m+2)] = i, li[i*(m+2)+m+1] = i*(m+2)+m+1, dead[i*(m+2)] = dead[i*(m+2)+m+1] = 1;
  int res = 0;
  for (int x = 0; x < k - 1; ++x) {
    for (auto& p : idx[x]) 
      insert(p.first, p.second);
    res += cur * (val[x + 1] - val[x]);
  }
  cout << res;
  return 0;
}

