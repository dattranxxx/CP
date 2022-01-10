#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
void file() {
  const string FILE_NAME = "ex";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const int oo = 1e9;
ll dp[19][59049][2];
int pw[10];
vector<int> nums;
ll call(int pos, int mask, int nozero = 0, int smaller = 0, int f = 0, int s = 0) {
  if (pos == nums.size())
    return 1;
  if (smaller && dp[pos][mask][nozero] != -1)
    return dp[pos][mask][nozero];
  ll res = 0;
  for (int d = 0; d <= max(smaller * 9, nums[pos]); ++d) {
    if (f >> d & 1) continue;
    if (d == 0 && !nozero) res += call(pos + 1, 0, 0, 1, 0, 0);
    else res += call(pos + 1, mask + pw[d], nozero | d > 0, smaller | d < nums[pos], s >> d & 1 ? f | (1 << d) : f, s | (1 << d));
  }
  if (smaller)
    dp[pos][mask][nozero] = res;
  return res;
}
ll f(ll r) {
  nums.clear();
  while (r) 
    nums.emplace_back(r % 10),
    r /= 10;
  reverse(nums.begin(), nums.end());
  memset(dp, -1, sizeof(dp));
  return call(0, 0);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  ll L, R;
  cin >> L >> R;
  pw[0] = 1;
  for (int i = 1; i <= 9; ++i)
    pw[i] = pw[i-1] * 3;
  cout << f(R) - f(L - 1);
  return 0;
}

