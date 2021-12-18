/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int oo = 1e9;
const int N = 1e5;
int pw_1[N+1];
ull pw_2[N+1];
const int base = 31, mod = 1e9 + 7;
struct hash_string {
  string s;
  vector<int> h_1;
  vector<ull> h_2;
  hash_string() {}
  hash_string(string s): s(s), h_1(s.size()), h_2(s.size()) {
    if (s.empty()) return;
    h_1[0] = h_2[0] = s[0] - 'A' + 1;
    for (int i = 1; i < s.size(); ++i)
      h_1[i] = (ll(h_1[i-1]) * base + s[i] - 'A' + 1) % mod,
      h_2[i] = h_2[i-1] * base + s[i] - 'A' + 1;
  }
  int size() {
    return s.size();
  }
  pair<int, ull> operator () (int l, int r) {
    if (l > r) return {0, 0};
    if (l == 0) return {h_1[r], h_2[r]};
    int res_1 = h_1[r] - ll(h_1[l - 1]) * pw_1[r - l + 1] % mod;
    if (res_1 < 0) res_1 += mod;
    return {res_1, h_2[r] - h_2[l - 1] * pw_2[r - l + 1]};
  }
  friend istream& operator >> (istream& is, hash_string& hs) {
    string str; is >> str; hs = hash_string(str); return is;
  }
   
};
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  pw_1[0] = pw_2[0] = 1;
  for (int i = 1; i <= N; ++i)
    pw_1[i] = ll(pw_1[i-1]) * base % mod,
    pw_2[i] = pw_2[i-1] * base;
  hash_string s, t;
  cin >> s >> t;
  int n = s.size();
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    if (s(i, n-1) == t(0, n-i-1)) {
      if (s(0, i-1) == t(n-i, n-1)) {
        res += n; continue;
      }
      // [0, ans] x [n-i+1, n-i+1 + ans]
      int lo = 0, hi = i-1, mid;
      while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (s(0, mid) == t(n-i, n-i+mid)) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      if (s(lo + 1, i-1) == t(n-i + lo + 1, n-1)) 
        res += 1;
    } else if (s(0, i-1) == t(n-i, n-1)) {
      // [i, i+ans] x [0, ans]
      int lo = 0, hi = n-i-1, mid;
      while (lo <= hi) {
        mid = (lo + hi) >> 1;
        if (s(i, i+mid) == t(0, mid)) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
      if (s(i + lo + 1, n-1) == t(lo + 1, n-i-1)) 
        res += 1;
    }
  }
  cout << res;
  return 0;
}


