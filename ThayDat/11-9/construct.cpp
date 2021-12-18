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
struct segment_tree {
  int n, x, y, res, ai;
  struct node {
    int max, min, lazy;
    node(): mx(-oo), mn(oo), lz(0) {}
    node(int mx, int mn, int lz): max(mx), min(mn), lazy(lz) {}
  };
  vector<node> st;
  void update(int k, int l, int r) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      
    } 
  }
  void leo(int k, int l, int r) {
    // tim i <= y lon nhat ma min(x, i) >= ai
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
      if (st[k].min >= ai) {
        res = min(res, r); return;
      } 
    }
    int m = (l + r) >> 1;
    leo(k<<1, l, m);
    leo(k<<1|1, m+1, r);
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
      cin >> a[i];
    while (q--) {
      cin >> t >> l >> r; l--; r--;
      if (t == 1) {
        cin >> k;
        for (int i = l; i <= r; ++i) 
          a[i] += k;
      }

    }
  }
  return 0;
}

