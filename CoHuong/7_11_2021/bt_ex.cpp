#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
int cnt[10];
int check(int d) {
  memset(cnt, 0, sizeof(cnt));
  while (d) {
    if (cnt[d % 10] == 2) return 0;
    cnt[d % 10]++;
    d /= 10;
  }
  return 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int l, r;
  cin >> l >> r;
  int res = 0;
  for (int d = l; d <= r; ++d) 
    res += check(d);
  cout << res;
  return 0;
}

