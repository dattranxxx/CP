#include <bits/stdc++.h>

using namespace std;

const int N = 8010;

int dpL[N][N];
int dpR[N][N];
int mx[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
      cin >> f[i];
    }
    vector<int> h(n - 1);
    for (int i = 0; i < n - 1; i++) {
      cin >> h[i];
    }
    for (int i = n - 2; i >= 0; i--) {
      int u = 0;
      for (int j = i; j <= n - 2; j++) {
        u = max(u, h[j]);
        mx[i][j] = u;
      }
    }
    const long long inf = (long long) 2e9;
    for (int i = 0; i < n; i++) {
      for (int j = n - 1; j >= i; j--) {
        if (i == 0 && j == n - 1) {
          dpL[i][j] = dpR[i][j] = 0;
          continue;
        }
        dpL[i][j] = dpR[i][j] = inf;
        { // dpL
          if (i > 0) {
            int cur = h[i - 1];
            // have - h[i - 1] + f[i - 1] >= dpL[i - 1][j]
            cur = max(cur, dpL[i - 1][j] - f[i - 1] + h[i - 1]);
            dpL[i][j] = min(dpL[i][j], cur);
          }
          if (j < n - 1) {
            int cur = max(mx[i][j], dpR[i][j + 1] - f[j + 1] + h[j]);
            dpL[i][j] = min(dpL[i][j], cur);
          }
        }
        { // dpR
          if (j < n - 1) {
            int cur = h[j];
            cur = max(cur, dpR[i][j + 1] - f[j + 1] + h[j]);
            dpR[i][j] = min(dpR[i][j], cur);
          }
          if (i > 0) {
            int cur = max(mx[i - 1][j - 1], dpL[i - 1][j] - f[i - 1] + h[i - 1]);
            dpR[i][j] = min(dpR[i][j], cur);
          }
        }

        if (i == j) {
          assert(dpL[i][j] == dpR[i][j]);
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      --x;
      cout << (y + f[x] >= dpL[x][x] ? "Y" : "N");
    }
    cout << '\n';
  }
  return 0;
}
