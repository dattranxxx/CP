#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "papers";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 1e5, M = 1e9 + 7;
int a[N];
int n, m;
int pw(ll x, ll k) {
  ll res = 1;
  for (; k; k >>= 1, x = (x * x) % M)
    if (k & 1) res = (res * x) % M;
  return res;
}
int C(int n, int k) {
  if (n < k || n < 0 || k < 0) return 0;
  ll u = 1, v = 1;
  for (ll i = n - k + 1; i <= n; ++i)
    u *= i, u %= M;
  for (ll i = 1; i <= k; ++i)
    v *= i, v %= M;
  return u * pw(v, M - 2) % M;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> m >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i], a[i]--, m -= a[i];
  cout << C(m - 1, n - 1);
  return 0;
}

