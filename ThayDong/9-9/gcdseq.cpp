/*                 ..... .
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
             .''....;coolc,'',;.                */
#include <bits/stdc++.h>
#define print(_v) for (auto &_ : _v) {cerr << _ << ' ';} cerr << endl;
using namespace std;
using ll = long long;
const int oo = 1e9;
const int N = 2e5 + 2;
int log_2[N];
ll a[N], spt[N][19];
tuple<int, int, int> q[N];
int n, m;
ll __lcm(ll x, ll y) {
  return x / __gcd(x, y) * y;
}
void build() {
  for (int i = 2; i <= n; ++i) 
    log_2[i] = log_2[i / 2] + 1;
  for (int i = 0; i < n; ++i) spt[i][0] = a[i];
  for (int j = 1; j <= log_2[n]; ++j)
    for (int i = 0; i + (1 << j) - 1 < n; ++i)
      spt[i][j] = __gcd(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
}
ll get(int l, int r) {
  int k = log_2[r - l + 1];
  return __gcd(spt[l][k], spt[r - (1 << k) + 1][k]);
}
struct segment_tree {
  int n, x, y, i;
  ll c, res;
  vector<ll> st;
  segment_tree(int n): n(n) {
    st.resize(n<<2, 1);
  }
  void update(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      st[k] = __lcm(st[k], c);
      return;
    }
    int m = (l + r) >> 1;
    update(k<<1, l, m);
    update(k<<1|1, m+1, r);
  }
  void get(int k, int l, int r) {
    res = __lcm(res, st[k]);
    if (l == r) return;
    int m = (l + r) >> 1;
    if (i <= m) get(k<<1, l, m);
    else get(k<<1|1, m+1, r);
  }
  void add(int l, int r, ll v) {
    c = v; x = l; y = r; update(1, 0, n-1);
  }
  ll query(int pos) {
    i = pos; res = 1; get(1, 0, n-1); return res;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n >> m;
  segment_tree st(n);
  for (int i = 0, l, r, c; i < m; ++i) {
    cin >> l >> r >> c; l--; r--;
    st.add(l, r, c);
    q[i] = make_tuple(l, r, c);
  }
  for (int i = 0; i < n; ++i)
    a[i] = st.query(i);
  build();
  for (int i = 0, l, r, c; i < m; ++i) {
    tie(l, r, c) = q[i]; 
    if (get(l, r) != c) {
      cout << -1; return 0;
    }
  }
  for (int i = 0; i < n; ++i)
    cout << a[i] << ' ';
  return 0;
}

