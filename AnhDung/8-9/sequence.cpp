/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
void file() {
  const string FILE_NAME = "sequence";
  freopen((FILE_NAME + ".inp"), "r", stdin);
  freopen((FILE_NAME + ".out"), "w", stdout);
}
const int N = 1e5;
int a[N];
int n;
int incl(int x, int d) {
  while (x) {
    if (d == (x % 10)) return 1;
    x /= 10;
  }
  return 0;
}
int check_n(int k) {
  for (int i = 0; i < n; ++i) {
    if (!incl(k + i, a[i])) return 0;
  }
  return 1;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0; i < n; ++i) 
    cin >> a[i];
  for (int i = 0; i <= 1000; ++i) {
    if (check_n(i)) {
      cout << i; return 0;
    }
  }
  assert(0);
  return 0;
}

