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
const int N = 300;
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
struct S {
  int x, oi, ni;
  S(int x, int oi): x(x), oi(oi), ni(-1) {}
  bool operator < (const S& s) const {
    if (x == s.x) return oi > s.oi;
    return x < s.x;
  }
  friend ostream& operator << (ostream& os, const S& s) {
    return os << s.x << ' ' << s.oi << ' ' << s.ni;
  }
};
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    vector<S> a; a.reserve(m);
    for (int i = 0, x; i < m; ++i) {
      cin >> x; a.emplace_back(x, i);
    } 
    sort(a.begin(), a.end());
    for (int i = 0; i < m; ++i) 
      a[i].ni = i;
    sort(a.begin(), a.end(), [&](S& u, S& v) {
      return u.oi < v.oi;
    });
    
    ll res = 0;
    fenwick_tree bit(m);
    for (int i = 0; i < m; ++i) {
      res += bit.get(a[i].ni);
      bit.update(a[i].ni + 1, 1);
    }
    cout << res << '\n';
  }
  return 0;
}

