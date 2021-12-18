                 /*..... .
                 .';:;;;;'':.
                .:::::::::cl'
                .c;;o,.cc::::.
                ';l:.. ..;;;;.
                 .,::.'',:...
                  '.'cxdo;..d.
                  d..:olo.'dO.
                  kk. .. :kOO.
                 .k0k...'000d.
                  c00'.,00k:..
                  l00..xOk;..co'
                 .l00cdOO, ...oO;.
           .,;;. .:ld::do  .  .OOx'.
       ,cokcc,......;. ..      oOO00Oooc'
    .oOOOc..... .......      ..oK000OOOOOl.
   :OOOO:....    .'...      .lO0KK000OOOOOOo.
   ,OOO00;  ..   .           x0KK0000OOOOOOO:.
    'ck00k.  ...  ...... ... ':000OOOOOOOOOk;.
      :OOO0kdld:':O0:.,,,l'.':'OOOOOOo:l:;'.
       .;ooolOOOOOO000O00000OOOOOOx:..
             .''....;coolc,'',;.*/
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1e6;
int a[N];
int n, k;
ll S = 0, m;
namespace task_1 {
  unordered_map<ll, int> dp[20];
  int pw[20];
  int call(int i, ll mask, int cur, int used, ll sum) {
    if (i == k) 
      return sum == 0 ? n : -1;
    if (dp[i].count(mask))
      return dp[i][mask];
    ll nmask, nsum; int ni, ncur;
    for (int j = 0; j < n; ++j) {
      if (!(used >> j & 1) && sum + a[j] <= m) {
        ni = i, nmask = mask + pw[j]; ncur = cur ^ (1 << j), nsum = sum + a[j]; 
        if (nsum == m) {
          for (int u = 0; u < n; ++u) if (ncur >> u & 1)
            nmask += pw[u];
          ni++, nsum = 0, ncur = 0;
        }
        if (call(ni, nmask, ncur, used ^ (1 << j), nsum) != -1) 
          return dp[i][mask] = j;
      }
    }
    return dp[i][mask] = -1;
  }
  void solve() {
    // k goi moi goi co m keo
    // dp[i][mask] la dang nhat goi thu i va mask la tt hien tai (da dung, dang dung, chua dung)
    pw[0] = 1;
    for (int i = 1; i < n; ++i)
      pw[i] = pw[i-1] * 3;
    if (call(0, 0, 0, 0, 0) == -1) {
      cout << -1; return;
    }
    ll mask = 0, sum = 0;  
    int i = 0, cur = 0;
    vector<int> res(n);
    while (i < k) {
      int c = dp[i][mask];
      res[c] = i + 1;
      mask += pw[c];
      sum += a[c];
      cur ^= (1 << c);
      if (sum == m) {
        for (int j = 0; j < n; ++j) if (cur >> j & 1)
          mask += pw[j];
        sum = 0, cur = 0, i++;
      }
    }
    for (int x : res)
      cout << x << ' ';
  }
}
namespace task_2 {
  const int M = 3500;
  bitset<M> dp[101][M];
  void solve() {
    for (int i = n; i; --i) 
      swap(a[i], a[i-1]);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        dp[i][j] |= dp[i-1][j];
        dp[i][j] |= (dp[i-1][j] << a[i]);
        if (j >= a[i]) 
          dp[i][j] |= dp[i-1][j-a[i]];
      }
    }
    if (!dp[n][m][m]) {
      cout << -1; return;
    }
    int i = n+1, x = m, y = m;
    vector<int> res(n);
    while (i) {
      if (dp[i-1][x][y]) 
        res[i-1] = 3;
      else if (x >= a[i] && dp[i-1][x-a[i]][y]) 
        res[i-1] = 1, x -= a[i];
      else if (y >= a[i] && dp[i-1][x][y-a[i]])
        res[i-1] = 2, y -= a[i];
      i--;
    }
    for (int x : res)
      cout << x << ' ';
  }
}
namespace task_3 {
  int res[N];
  int dp[1 << 25];
  bool vis[1 << 25];
  int call(int mask, ll sum, ll cur) {
    if (sum == S) return 1;
    if (vis[mask]) return dp[mask];
    vis[mask] = 1;
    for (int i = 0; i < n; ++i) if (mask >> i & 1) {
      if (cur + a[i] <= m && call(mask ^ (1 << i), sum + a[i], cur + a[i] == m ? 0 : cur + a[i]) != -1) 
        return dp[mask] = i;
    }
    return dp[mask] = -1;
  }
  void solve() {
    int _n = n;
    while (n > 25) {
      // 2k pt cuoi
      for (int i = 0, c = 1; i < k; ++i)
        res[n-i-1] = res[n-2*k+i] = c, c++, S -= a[n-i-1], S -= a[n-2*k+i];
      n -= 2*k;
    }
    m = S / k;
    if (call((1 << n) - 1, 0, 0) == -1) {
      cout << -1; return;
    }
    int mask = (1 << n) - 1; 
    ll sum = 0;
    while (sum != S) {
      res[dp[mask]] = sum / m + 1;
      sum += a[dp[mask]];
      mask ^= 1 << dp[mask];
    }
    for (int i = 0; i < _n; ++i)
      cout << res[i] << ' ';
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> k; 
  for (int i = 0; i < n; ++i)
    cin >> a[i], S += a[i];
  if (S % k != 0) {
    cout << -1 << '\n'; return 0;
  }
  m = S / k;
  if (n <= 20) task_1::solve();
  else if (k == 3 && n <= 100) task_2::solve();
  else task_3::solve();
  return 0;
}

