#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
vector<int> nums;
bool p[136];
ll dp[16][136][136][2];
ll call(int pos, int sum_x, int sum_y, int r) {
  if (pos == nums.size()) 
    return r == 0 && p[sum_x] && p[sum_y];
  if (dp[pos][sum_x][sum_y][r] != -1)
    return dp[pos][sum_x][sum_y][r];
  ll res = 0;
  for (int x = 0; x <= 9; ++x)
    for (int y = 0; y <= 9; ++y) if ((x + 2*y + r) % 10 == nums[pos]) 
      res += call(pos + 1, sum_x + x, sum_y + y, (x + 2*y + r) / 10);
  return dp[pos][sum_x][sum_y][r] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  ll n;
  cin >> n;
  while (n) {
    nums.emplace_back(n % 10);
    n /= 10;
  }
  fill(begin(p), end(p), 1);
  p[0] = p[1] = 0;
  for (int i = 2; i * i <= 135; ++i)
    if (p[i]) for (int j = i * i; j <= 135; j += i) p[j] = 0;
  memset(dp, -1, sizeof(dp));
  cout << call(0, 0, 0, 0);
  return 0;
}

