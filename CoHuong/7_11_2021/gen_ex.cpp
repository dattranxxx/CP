#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
mt19937 rng(time(0));
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int r = rng() % int(3e5) + 1;
  int l = rng() % r + 1;
  cout << l << ' ' << r;
  return 0;
}

