/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 100;
string res;
void dfs(int pos, int nrem_10, int nrem_11) {
  for (int d = 9; ~d; --d) {
    for (int orem_10 = 0; orem_10 <= 90; ++orem_10) {
      for (int orem_11 = 0; orem_11 <= 82; ++orem_11) {
        if (check(n, d, orem_11, nums[pos], orem_10)) {
          if (dfs(pos + 1, orem_10, orem_11)) {
            res += d + '0'; return 1;
          }
        }
      }
    }
  }
  return 0;
}
int main() {
  int t, n, s;
  cin >> t;
  while (t--) {
    cin >> s >> n; nums.clear();
    while (s) {
      nums.push_back(s % 10); s /= 10;
    }
    reverse(nums.begin(), nums.end());
    res = "";
    dfs();
    cout << res;
  }
  

  return 0;
}

