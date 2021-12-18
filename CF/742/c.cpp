/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
int n;
vector<int> nums;
int dp[11][2][2][2][2];
int call(int pos, int cur, int nxt, int z_1, int z_2) {
  if (pos == nums.size()) return !cur && !nxt && z_1 && z_2;
  if (dp[pos][cur][nxt][z_1][z_2] != -1) return dp[pos][cur][nxt][z_1][z_2];
  int res = 0;
  for (int x = 0; x <= 9; ++x)
    for (int y = 0; y <= 9; ++y)
      if ((x + y + cur) % 10 == nums[pos]) 
        res += call(pos + 1, nxt, (x + y + cur) / 10, z_1 | (x > 0), z_2 | (y > 0)); 
  return dp[pos][cur][nxt][z_1][z_2] = res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n; nums.clear();
    while (n) {
      nums.push_back(n % 10); n /= 10;
    }
    memset(dp, -1, sizeof(dp));
    cout << call(0, 0, 0, 0, 0) << '\n';
  }
  return 0;
}

