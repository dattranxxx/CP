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
  const string FILE_NAME = "grn";
  freopen((FILE_NAME + ".inp").c_str(), "r", stdin);
  freopen((FILE_NAME + ".out").c_str(), "w", stdout);
}
const int oo = 1e9;
int n;
namespace task_4 {
  const int N = 1e4;
  int a[N];
  unordered_map<int, bool> cnt;
  int check(int pos, int d) {
    for (int i = 1; i < n; ++i) 
      if (i != pos) cnt[a[i]] = 1;
    bool flag = 1;
    for (int i = 1; i < n; ++i)
      if (i != pos && cnt[a[i]]) {
        if (!cnt[a[i] + d]) {
          flag = 0; break;
        }
        cnt[a[i]] = cnt[a[i] + d] = 0;
      }
    cnt.clear(); 
    return flag;
  }
  void solve() {
    n <<= 1;
    for (int i = 0; i < n; ++i) 
      cin >> a[i];
    sort(a, a + n);
    int res = 0; cnt.reserve(n);
    for (int i = 1; i < n; ++i) 
      if (check(i, a[i] - a[0])) res++;
    cout << res;
  }
}
namespace task_5 {
  void solve() {
    for (int i = 0, x; i < n*2; ++i)
      cin >> x;
    int res = 0;
    for (int i = 1; i * i <= n; ++i)
      if (i * i == n) res += 1;
      else if (n % i == 0) res += 2;
    cout << res;
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0); cout.tie(0);
  file();
  cin >> n;
  if (n <= 1000) task_4::solve();
  else task_5::solve();
  return 0;
}

