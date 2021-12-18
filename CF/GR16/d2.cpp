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
int query_prefix(int r, int row, int x, vector<S>& a) {
  int res = 0;
  for (int i = 0; i < r; ++r) {
    int i_row = a[i].ni / m;
    if (i_row == row && a[i].oi < x) res++;
  }
  return res;
}
int n, m;
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m; 
    vector<S> a; a.reserve(n*m);
    for (int i = 0, x; i < n*m; ++i) {
      cin >> x; a.emplace_back(x, i); 
    } 
    sort(a.begin(), a.end());
    for (int i = 0; i < n*m; ++i) 
      a[i].ni = i; // ko dung voi xuong dong

    for (int i = 0; i < n*m;) {
      int cnt = 1, j = i, old_row = i / m;
      while (j+1 < n*m && a[j+1].x == a[i].x) {
        j++, cnt++; 
      }
      int new_row = j / m;
      if (new_row != old_row) {
        sort(a.begin() + i, a.begin() + j, [&](S& u, S& v) {
          return u.oi < v.oi;
        }); 
        int k = 0;
        // middle
        for (int row = old_row + 1; row <= new_row - 1; ++row)
          for (int col = 0; col < m; ++col) a[k].ni = row*m+col, k++;
        // prefix of new_row and suffix of old_row
        int pt1 = m-1, pt2 = 0;
        int old_col = i-old_row*m, new_col = j-new_row*m;
        cerr << old_col << ' ' << new_col << '\n';
        // count number of a[p].oi < a[k].oi : p < k
        // and number of a[q].oi > a[k].oi : p > k
        // the smaller get added
        while (pt1 >= old_col && pt2 <= new_col) {
          int x = mt.query_prefix(i - 1, a[k].oi), y = mt.query_suffix(j + 1, a[k].oi);
          if (x < y)
        }
      }
      i = j + 1;
    }

    sort(a.begin(), a.end(), [&](S& u, S& v) {
      return u.oi < v.oi;
    });
    
    ll res = 0;
    vector<fenwick_tree> bit(n, fenwick_tree(m));
    for (int i = 0; i < n*m; ++i) {
      int row = a[i].ni / m, col = a[i].ni - row*m; 
      res += bit[row].get(col);
      bit[row].update(col + 1, 1);
      printf("add %d %d\n", row, col);
    }
    cout << res << '\n';
  }
  return 0;
}

