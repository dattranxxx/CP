#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
void file() {
  const string FILE_NAME = "order";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e5;
int col[N];
vector<vector<int>> G;
int n, m, trace = 0;
stack<int> st;
vector<vector<int>> q;
int dfs(int u) {
  for (int v : G[u]) if (col[v] != 2) {
    if (col[v]) return 1;
    col[v] = 1;
    if (dfs(v)) return 1;
  } 
  col[u] = 2;
  if (trace) st.push(u);
  return 0;
}
int check(int mid) {
  vector<vector<int>>(n).swap(G);
  for (int i = 0; i <= mid; ++i)
    for (int j = 0; j < q[i].size() - 1; ++j)
      G[q[i][j+1]].emplace_back(q[i][j]);
  memset(col, 0, sizeof(col));
  for (int i = 0; i < n; ++i) if (!col[i]) { 
    col[i] = 1;
    if (dfs(i)) return 1;
  }
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> m;
  q.resize(m);
  for (int i = 0, k; i < m; ++i) {
    cin >> k; 
    q[i].resize(k);
    for (int& x : q[i]) 
      cin >> x, x--;
  }
  int lo = 0, hi = m-1, res = 0, mid;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (!check(mid)) 
      res = mid,
      lo = mid + 1;
    else
      hi = mid - 1;
  }
  trace = 1;
  check(res);
  vector<int> v;
  while (!st.empty())
    v.emplace_back(st.top() + 1), st.pop();
  reverse(v.begin(), v.end());
  for (int x : v)
    cout << x << ' ';
  return 0;
}

