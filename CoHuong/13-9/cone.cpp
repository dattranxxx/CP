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
  const string FILE_NAME = "cone";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e5;
int a[N], val[N], lis[N], lds[N];
int n;
struct fenwick_tree {
  int n;
  vector<int> bit;
  fenwick_tree(int n): n(n), bit(n + 1) {}
  void update(int i, int x) {
    for (; i <= n; i += i & -i) 
      bit[i] = max(bit[i], x);
  }
  int get(int i) {
    int res = 0;
    for (; i; i -= i & -i) 
      res = max(res, bit[i]);
    return res;
  }
};
int calc(int x) {
  int res = 0;
  while (x) {
    res += x % 10; x /= 10;
  }
  return res;
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i], c[i] = a[i];
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  for (int i = 0; i < n; ++i) {
    val[i] = calc(a[i]);
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
  }
  int m = c.size();
  fenwick_tree bit(m);
  for (int i = 0; i < n; ++i) {
    lis[i] = bit.get(a[i] - 1) + val[i];
    bit.update(a[i], lis[i]);
  }
  bit = fenwick_tree(m);
  for (int i = n-1; ~i; --i) {
    lds[i] = bit.get(a[i] - 1) + val[i];
    bit.update(a[i], lds[i]);
  }
  int res = -oo;
  for (int i = 0; i < n; ++i) 
    res = max(res, lis[i] + lds[i] - val[i]);
  cout << res;
  return 0;
}

