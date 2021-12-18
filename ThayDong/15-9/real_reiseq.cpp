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
const int N = 20;
int n; ll t;
ll dp[N][N+2][N+2][N+2], a[N];
ll call(int pos, int mn, int second_mn, int mx) {
  if (pos == n) return 1;
  if (dp[pos][mn][second_mn][mx] != -1)
    return dp[pos][mn][second_mn][mx];
  dp[pos][mn][second_mn][mx] = 0;
  int n_mn, n_second_mn, n_mx;
  for (int x = 1; x <= n; ++x) {
    if (mn + second_mn > x && mx - mn < x) {
      n_mx = max(mx, x); 
      if (x < mn) n_mn = x, n_second_mn = mn;
      else if (x < second_mn) n_mn = mn, n_second_mn = x;
      else n_mn = mn, n_second_mn = second_mn;
      dp[pos][mn][second_mn][mx] += call(pos + 1, n_mn, n_second_mn, n_mx);
    }
  }
  return dp[pos][mn][second_mn][mx];
}
void leo(int pos, int mn, int second_mn, int mx, ll t) {
  if (pos == n) return;
  int n_mn, n_second_mn, n_mx;
  for (int x = 1; x <= n; ++x) {
    if (mn + second_mn > x && mx - mn < x) {
      n_mx = max(mx, x); 
      if (x < mn) n_mn = x, n_second_mn = mn;
      else if (x < second_mn) n_mn = mn, n_second_mn = x;
      else n_mn = mn, n_second_mn = second_mn;

      if (call(pos + 1, n_mn, n_second_mn, n_mx) >= t) {
        cout << x << ' ';
        leo(pos + 1, n_mn, n_second_mn, n_mx, t); 
        return;
      }
      t -= call(pos + 1, n_mn, n_second_mn, n_mx);
    }
  }
}
ll dfs_index(int pos, int mn, int second_mn, int mx) {
  if (pos == n) return 1;
  int n_mn, n_second_mn, n_mx;
  ll res = 0;
  for (int x = 1; x <= a[pos]; ++x) {
    if (mn + second_mn > x && mx - mn < x) {
      int n_mx = max(mx, x); 
      if (x < mn) n_mn = x, n_second_mn = mn;
      else if (x < second_mn) n_mn = mn, n_second_mn = x;
      else n_mn = mn, n_second_mn = second_mn;
      if (x == a[pos]) {
        return res + dfs_index(pos + 1, n_mn, n_second_mn, n_mx);
      } else res += call(pos + 1, n_mn, n_second_mn, n_mx);
    }
  }
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> t; 
  for (int i = 0; i < n; ++i) cin >> a[i];
  memset(dp, -1, sizeof(dp));
  cout << call(0, n+1, n+1, 0) << '\n';
  leo(0, n+1, n+1, 0, t);
  cout << '\n' << dfs_index(0, n+1, n+1, 0);
  return 0;
}

