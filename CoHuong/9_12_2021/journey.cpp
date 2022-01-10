#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "journey";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
const int N = 1e6;
int tx, ty, n;
string s;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> tx >> ty >> s;
  n = s.size();
  int t = 0;
  vector<int> pos;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'D') ty++;
    else if (s[i] == 'L') tx++;
    else if (s[i] == 'R') tx--;
    else if (s[i] == 'U') ty--;
    else pos.emplace_back(i), t++;
  }
  // D -> L -> R -> U
  if (tx + ty > t || (t - abs(tx) - abs(ty)) & 1)  
    return cout << "IMPOSSIBLE", 0;
  // mat |tx| cai 
  vector<int> res(4);
  if (tx > 0) res[1] += abs(tx);
  else if (tx < 0) res[2] += abs(tx);
  t -= abs(tx);
  // mat |ty| cai
  if (ty > 0) res[3] += abs(ty);
  else if (ty < 0) res[0] += abs(ty);
  t -= abs(ty);
  // t chan -> += t/2 vao D va U 
  res[0] += t / 2, res[3] += t / 2;
  int i = 0;
  vector<char> c = {'D', 'L', 'R', 'U'};
  for (int i = 0, j = 0; j < 4 && i < pos.size(); ++j) {
    while (res[j]--) 
      s[pos[i]] = c[j], i++;
  }
  cout << s << '\n';
  return 0;
}

