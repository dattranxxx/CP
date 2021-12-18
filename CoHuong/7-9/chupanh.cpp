/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
void file() {
  const string FILE_NAME = "chupanh";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int N = 1e5;
int a[N], idx[5][N+1];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int k = 0, x; k < 5; ++k)
    for (int i = 0; i < n; ++i)
      cin >> x, idx[k][x] = i;
  vector<int> a(n);
  iota(a.begin(), a.end(), 1);
  auto cmp = [&](const int x, const int y) {
    int cnt = 0;
    for (int k = 0; k < 5; ++k)
      cnt += idx[k][x] < idx[k][y];
    return cnt >= 3;
  };
  sort(a.begin(), a.end(), cmp);
  for (int x : a)
    cout << x << ' ';
  return 0;
}

