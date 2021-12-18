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
const int N = 2e5, M = 1e9 + 7;
void add(int& x, int y) {
  x += y; if (x >= M) x -= M;
}
void dif(int& x, int y) {
  x -= y; if (x < 0) x += M;
}
int mul(ll x, ll y) {
  return x * y % M;
}
struct S {
  int x, h, t;
  S(): x(0), h(0), t(0) {}
  bool operator < (const S& s) const {
    return x < s.x;
  }
} a[N];
int n;
struct sparse_table {
  int log_2[N + 1], spt[N][20];
  sparse_table() {}
  void build() {
    for (int i = 0; i < n; ++i)
      spt[i][0] = a[i].h;
    for (int j = 1; j <= log_2[n]; ++j)
      for (int i = 0; i + (1 << j) - 1 < n; ++i)
        spt[i][j] = max(spt[i][j-1], spt[i+(1<<(j-1))][j-1]);
  }
  int get(int l, int r) {
    int k = log_2[r - l + 1];
    return max(spt[l][k], spt[r-(1<<k)+1][k]);
  }
} spt;
int A[N], Z[N], k[N], last[N];
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  for (int i = 2; i <= N; ++i) 
    spt.log_2[i] = spt.log_2[i / 2] + 1;
  int T;
  cin >> T;
  while (T--) {
    cin >> n; vector<int> c; c.reserve(n);
    for (int i = 0; i < n; ++i)
      cin >> a[i].x >> a[i].h, c.emplace_back(a[i].h);
    sort(a, a + n);
    spt.build();
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (int i = 0; i < n; ++i)
      a[i].t = lower_bound(c.begin(), c.end(), a[i].h) - c.begin();
    /*
    A = (a-x1)^2 + (a-x2)^2 + .. + (a-xk)^2
    = ka^2 + Z(x^2) - 2a*Z(x)
    A' = ((a+h)-x1)^2 ... + ((a+h)-xk)^2 + h^2
    = k(a+h)^2 + Z(x^2) - 2(a+h)*Z(x) + h^2
    = ka^2 + Z(x^2) - 2a*Z(x) + kh^2 + 2kah - 2h*Z(x) + h^2
    = A + kh^2 + 2kah - 2h*Z(x) + h^2
    */
    int res = 0;
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; ++i) {
      if (last[a[i].t] == -1 || spt.get(last[a[i].t], i) > a[i].h) {
        A[a[i].t] = k[a[i].t] = Z[a[i].t] = 0; 
        last[a[i].t] = i; 
        continue;
      } 
      int h = a[i].x - a[last[a[i].t]].x;
      /*
      A[a[i].t] += k[a[i].t]*h*h + 2*k[a[i].t]*a[last[a[i].t]].x*h - 2*h*Z[a[i].t] + h*h;
      res += A[a[i].t]; k[a[i].t]++; Z[a[i].t] += a[last[a[i].t]].x; last[a[i].t] = i;
      */
      
      add(A[a[i].t], mul(mul(h, h), k[a[i].t]));
      add(A[a[i].t], mul(2, mul(k[a[i].t], mul(a[last[a[i].t]].x, h))));
      dif(A[a[i].t], mul(2, mul(h, Z[a[i].t])));
      add(A[a[i].t], mul(h, h));

      add(Z[a[i].t], a[last[a[i].t]].x);
      k[a[i].t]++; last[a[i].t] = i;

      add(res, A[a[i].t]); 
      
    } 
    cout << res << '\n';
  }
  return 0;
}

