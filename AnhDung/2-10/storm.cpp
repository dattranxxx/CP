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
const int N = 6e5, M = 1e9 + 7;
int a[N+1], f[N+1], sum_x[N+1][20], sum_n[N+1][20], xuoi[N+1][20], nguoc[N+1][20];
int n, q;
int mul(ll x, ll y) {
  return x * y % M;
}
int sum(int x, int y) {
  x += y; if (x >= M) x -= M; return x;
}
int dif(int x, int y) {
  x -= y; if (x < 0) x += M; return x;
}
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
int cost(int l, int r) {
  if (r - l <= 1) return 0;
  return dif(mul(r - l - 1, min(a[l], a[r])), dif(f[r-1], f[l]));
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
      cin >> a[i], f[i] = sum(f[i-1], a[i]); 
    stack<int> st;
    memset(xuoi, -1, sizeof(xuoi));
    memset(nguoc, -1, sizeof(nguoc));
    memset(sum_x, 0, sizeof(sum_x));
    memset(sum_n, 0, sizeof(sum_n));
    for (int i = 1; i <= n; ++i) {
      while (!st.empty() && a[st.top()] < a[i]) st.pop();
      nguoc[i][0] = st.empty() ? -1 : st.top();
      if (!st.empty()) 
        sum_n[i][0] = cost(st.top(), i);
      st.push(i);
    }
    st = stack<int>();
    for (int i = n; i; --i) {
      while (!st.empty() && a[st.top()] < a[i]) st.pop();
      xuoi[i][0] = st.empty() ? -1 : st.top();
      if (!st.empty()) 
        sum_x[i][0] = cost(i, st.top());
      st.push(i);
    }
    for (int j = 1; j <= 19; ++j)
      for (int i = 1; i <= n; ++i) {
        if (xuoi[i][j-1] != -1 && xuoi[xuoi[i][j-1]][j-1] != -1) 
          xuoi[i][j] = xuoi[xuoi[i][j-1]][j-1],
          sum_x[i][j] = sum(sum_x[i][j-1], sum_x[xuoi[i][j-1]][j-1]);
        if (nguoc[i][j-1] != -1 && nguoc[nguoc[i][j-1]][j-1] != -1) 
          nguoc[i][j] = nguoc[nguoc[i][j-1]][j-1],
          sum_n[i][j] = sum(sum_n[i][j-1], sum_n[nguoc[i][j-1]][j-1]);
      }
    int l, r, res = 0;
    while (q--) {
      cin >> l >> r; 
      for (int k = 19; ~k; --k) {
        if (xuoi[l][k] != -1 && xuoi[l][k] <= r) 
          add(res, sum_x[l][k]), l = xuoi[l][k];
        if (nguoc[r][k] != -1 && nguoc[r][k] >= l)
          add(res, sum_n[r][k]), r = nguoc[r][k];
      }
    }
    cout << res << '\n';
  }
  return 0;
}

