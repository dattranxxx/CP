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
int mul(int a, int b, int c, int d) {
  ll res = 1;
  res = (res * a) % M;
  res = (res * b) % M;
  res = (res * c) % M;
  res = (res * d) % M;
  return res;
}
int a[N+1];
int n;
struct sparse_table {
  int log_2[N+1];
  pair<int, int> spt[N][20];
  int g[N][20];
  void build() {
    for (int i = 2; i <= n; ++i)
      log_2[i] = log_2[i / 2] + 1;
    for (int i = 0; i < n; ++i) 
      spt[i][0] = {a[i], i},
      g[i][0] = a[i];
    for (int j = 1; j <= log_2[n]; ++j)
      for (int i = 0; i + (1 << j) - 1 < n; ++i)
        spt[i][j] = max(spt[i][j-1], spt[i+(1<<(j-1))][j-1]),
        g[i][j] = __gcd(g[i][j-1], g[i+(1<<(j-1))][j-1]);
  }
  int mid(int l, int r) {
    int k = log_2[r - l + 1];
    return max(spt[l][k], spt[r-(1<<k)+1][k]).second;
  }
  int get(int l, int r) {
    int k = log_2[r - l + 1];
    return __gcd(g[l][k], g[r-(1<<k)+1][k]);
  }
} spt;
int nxt_l(int l, int m) {
  int x = spt.get(l, m);
  int lo = 0, hi = l, mid, ans = l;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (spt.get(mid, m) == x) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }
  return ans;
}
int nxt_r(int r, int m) {
  int x = spt.get(m, r);
  int lo = r, hi = n-1, mid, ans = r;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    if (spt.get(m, mid) == x) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}

int res = 0;
void call(int l, int r) {
  if (l > r) return;
  if (l == r) {
    add(res, ll(a[l]) * a[l] % M);
    return;
  }
  int m = spt.mid(l, r);
  vector<int> L, R; // [ ), [ )
  L.emplace_back(m + 1);
  for (int i = nxt_l(m, m); i > l; i = nxt_l(i - 1, m)) 
    L.emplace_back(i);
  L.emplace_back(l);
  R.emplace_back(m - 1);
  for (int i = nxt_r(m, m); i < r; i = nxt_r(i + 1, m)) 
    R.emplace_back(i);
  R.emplace_back(r);
  for (int i = 0; i < L.size() - 1; ++i) 
    for (int j = 1; j < R.size(); ++j) 
      add(res, mul(L[i] - L[i+1], R[j] - R[j-1], a[m], spt.get(L[i+1], R[j])));
  call(l, m-1);
  call(m+1, r);
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  spt.build();
  call(0, n-1);
  cout << res << '\n';
  return 0;
}

