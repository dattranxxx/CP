#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
ll f[N + 1];
int n;
ll C;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> C;
  ll res = 0;
  for (int i = 1; i <= n; ++i)
    cin >> f[i], f[i] += f[i-1], res += abs(f[i]) > C;
  sort(f + 1, f + n + 1);
  for (int i = 1; i <= n; ++i) 
    res += n - (upper_bound(f + 1, f + n + 1, f[i] + C) - f - 1);
  cout << res;
  return 0;
}

