#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;

int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  int x1, x2, y1, y2;
  while (T--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << __gcd(abs(x1 - x2), abs(y1 - y2)) + 1 << '\n';
  }
  return 0;
}

