#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
int dp[19][59049][2][2];
ll call(int pos, int mask, int smaller, int nozero, int used = 0, int using = 0) {
  ll res = 0;
  if (nozero) res += call(pos + 1, mask, 1, 0, used, using);
  else if (!(used >> pos & 1)) res += call(pos + 1, mask + pw[0], smaller, nozero, used ^ (1 << pos), using);
  else if (!( >> pos & 1)) res += call(pos + 1, mask + pw[0], smaller, nozero, used ^ (1 << pos), using);
  for (int i = 1; i <= max(nums[pos], smaller * 9), ++i) {
    
  }
} 
ll f(ll r) {
  nums.clear();
  while (r) {
    nums.emplace_back(r % 10);
    r /= 10;
  }
  reverse(nums.begin(), nums.end());
  return call(0, 0, 0, 0);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  ll L, R;
  cin >> L >> R;
  cout << f(R) - f(L - 1);
  return 0;
}

