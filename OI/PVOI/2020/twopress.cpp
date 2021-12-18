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
  const string FILE_NAME = "twopress";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 1e3;
ll a[N + 1];
int n, S, k; ll X;
int calc(ll x) {
  if (x == 0) return 0;
  if (x % k == 0) 
    return calc(x / k) + 1;
  return calc(x - 1) + 1;
}
struct fenwick_tree {
  int n;
  vector<int> bit;
  fenwick_tree(int n): n(n), bit(n + 1) {}
  void update(int i) {
    for (; i <= n; i += i & -i)
      bit[i] += 1;
  }
  int get(int i) {
    int res = 0;
    for (; i; i -= i & -i)
      res += bit[i];
    return res;
  }
};
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n >> S >> X;
  for (int i = 1; i <= n; ++i) {
    cin >> k;
    if (k == 1) a[i] = X;
    else a[i] = calc(X); // log(k)
  }
  fenwick_tree bit(S);
  bit.update(a[1]);
  int res = 0;
  for (int i = 2; i <= n-1; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ll sum = a[i] + a[j];
      if (S >= sum)
       res += bit.get(S - sum);
    }
    if (a[i] <= S)
      bit.update(a[i]);
  }
  cout << res;
  return 0;
}

