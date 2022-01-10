#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
int a[N];
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  int res = oo;
  for (int i = 0; i < n - m + 1; ++i)
    res = min(res, a[i + m - 1] - a[i]);
  cout << res;
  return 0;
}


