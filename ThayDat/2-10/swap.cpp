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
void file() {
  const string FILE_NAME = "swap";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e5;
struct fenwick_tree {
  int n;
  vector<ll> bit;
  fenwick_tree(int n): n(n), bit(n + 1) {}
  void update(int i, int x) {
    for (; i <= n; i += i & -i)
      bit[i] += x;
  }
  ll get(int i) {
    ll res = 0;
    for (; i; i -= i & -i)
      res += bit[i];
    return res;
  }
};
int a[N+1];
int n, q;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> q;
  fenwick_tree bit(n);
  for (int i = 1; i <= n; ++i) 
    cin >> a[i], bit.update(i, a[i]);
  int k, l, r;
  while (q--) {
    cin >> k >> l >> r;
    if (k == 0) {
      bit.update(l, -a[l]);
      bit.update(r, -a[r]);
      swap(a[l], a[r]);
      bit.update(l, a[l]);
      bit.update(r, a[r]);
    } else {
      cout << bit.get(r) - bit.get(l - 1) << '\n';
    }
  }
  return 0;
}

