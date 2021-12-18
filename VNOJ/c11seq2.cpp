/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 60;
int n, m;
ll M;
int a[N], val[N], b[N];
ll ncr[N+1][N+1];
vector<pair<int, int>> idx[N];
ll cur = 0;
ll C(int x, int y) {
  if (x < 0 || y < 0 || x - y < 0) return 0;
  return ncr[x][y];
}
ll calc(int x, int y) {
  ll res = 0;
  for (pair<int, int>& p : idx[x]) 
    res += C(n - p.first - 1, y) * p.second;
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int k;
  cin >> n >> k; 
  vector<int> c(n);
  for (int i = 0; i < n; ++i) 
    cin >> a[i], c[i] = a[i];
  cin >> M;
  for (int i = 0; i < k; ++i)
    cin >> b[i];
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  m = c.size();
  for (int i = 0; i < n; ++i) { 
    int x = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
    val[x] = a[i];
    a[i] = x;
  }
  for (int i = 0; i < k; ++i) 
    b[i] = lower_bound(c.begin(), c.end(), b[i]) - c.begin();
  
  ncr[0][0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= n; ++j) 
      if (j == 0) ncr[i][j] = 1;
      else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
  for (int i = 0; i < n; ++i)
    idx[a[i]].push_back({i, 1});

  for (int p = k; p; --p) {
    for (int x = 0; x < m; ++x) {
      ll nxt = calc(x, p - 1);
      if (cur >= M - nxt) {
        cout << val[x] << ' ';
        for (int x = 0; x < m; ++x) idx[x].clear();
        int pre = 0;
        for (int i = 0; i < n; ++i) {
          if (a[i] == x) pre++;
          else if (pre) idx[a[i]].push_back({i, pre});
        }
        break;
      } else cur += nxt;
    }
  }
  cout << '\n';

  for (int i = 0; i < m; ++i) idx[i].clear();
  for (int i = 0; i < n; ++i)
    idx[a[i]].push_back({i, 1});
  
  ll res = 0;
  for (int p = 0; p < k; ++p) {
    for (int x = 0; x < b[p]; ++x) 
      res += calc(x, k - p - 1);
    for (int x = 0; x < m; ++x) idx[x].clear();
    int pre = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == b[p]) pre++;
      else if (pre) idx[a[i]].push_back({i, pre});
    }
  }
  cout << res + 1;
  return 0;
}

