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
const int N = 1e5;
struct Q {
  int l, r, i, val;
  Q(int l, int r, int i, int val): l(l), r(r), i(i), val(val) {}
  bool operator < (const Q& q) const {
    if (r == q.r) return val > q.val;
    return r < q.r; 
  }
  friend ostream& operator << (ostream& os, const Q& q) {
    return os << q.l << ' ' << q.r << ' ' << q.i << ' ' << q.val;
  }
};
int a[N+1];
int n;
struct sparse_table {
  const static int K = 19;
  int log_2[N+1], mx[N+1][K], mn[N+1][K], gcd[N][K];
  void build() {
    for (int i = 2; i <= n; ++i) 
      log_2[i] = log_2[i / 2] + 1;
    for (int i = 1; i <= n; ++i) { 
      mx[i][0] = mn[i][0] = a[i];
      if (i+1 <= n) 
        gcd[i][0] = a[i] - a[i + 1];
    }
    for (int j = 1; j <= log_2[n]; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
        mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]),
        mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
        if (i + (1 << j) <= n)
          gcd[i][j] = __gcd(gcd[i][j-1], gcd[i+(1<<(j-1))][j-1]);
      }
  }
  tuple<int, int, int> get(int l, int r) {
    int k = log_2[r - l + 1];
    int k_gcd = log_2[r - l];
    return make_tuple(
        max(mx[l][k], mx[r-(1<<k)+1][k]), 
        min(mn[l][k], mn[r-(1<<k)+1][k]), 
        __gcd(gcd[l][k_gcd], gcd[r-(1<<k_gcd)][k_gcd]));
  } 
} spt;
struct fenwick_tree {
  int n;
  vector<int> bit; 
  fenwick_tree(int n): n(n), bit(n + 1) {}
  void update(int i, int x) {
    for (; i <= n; i += i & -i) 
      bit[i] += x;
  }
  int get(int i) {
    int res = 0;
    for (; i; i -= i & -i)
      res += bit[i];
    return res;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int k;
  cin >> n >> k;
  vector<Q> qu;
  qu.reserve(k);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    qu.emplace_back(i, i, -1, a[i]);
  }
  for (int i = 0, l, r; i < k; ++i) {
    cin >> l >> r;
    qu.emplace_back(l, r, i, 0);
  } 
  sort(qu.begin(), qu.end());

  spt.build();
  fenwick_tree bit(n);
  unordered_map<int, int> last;
  vector<bool> res(k);
  int mx, mn, gc;
  for (int i = 0; i < qu.size(); ++i) {
    if (qu[i].i == -1) {
      if (last[qu[i].val]) 
        bit.update(last[qu[i].val], -1);
      last[qu[i].val] = qu[i].l;
      bit.update(qu[i].l, 1);
    } else {
      bool distict = (bit.get(qu[i].r) - bit.get(qu[i].l-1)) == (qu[i].r - qu[i].l + 1);
      if (!distict) continue;
      tie(mx, mn, gc) = spt.get(qu[i].l, qu[i].r);
      if ((mx - mn) % (qu[i].r - qu[i].l)) continue;
      int d = (mx - mn) / (qu[i].r - qu[i].l);
      if (gc % d == 0)
        res[qu[i].i] = 1;
    }
  }
  for (bool x : res)
    cout << (x ? "YES\n" : "NO\n");
  return 0;
}

