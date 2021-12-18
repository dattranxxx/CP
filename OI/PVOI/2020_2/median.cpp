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
  const string FILE_NAME = "median";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
const int N = 2e3;
int a[N];
int n;
namespace task_1 {
  void solve() {
    vector<ll> c; c.reserve(1 << n);
    for (int b = 1; b < 1 << n; ++b) {
      ll sum = 0;
      for (int i = 0; i < n; ++i) 
        if (b & (1 << i)) sum += a[i];
      c.emplace_back(sum);
    }
    sort(c.begin(), c.end());
    cout << c[c.size() / 2];
  }
}
namespace task_2 {
  bitset<2000*2000/2> dp;
  void solve() {
    int sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    sum = (sum + 1) / 2;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) 
      dp |= dp << a[i];
    int res = 0;
    for (int i = sum; i; --i) if (dp[i]) {
      res = i; break;
    }
    cout << res;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  if (n <= 20) task_1::solve();
  else task_2::solve();
  return 0;
}

