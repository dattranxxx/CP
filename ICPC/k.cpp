#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int Q = 1e4;
int x[Q], y[Q];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int n, m, q;
  cin >> n >> m; 
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      cin >> a[i][j];
  cin >> q;
  for (int i = 0; i < q; ++i)
    cin >> x[i] >> y[i];
  vector<vector<int>> res;
  for (int row = 0; row < n; ++row) {
    vector<vector<int>> a_ = a;
    swap(a_[0], a_[row]);
    vector<vector<int>> b(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        b[i][j] = a_[j][i];
    sort(b.rbegin(), b.rend());
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        a_[i][j] = b[j][i];
    sort(a_.rbegin(), a_.rend());
    if (!row) res = a_;
    else res = max(res, a_);
  }
  for (int i = 0; i < q; ++i) {
    cout << res[x[i] - 1][y[i] - 1] << '\n';
  }
  return 0;
}


