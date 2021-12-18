/*
ID: neetgam1
TASK: friday
LANG: C++
*/
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9, M = 47;
int mul(int x, int y) {
  return x * y % M;
}
void file() {
  const string FILE_NAME = "friday";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int N = 400;
int n;
int leap(int y) {
  if (y % 100 == 0) return y % 400 == 0;
  return y % 4 == 0;
}
int get(int m, int y) {
  if (m == 2) return 28 + leap(y);
  if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
  return 31;
}
int res[7];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  int cur = 2;
  for (int i = 0; i < n; ++i) {
    int year = 1900 + i;
    for (int month = 1; month <= 12; ++month)
      for (int day = 1; day <= get(month, year); ++day) {
        if (day == 13) res[cur] += 1;
        cur += 1; if (cur >= 7) cur -= 7;
      }
  }
  for (int i = 0; i < 7; ++i)
    cout << res[i] << " \n"[i == 6];
  return 0;
}

