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
const int N = 2e5;
vector<int> G[N];
int n;
ll res = 0;
struct V {
  int a, b;
  V(): a(0), b(0) {}
  bool operator < (const V& v) const {
    return ll(a) * v.b >= ll(v.a) * b;
  }
  friend ostream& operator << (ostream& os, const V& v) {
    return os << '[' << v.a << ", " << v.b << ']';
  }
};
vector<V> a;
void merge(V& u, const V& v) {
  res += ll(u.b) * v.a;
  u.a += v.a; u.b += v.b;
}
set<V> call(int u) {
  set<V> cur, nxt;
  for (int v : G[u]) {
    nxt = call(v);
    if (cur.size() < nxt.size()) 
      cur.swap(nxt);
    for (const V& x : nxt) cur.insert(x);
  }
  while (!cur.empty() && !(a[u] < *cur.begin())) {
    merge(a[u], *cur.begin()); 
    cur.erase(cur.begin());
  }
  cur.insert(a[u]);
  return cur;
}
// a[i] / b[i] >= a[j] / b[j] <> a[i] * b[j] >= a[j] * b[i]
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n; 
  for (int i = 0, p; i < n; ++i) {
    cin >> p; 
    if (p != -1) G[p].emplace_back(i);
  }
  a.resize(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i].a;
  for (int i = 0; i < n; ++i)
    cin >> a[i].b, res += ll(a[i].a) * a[i].b;
  set<V> s = call(0);
  ll t = 0;
  for (const V& v : s) {
    res += t * v.a; t += v.b;
  }
  cout << res;
  return 0;
}
