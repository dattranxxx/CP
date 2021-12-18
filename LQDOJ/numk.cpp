/* 
 * Author :  shora
 */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e6;
int dis[N][2];
tuple<int, int, int> tra[N][2];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int k, M; 
  cin >> k >> M;
  vector<int> a(k);
  for (int& x : a) cin >> x;
  queue<pair<int, int>> q; 
  memset(dis, 0x3f, sizeof(dis));
  dis[0][0] = 0; q.push({0, 0});
  while (!q.empty()) {
    int u = q.front().first, pick = q.front().second; q.pop();
    if (u == 0 && pick) {
      string res;
      int d, nu, npick;
      while (pick) {
        tie(d, nu, npick) = tra[u][pick];
        res += char(d + '0');
        u = nu; pick = npick;
      }
      reverse(res.begin(), res.end());
      cout << res << '\n';
      return 0;
    }
    for (int d : a) if (dis[u][pick] + 1 < dis[(u * 10 + d) % M][pick | d > 0]) {
      dis[(u * 10 + d) % M][pick | d > 0] = dis[u][pick] + 1;
      tra[(u * 10 + d) % M][pick | d > 0] = {d, u, pick};
      q.push({(u * 10 + d) % M, pick | d > 0});
    } 
  }
  cout << -1;
  return 0;
}

