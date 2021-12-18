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
const int N = 5e4;
struct P {
  int x, y;
  P(int x, int y): x(x), y(y) {}
  bool operator < (const P& p) const {
    if (x == p.x) return y < p.y;
    return x < p.x;
  }
  friend ostream& operator << (ostream& os, const P& p) {
    return os << '[' << p.x << ", " << p.y << ']';
  }
  P operator - (const P& p) const {
    return P(x - p.x, y - p.y);
  }
  int cross(const P& p) const {
    return x * p.y - y * p.x;
  }
  int cross(const P& a, const P& b) const {
    return (a - *this).cross(b - *this);
  }
};
vector<P> a, b;
int n;
void solve() {
  // tao convex hull tu a va dem so diem b nam trong convex hull do
  sort(a.begin(), a.end());
  P p1 = a[0], p2 = a[n-1];
  vector<P> up, down;
  up.push_back(p1);
  down.push_back(p1);
  for (int i = 1; i < n; ++i) {
    if (i == n-1 || p1.cross(a[i], p2) < 0) {
      while (up.size() >= 2 && up[up.size() - 2].cross(up.back(), a[i]) >= 0)
        up.pop_back();
      up.push_back(a[i]);
    }
    if (i == n-1 || p1.cross(a[i], p2) > 0) {
      while (down.size() >= 2 && down[down.size() - 2].cross(down.back(), a[i]) <= 0)
        down.pop_back();
      down.push_back(a[i]);
    }
  }
  vector<P> cvh; cvh.reserve(up.size() + down.size() - 1);
  // -> cw cvh
  for (int i = 0; i < up.size(); ++i)
    cvh.push_back(up[i]);
  for (int i = down.size() - 2; i > 0; --i)
    cvh.push_back(down[i]);
  print(cvh);
  int res = 0;
  for (P& p : b) {

  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n; a.reserve(n); b.reserve(n);
  for (int i = 0, x, y; i < n; ++i) 
    cin >> x >> y, a.emplace_back(x, y);
  for (int i = 0, x, y; i < n; ++i) 
    cin >> x >> y, b.emplace_back(x, y);
  solve();
  swap(a, b);
  solve();
  return 0;
}

