#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
int a[N + 1];
ll f[N + 1];
int n;
ll k;
void file() {
  const string FILE_NAME = "average";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) 
    cin >> a[i], f[i] = f[i-1] + a[i];
  // f(r) - f(l-1) / (r - l + 1) = k
  // <> f(r) - kr = f(l-1) - kl + 1
  int res = 0;
  unordered_map<ll, int> m;
  for (int i = 1; i <= n; ++i) {
    m[f[i-1] - k*i + k] = i;
    if (m.count(f[i] - k*i))
      res = max(res, i - m[f[i] - k*i] + 1);
  }
  cout << res;
  return 0;
}

