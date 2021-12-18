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
struct segment_tree {
  int n, x, y, z, res;
  vector<int> st;
  segment_tree(int n): n(n), st(n<<2) {}
  void update(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      st[k] += z; return;
    }
    int m = (l + r) >> 1;
    update(k<<1, l, m);
    update(k<<1|1, m+1, r);
  }
  void get(int k, int l, int r) {
    res += st[k];
    if (l == r) return;
    int m = (l + r) >> 1;
    if (x <= m) get(k<<1, l, m);
    else get(k<<1|1, m+1, r);
  }
  int query(int i) {
    x = i; res = 0; get(1, 0, n-1); return res;
  }
  void add(int l, int r, int val) {
    x = l; y = r; z = val; update(1, 0, n-1);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int q;
  cin >> q;
  segment_tree st(int(1e6));
  for (int l, r, x, y; q; q--) {
    cin >> l >> r; l--; r--;
    x = st.query(l), y = st.query(r);
    cout << x + y << '\n';
    st.add(l, l, -x); st.add(r, r, -y);
    st.add(l + 1, r - 1, 1);
  }
  return 0;
}

