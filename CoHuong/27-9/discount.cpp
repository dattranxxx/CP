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
void file() {
  const string FILE_NAME = "discount";
  freopen((FILE_NAME + ".in").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
using ll = long long;
const ll oo = 1e18;
const int N = 1e5;
struct segment_tree {
  int n, x; ll res, y;
  vector<ll> st;
  segment_tree(int n): n(n) { st.resize(n << 2, oo); }
  void update(int k, int l, int r) {
    if (l > x || r < x) return;
    if (l == r) {
      st[k] = y; return;
    }
    int m = (l + r) >> 1;
    update(k<<1, l, m);
    update(k<<1|1, m+1, r);
    st[k] = min(st[k<<1], st[k<<1|1]);
  }
  void get(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      res = min(res, st[k]); return;
    }
    int m = (l + r) >> 1;
    get(k<<1, l, m);
    get(k<<1|1, m+1, r);
  }
  void set(int i, ll v) {
    x = i; y = v; update(1, 0, n-1);
  }
  ll query(int l, int r) {
    x = l; y = r; res = oo;
    get(1, 0, n-1);
    return res;
  }
};
ll a[N+1];
ll dp[N+1], f[N+1];
int n, k;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  f[0] = a[0];
  for (int i = 1; i <= n; ++i)
    f[i] = f[i-1] + a[i];
  segment_tree st(n + 1);
  st.set(n, f[n] / 2);
  dp[n] = 0;
  for (int i = n-1; i >= 0; --i) {
    // [i+1, i+k+1]
    /*
    dp[i] = oo;
    for (int j = i + 1; j <= n && j - i <= k + 1; ++j) {
      int sum = (f[j] - a[j]) / 2;
      dp[i] = min(dp[i], sum + dp[j]);
    }
    dp[i] = dp[i] - f[i]/2 + a[i];
    */
    dp[i] = st.query(i+1, min(n, i+k+1)) - f[i]/2 + a[i];
    st.set(i, dp[i] + (f[i] - a[i]) / 2);
  }
  cout << dp[0] << '\n';
  return 0;
}

