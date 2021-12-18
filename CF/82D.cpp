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
#include "bits/stdc++.h"
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 1000;
int a[N], dp[N+1][N];
pair<int, int> tr[N+2][N], di[N+2][N];
int n;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  int res = oo;
  memset(dp, 0x3f, sizeof(dp));
  int inf = dp[0][0];
  dp[1][0] = 0;
  pair<int, int> tra, did, zer = {1, 0};
  for (int i = 1; i < n; i += 2)
    for (int j = 0; j < i; ++j) if (dp[i][j] != inf) {
      if (i == n-1 && dp[i][j] + max(a[i], a[j]) < res) {
        res = dp[i][j] + max(a[i], a[j]);
        tra = {i, j};
        did = {i, j};
      }
      if (dp[i][j] + max(a[i], a[j]) < dp[i+2][i+1]) {
        dp[i+2][i+1] = dp[i][j] + max(a[i], a[j]);
        tr[i+2][i+1] = {i, j};
        di[i+2][i+1] = {i, j};
      }
      if (dp[i][j] + max(a[i+1], a[j]) < dp[i+2][i]) {
        dp[i+2][i] = dp[i][j] + max(a[i+1], a[j]);
        tr[i+2][i] = {i, j};
        di[i+2][i] = {i+1, j};
      }
      if (dp[i][j] + max(a[i], a[i+1]) < dp[i+2][j]) {
        dp[i+2][j] = dp[i][j] + max(a[i], a[i+1]);
        tr[i+2][j] = {i, j};
        di[i+2][j] = {i, i+1};
      }
    }
  if (n % 2 == 0) {
    printf("%d\n", res);
    stack<pair<int, int>> st;
    st.push(did);
    for (; tra != zer; tra = tr[tra.first][tra.second]) {
      st.push(di[tra.first][tra.second]); 
    }
    while (!st.empty()) {
      printf("%d %d\n", st.top().second + 1, st.top().first + 1); st.pop();
    } 
  } else {
    for (int i = 0; i < n; ++i) if (dp[n][i] != inf) {
      if (dp[n][i] + a[i] < res) {
        res = dp[n][i] + a[i];
        tra = {n, i};
        did = {-1, i};
      }
    }
    printf("%d\n", res);
    stack<pair<int, int>> st;
    st.push(did);
    for (; tra != zer; tra = tr[tra.first][tra.second]) {
      st.push(di[tra.first][tra.second]); 
    }
    while (!st.empty()) {
      if (st.top().first == -1) printf("%d", st.top().second + 1);
      else printf("%d %d\n", st.top().second + 1, st.top().first + 1); 
      st.pop();
    }
  } 
  return 0;
}

