#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e6;
int tx, ty, n;
string s;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> tx >> ty >> s;
  n = s.size();
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'D') ty++;
    if (s[i] == 'L') tx++;
    if (s[i] == 'R') tx--;
    if (s[i] == 'U') ty--;
  }
  return 0;
}

