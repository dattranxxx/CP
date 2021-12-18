#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "ave";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 1e3;
ll a[N], b[N], f[N];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  a[0] = b[0], f[0] = a[0];
  for (int i = 1; i < n; ++i)
    a[i] = (b[i] * (i + 1)) - f[i - 1],
    f[i] = f[i-1] + a[i];
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  return 0;
}

