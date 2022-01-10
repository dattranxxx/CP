#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;

int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  string s;
  cin >> s;
  int idx = -1;
  for (int i = 0; i < s.size(); ++i)
    if (s[i] == '.') {
      if (idx != -1) return cout << "no", 0;
      idx = i;
    }
  if (idx > 0 && s.size() - idx == 3 && s.substr(idx, 3) == ".py")
    cout << "yes";
  else
    cout << "no";
  return 0;
}

