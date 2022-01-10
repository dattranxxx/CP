#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e5;
string s;
int n;
ll a[N], b[N];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> s; n = s.size();
  s = ' ' + s;
  ll cnt_a = 0, cnt_b = 0, sum_a = 0, sum_b = 0;
  for (int i = 1; i <= n; ++i) 
    a[i] += cnt_a * i - sum_a,
    b[i] += cnt_b * i - sum_b,
    cnt_a += s[i] == 'A',
    cnt_b += s[i] == 'B',
    sum_a += s[i] == 'A' ? i : 0,
    sum_b += s[i] == 'B' ? i : 0;
  cnt_a = 0, cnt_b = 0, sum_a = 0, sum_b = 0;
  for (int i = n; i; --i) 
    a[i] += cnt_a * (n - i + 1) - sum_a,
    b[i] += cnt_b * (n - i + 1) - sum_b,
    cnt_a += s[i] == 'A',
    cnt_b += s[i] == 'B',
    sum_a += s[i] == 'A' ? n - i + 1 : 0,
    sum_b += s[i] == 'B' ? n - i + 1 : 0;
  int T, i;
  cin >> T;
  while (T--) {
    cin >> i;
    cout << a[i] << ' ' << b[i] << '\n';
  }
  
  return 0;
}

