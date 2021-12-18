/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 5e5+5;
string s; int n;
int pre[N], suf[N];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> s; n = s.size(); s = ' ' + s + ' ';
  // so luong so < a[i] = Z< 0->i-1 + Z> i->n 
  for (int i = 1; i <= n; ++i) 
    if (s[i] == '<')
      pre[i] = pre[i-1] + 1;
  for (int i = n; i >= 1; --i)
    if (s[i] == '>')
      suf[i] = suf[i+1] + 1;
  ll res = 0;
  for (int i = 1; i <= n+1; ++i)
    res += max(pre[i-1], suf[i]);
  cout << res;
  return 0;
}

