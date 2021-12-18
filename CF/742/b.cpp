/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 3e5;
int xr[N+1];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  xr[0] = 0;
  for (int i = 1; i <= N; ++i)
    xr[i] = xr[i-1] ^ i;
  int t, a, b;
  cin >> t;
  while (t--) {
    cin >> a >> b;
    // u ^ x = v 
    // 0 ^ 0 = 0
    // 0 ^ 1 = 1
    // 1 ^ 0 = 1
    // 1 ^ 1 = 0
    int x = xr[a-1] ^ b;
    if (xr[a-1] == b) cout << a << '\n';
    else if (x == a) cout << a + 2 << '\n';
    else cout << a + 1 << '\n';

  }
  return 0;
}

