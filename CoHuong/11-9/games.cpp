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
void file() {
  const string FILE_NAME = "games";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
struct segment_tree {
  int n, x, y, res, v;
  vector<int> st, lz;
  segment_tree(int n): n(n), st(n << 2), lz(n << 2) {}
  void push(int k) {
    lz[k<<1] = max(lz[k<<1], lz[k]);
    lz[k<<1|1] = max(lz[k<<1|1], lz[k]);
    st[k<<1] = max(st[k<<1], lz[k]);
    st[k<<1|1] = max(st[k<<1|1], lz[k]);
  }
  void update(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      st[k] = max(st[k], v); 
      lz[k] = max(lz[k], v);
      return;
    }
    push(k);
    int m = (l + r) >> 1;
    update(k<<1, l, m);
    update(k<<1|1, m+1, r);
    st[k] = max(st[k<<1], st[k<<1|1]);
  }
  void get(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      res = max(res, st[k]); return;
    }
    push(k);
    int m = (l + r) >> 1;
    get(k<<1, l, m);
    get(k<<1|1, m+1, r);
  }
  int query(int l, int r) {
    x = l; y = r; res = -oo;
    get(1, 0, n-1);
    return res;
  }
  void change(int l, int r, int val) {
    x = l; y = r; v = val;
    update(1, 0, n-1);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  int n, q;
  cin >> n >> q; 
  segment_tree st(n);
  for (int i = 0, x; i < n; ++i) 
    cin >> x, st.change(i, i, x);
  for (int len, l, r, res; q--;) {
    cin >> l >> len; l--;
    r = min(n - 1, l + len - 1);
    res = st.query(l, r) + 1;
    cout << res << '\n';
    st.change(l, r, res);
  }
  return 0;
}

